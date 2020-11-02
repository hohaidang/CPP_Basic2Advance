// build c++20
#include <type_traits>

template <typename Float>
auto go(const Float value1,
        const Float value2) requires std::is_floating_point_v<Float> {
  return value1 + value2;
}

int main() { go(1.1, 2.3); }