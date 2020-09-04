#include "stdafx.h"

#include "Fixture.h"

namespace EmbeddedCUnitTest {

// Services
std::unique_ptr<OscillatorService> TestFixture::_oscillator;
std::unique_ptr<GpioService> TestFixture::_gpio;

// Modules mocks
std::unique_ptr<BaseModuleMock> TestFixture::_modulesMocks;

}
