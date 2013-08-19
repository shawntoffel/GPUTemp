#pragma once
#include "nvapi.h"
#include "GPU_Interface.h"

class NvidiaGPU : public GPU_Interface
{
public:
	NvidiaGPU();
	~NvidiaGPU();
	virtual std::string getFullName();
	virtual int getCurrentTemp();
private:
	NvU32 cnt;
	NvPhysicalGpuHandle phys;
	bool status_OK(const NvAPI_Status& status);
};