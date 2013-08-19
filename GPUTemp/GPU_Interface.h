#pragma once
#include <iostream>

class GPU_Interface
{
public:
	virtual ~GPU_Interface() {}
	virtual std::string getFullName() = 0;
	virtual int getCurrentTemp() = 0;
};