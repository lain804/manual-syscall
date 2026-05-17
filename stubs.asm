.data

syscallIndex DWORD 0

.code

PUBLIC SetupSyscall
SetupSyscall PROC
	mov syscallIndex, ecx
	ret
SetupSyscall ENDP

PUBLIC SyscallStub
SyscallStub PROC
	mov eax, syscallIndex
	mov r10, rcx
	syscall
	ret
SyscallStub ENDP

PUBLIC CleanupSyscall
CleanupSyscall PROC
	mov syscallIndex, 0
	ret
CleanupSyscall ENDP

END