#include <stdint.h>
#include <vector>
#include <iostream>
//#define optimize

uint8_t glob_data = 0;

#ifdef optimize
struct gpio_struct {
public:
	constexpr gpio_struct(uint8_t pin_number, uint8_t irq_priority) : pin_number_(pin_number), irq_priority_(irq_priority) {};
	constexpr uint8_t get_irq_num() const {
		return (pin_number_ < 5) ? pin_number_ + 6
			: (pin_number_ < 10) ? 26
			: (pin_number_ < 16) ? 40
			: 0;
	};

	constexpr uint8_t get_shift_amount() const { 
		return ((get_irq_num() % 4) * 8) + (8 - 4);
	}

	constexpr uint32_t get_nvic() const {
		return irq_priority_ << get_shift_amount();
	}
private:
	uint8_t pin_number_;
	uint8_t irq_priority_;
};

class gpio_handler {
public:
	// gpio_handler(struct gpio_struct gpio) : gpio_(gpio) {};
	template<uint8_t irq_num>
	constexpr void gpio_init() {
		glob_data = irq_num;
	}
private:

};
#else
class gpio_handler {
public:
	uint8_t get_irq_num() const {
		return (pin_number_ < 5) ? pin_number_ + 6
			: (pin_number_ < 10) ? 26
			: (pin_number_ < 16) ? 40
			: 0;
	};

	uint8_t get_shift_amount() const {
		return ((get_irq_num() % 4) * 8) + (8 - 4);
	}

	uint32_t get_nvic() const {
		return irq_priority_ << get_shift_amount();
	}

	void gpio_init(uint8_t pin_number, uint8_t irq_priority) {
		pin_number_ = pin_number;
		irq_priority_ = irq_priority;
		glob_data = get_nvic();
	}

	uint8_t pin_number_;
	uint8_t irq_priority_;
};
#endif



int main() {
#ifdef optimize
	constexpr gpio_struct my_struct(30, 15);
	gpio_handler gpio;
	gpio.gpio_init<my_struct.get_nvic()>();
#else
	gpio_handler gpio;
	gpio.gpio_init(30, 15);
#endif

	return 0;
}