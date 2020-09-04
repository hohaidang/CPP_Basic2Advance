#include "stdafx.h"

#include "Fixture.h"

using namespace EmbeddedCUnitTest;

namespace EmbeddedC {

int GetTime()
{
	return TestFixture::_oscillator->GetTime();
}

int WriteGpio(int line, int value)
{
	return TestFixture::_gpio->WriteGpio(line, value);
}

int ReadGpio(int line, int *value)
{
	return TestFixture::_gpio->ReadGpio(line, value);
}

}
