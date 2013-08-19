#include "NvidiaGPU.h"

NvidiaGPU::NvidiaGPU() {
	// initialize NVAPI library
	NvAPI_Initialize();

	// get array of physical gpu handles
    NvAPI_EnumPhysicalGPUs(&phys, &cnt);
}

// check status is NVAPI_OK
bool NvidiaGPU::status_OK(const NvAPI_Status& status) {
	return (status == NVAPI_OK);
}

// get full name, returns empty in error
std::string NvidiaGPU::getFullName() {
	NvAPI_ShortString name = {};
	NvAPI_GPU_GetFullName(phys, name);
	return name;
}

// get current temperature, returns -1 in error
int NvidiaGPU::getCurrentTemp() {
	NV_GPU_THERMAL_SETTINGS thermalSettings;

	// NVAPI Version Definition. NVAPI maintains a per-structure specific version.
	thermalSettings.version = NV_GPU_THERMAL_SETTINGS_VER;

	// initialize current temperature to -1
	int currentTemp = -1;

	// get current temperature at sensor index 0
	if (status_OK(NvAPI_GPU_GetThermalSettings(phys, 0, &thermalSettings))) {
		currentTemp = thermalSettings.sensor[0].currentTemp;
	}

	return currentTemp;
}

NvidiaGPU::~NvidiaGPU() {
	// Unload NVAPI library. 
	// !! This method is NOT thread safe
	NvAPI_Unload();
}