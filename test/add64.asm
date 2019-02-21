.code

my_add64 proc
	add rcx,rdx
	add r8,r9

	mov rax,[rsp+40]
	add rax,[rsp+48]

	add rcx,r8
	add rax,rcx

	ret
my_add64 endp

end
