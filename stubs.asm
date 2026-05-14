.data

syscallIndex DWORD 0

.code

PUBLIC PrepareSyscall
PrepareSyscall PROC
	mov syscallIndex, ecx
	ret
PrepareSyscall ENDP

PUBLIC SyscallStub
SyscallStub PROC
	mov eax, syscallIndex
	mov r10, rcx
	syscall
	ret
SyscallStub ENDP

END