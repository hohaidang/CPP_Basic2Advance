#include "../common/Utils.hpp"
#include <ap_int.h>
#include <iostream>

#define EnumValues(...)                                                        \
  enum RawEnum { __VA_ARGS__, N, Invalid = N };                                \
  struct Enum {                                                                \
  private:                                                                     \
    RawEnum value;                                                             \
                                                                               \
  public:                                                                      \
    Enum() = delete;                                                           \
    inline constexpr Enum(RawEnum value) : value(value) {}                     \
    inline constexpr operator RawEnum() const { return value; }                \
  };                                                                           \
  typedef ap_uint<Log<2, N + 1>::value> UInt

struct FilterCodes {
  EnumValues(Success, InvalidInstrument, InvalidPrice, InvalidQuantity,
             InvalidSide, InvalidCapacity, InternalError);
};

template <typename FilterCodes> struct Filter : FilterCodes {
  using UInt = typename FilterCodes::UInt;
  constexpr static int N = FilterCodes::N;
  using T = ap_int<N - (FilterCodes::Success + 1)>;
  inline Filter() : m_filter(0){};
  // moi bi se tuong ung voi 1 loai enum, vd 0100 nghia la InvalidQuantity, 0000 nghia la Success
  inline Filter(typename FilterCodes::RawEnum value)
      : m_filter((value == FilterCodes::Success)
                     ? T(0)
                     : (T(1) << (value - (Filter::Success + 1)))) {}

public:
  T m_filter; // m_filter nay la bien chua enum
};

int main() {
  std::cout << FilterCodes::Success << std::endl;
  //  Filter<FilterCodes> dang;
  std::cout << Filter<FilterCodes>::Success << std::endl;
  Filter<FilterCodes> dang(FilterCodes::InvalidQuantity);
  std::cout << "dang.m_filter = " << dang.m_filter << std::endl;
  // van chua biet tai sao lai can typedef ::Filter<FilterCodes> Filter; trong RaptorBasic
  return 0;
}
