#include <windows.h>
#include <winternl.h>
#include <stdio.h>
#include "stubs.hpp"

// https://j00ru.vexillium.org/syscalls/nt/64/
#define NtQueryInformationProcessSyscallIdx 0x19
// this kernel routine had the 0x19 syscall index since windows 10 1507
// cannot take it for granted in production though, always resolve syscall numbers during runtime, this is only a simple poc

int main() {
	SIZE_T portNumber = 0;

	{
		PrepareSyscall(NtQueryInformationProcessSyscallIdx);
		NTSTATUS ok = SyscallStub((HANDLE)-1LL, ProcessDebugPort, &portNumber, sizeof(portNumber), NULL);

		if (!NT_SUCCESS(ok)) {
			printf("Manual Syscall failed with code: 0x%X\n", ok);
		}
	}
	
	printf("Debugger Detected: %s\n", portNumber != 0 ? "true" : "false");
	(void)getchar();
}
