# asm2.c 
## Traduction de code assembleur
La fonction suivante a été écrite en assembleur. Traduisez la en une version équivalente en C. Votre fonction doit nécessairement avoir comme nom __mp__.

``` 
mp:
    subl $8, %esp
    movl 16(%esp), %edx
    movl 12(%esp), %ecx
    addl %ecx, %ecx
    cmpl %edx,%ecx
    jle mp1
    movl %edx, %eax
    addl $8, %esp
    ret
mp1: movl %ecx, %eax
    addl $8, %esp
    ret 
```
