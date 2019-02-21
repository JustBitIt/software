.model flat,c
.code

my_add proc
	push ebp
	mov ebp,esp

	mov eax,[ebp+8]
	mov ecx,[ebp+12]
	mov edx,[ebp+16]

	add eax,ecx
	add eax,edx

	pop ebp

	ret
my_add endp
end