.data

syscallIndex DWORD 0

.code

PUBLIC SetSyscallIndex
SetSyscallIndex PROC
	mov syscallIndex, ecx
	ret
SetSyscallIndex ENDP

PUBLIC ExecuteSyscallWithArgs
ExecuteSyscallWithArgs PROC
	mov eax, syscallIndex
	mov r10, rcx
	syscall
	ret
ExecuteSyscallWithArgs ENDP

PUBLIC ResetSyscallIndex
ResetSyscallIndex PROC
	mov syscallIndex, 0
	ret
ResetSyscallIndex ENDP

END