#pragma once

namespace EmbeddedCUnitTest {

// Base class to be stored in fixture class
class BaseModuleMock
{
public:
	virtual ~BaseModuleMock()
	{

	}
};

// Tell HOOK whether it should stop or continue function execution
class ReturnAfterHookCallSwitch
{
public:
	ReturnAfterHookCallSwitch()
	{
		_returnAfterHookCall = true;
	}

	bool ShouldReturnAfterHookCall()
	{
		return _returnAfterHookCall;
	}

	bool _returnAfterHookCall;
};


// This class should be used as base class for all module mock classes.
// 1. The BaseModuleMock inheritance must be virtual to allow storing mocks in fixture class.
// 2. The ReturnAfterHookCallSwitch inheritance must be non virtual to allow this switch
// behave differently in every mock class.
class ModuleMock : public virtual BaseModuleMock, public ReturnAfterHookCallSwitch
{

};

}
