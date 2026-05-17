#include <windows.h>
#include <winternl.h>
#include <stdio.h>
#include "stubs.hpp"
#include <cstdint>

// this kernel routine had the 0x19 syscall index since windows 10 1507
// cannot take it for granted in production though, always resolve syscall numbers during runtime, this is only a simple poc

// https://j00ru.vexillium.org/syscalls/nt/64/
#define NtQueryInformationProcessSyscallIndex 0x19

// lol
#define GetCurrentProcess() ((HANDLE)-1LL)

int main() {
	uint64_t portNumber = 0;

	{
		SetupSyscall(NtQueryInformationProcessSyscallIndex);

		NTSTATUS ok = SyscallStub(GetCurrentProcess(), ProcessDebugPort, &portNumber, sizeof(portNumber), NULL);

		CleanupSyscall();

		if (!NT_SUCCESS(ok)) {
			printf("Manual Syscall failed with code: 0x%X\n", ok);
		}
	}
	
	printf("Debugger Detected: %s\n", portNumber != 0 ? "true" : "false");
	(void)getchar();
}
