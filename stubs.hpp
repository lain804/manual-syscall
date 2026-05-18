#pragma once

#include <Windows.h>
#include <cstdint>

extern "C" NTSTATUS ExecuteSyscallWithArgs(...);
extern "C" void SetSyscallIndex(uint32_t idx);
extern "C" void ResetSyscallIndex();
