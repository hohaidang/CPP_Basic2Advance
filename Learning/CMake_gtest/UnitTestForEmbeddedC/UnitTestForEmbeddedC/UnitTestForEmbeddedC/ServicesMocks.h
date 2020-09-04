#pragma once

namespace EmbeddedCUnitTest {

class OscillatorService
{
public:
	virtual ~OscillatorService() {} // IMPORTANT: This is needed by std::unique_ptr

	MOCK_METHOD0(GetTime, int());
};

class GpioService
{
public:
	virtual ~GpioService() {} // IMPORTANT: This is needed by std::unique_ptr

	MOCK_METHOD2(ReadGpio, int(int, int*));
	MOCK_METHOD2(WriteGpio, int(int, int));
};

}
