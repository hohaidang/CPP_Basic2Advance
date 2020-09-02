#pragma once
#include <memory>
using namespace std;

class widget {
	class impl;
	unique_ptr<impl> pimpl;
public:
	void draw(); // public API that will be forwarded to the implementation
	widget(int); // defined in the implementation file
	~widget(); // defined in the implementation file, where impl is a complete type
	widget(widget &&) = default;
	widget(const widget &) = delete;
	widget& operator=(widget &&);// defined in the implementation file
	widget& operator=(const widget &) = delete;
};