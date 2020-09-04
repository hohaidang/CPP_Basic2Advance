#pragma once

#include "ServicesMocks.h"
#include "ModuleMock.h"

namespace EmbeddedCUnitTest {

class TestFixture : public ::testing::Test
{
public:
	TestFixture(BaseModuleMock *mocks)
	{
		_oscillator.reset(new ::testing::NiceMock<OscillatorService>());
		_gpio.reset(new ::testing::NiceMock<GpioService>());
		_modulesMocks.reset(mocks);
	}

	~TestFixture()
	{
		_oscillator.reset();
		_gpio.reset();
		_modulesMocks.reset();
	}

	template<typename T>
	static T& GetMock()
	{
		auto ptr = dynamic_cast<T*>(_modulesMocks.get());
		if (ptr == nullptr)
		{
			auto errMsg = "The test does not provide mock of \"" + std::string(typeid(T).name()) + "\"";
			throw std::exception(errMsg.c_str());
		}
		return *ptr;
	}

	// Services
	static std::unique_ptr<OscillatorService> _oscillator;
	static std::unique_ptr<GpioService> _gpio;

	// Modules mocks
	static std::unique_ptr<BaseModuleMock> _modulesMocks;
};

}
