#pragma once

#include <Windows.h>
#include <cstdint>

extern "C" NTSTATUS SyscallStub(...);
extern "C" void SetupSyscall(uint32_t idx);
extern "C" void CleanupSyscall();
