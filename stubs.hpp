#include <windows.h>

extern "C" NTSTATUS SyscallStub(...);
extern "C" void PrepareSyscall(int idx);
extern "C" void SyscallCleanup();