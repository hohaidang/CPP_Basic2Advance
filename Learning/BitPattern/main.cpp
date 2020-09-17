#include <cstdint>
#include <stdexcept>
#include <type_traits>
#include <iostream>

class BitPattern {
private:
	/*expected result after masking*/
	std::uint64_t expected_{};

	/*mask is set of bits I care*/
	std::uint64_t mask_{ 0xFFFFFFFFFFFFFFFF };
public:
	template<std::size_t Size>
	explicit constexpr  BitPattern(const char(&input)[Size]) {
		/*Size luon duoc + 1 boi vi co character '\0' o cuoi moi string*/
		std::uint64_t cur_bit = 1U << (Size - 2); /*vi tri bit, most significant bit, vd size = 2 -> cur_bit = 1*/
		for (const char &val : input) {
			if (val == 0) {
				return;
			}
			if (val == '1') {
				expected_ |= cur_bit;
			} else if(val == '0') {
			}
			else if (val == 'x' || val == 'X') {
				mask_ &= ~cur_bit;
			}
			else {
				throw std::logic_error("Unknown characters");
			}
			cur_bit >>= 1;
		}
	}

	template<typename ValueType>
	constexpr friend bool operator==(const ValueType value,
		const BitPattern& pattern) {
		return (value & pattern.mask_) == pattern.expected_;
	}
};

int main(int argc, const char* []) {
	//static_assert(0b1101010u == BitPattern("11XXX10"));

	/*Optimize tao struct*/
	// constexpr BitPattern pattern("101XXX111000101XX0101"); // tinh truoc cai expected o compiler time
    // return (static_cast<std::uint32_t>(argc) == pattern); // chi can so sanh vs cai expected o compiler time la xong

	return (static_cast<std::uint32_t>(argc) == BitPattern("101XXX111000101XX0101"));

	if (2 == BitPattern("001")) {
		std::cout << "True" << '\n';
	}
	else {
		std::cout << "False" << '\n';
	}
	
}
