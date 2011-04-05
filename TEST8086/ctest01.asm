; ctest01.asm
; problem - program outputs more than 20 numbers!
; sum = 46306

        org  1000
        setreg ip = main
        setreg sp = 5fff
CR      equ  %10
LF      equ  %13
   ;
   ;main()
   ;
main:   push  bp
        mov   bp,sp
        sub   sp,40
        push  si
        push  di
   ;
   ;{
   ;  int a[20];
   ;  int i, sum;
   ;
   ;  for (i=0; i<20; i++)
   ;
        xor   si,si
        jmp    @1@98
@1@50:  mov   bx,si
   ;
   ;    a[i] = i * 200;
   ;
        shl   bx,1
        lea   ax,[bp-40]
        add   bx,ax
        mov   ax,si
        mov   dx,200
        mul   dx
        mov   word ptr [bx],ax
        inc   si
@1@98:  cmp   si,20
        jl     @1@50
   ;
   ;
   ;  for (i=19; i ; i--) {
   ;
         mov  si,19
         jmp   @1@194

   ;
   ;    a[i] = a[i] / 7;
   ;
@1@146:  mov  bx,si
         shl  bx,1
         lea  ax,[bp-40]
         add  bx,ax
         mov  ax,word ptr [bx]
         mov  bx,7
         xor  dx,dx      ; cwd would be better
         div  bx
         mov  bx,si
         shl  bx,1
         lea  dx,[bp-40]
         add  bx,dx
         mov  word ptr [bx],ax
   ;
   ;    a[i] = a[i] + a[i] % 30;
   ;
         mov  bx,si
         shl  bx,1
         lea  ax,[bp-40]
         add  bx,ax
         mov  ax,word ptr [bx]
         mov  bx,si
         shl  bx,1
         lea  dx,[bp-40]
         add  bx,dx
         push ax
         mov  ax,word ptr [bx]
         mov  bx,30
         xor  dx,dx     ; cwd would be better
         div  bx
         pop  ax
         add  ax,dx
         mov  bx,si
         shl  bx,1
         lea  dx,[bp-40]
         add  bx,dx
         mov  word ptr [bx],ax
         dec  si
@1@194:  or   si,si
         jne   @1@146
   ;
   ;  }
   ;
   ;  sum = 0;
   ;
         xor  di,di
   ;
   ;  for (i=0; i<20; i++) {
   ;
         xor  si,si
         jmp   @1@290

   ;
   ;    sum += a[i];
   ;
@1@242:  mov  bx,si
         shl  bx,1
         lea  ax,[bp-40]
         add  bx,ax
         add  di,word ptr [bx]
   ;
   ;    printf("%d\n",a[i]);
   ;
         mov  bx,si
         shl  bx,1
         lea  ax,[bp-40]
         add  bx,ax
         push word ptr [bx]
         pop  ax
         lea  dx,outnum
         int  13           ; convert integer to string
         int  10           ; output string
         inc  si
@1@290:  cmp  si,20
         jl    @1@242
   ;
   ;  }
   ;  printf("the sum is %d\n",sum);
   ;
         mov  ax,di
         lea  dx,outsum
         int  13
         lea  dx,summsg
         int  10
   ;
   ;  printf("the sum from the function is %d\n", func(a,20));
   ;
         mov  ax,20
         push ax
         lea  ax,[bp-40]
         push ax
         call _func
         pop  cx
         pop  cx
         lea  dx,outfunc
         int  13
         lea  dx,funcmsg
         int  10
   ;
   ;}
   ;
         pop  di
         pop  si
         mov  sp,bp
         pop  bp
         hlt
   ;
   ; int func(int a[], int size)
   ;
_func:   push bp
         mov  bp,sp
         push si
         push di
   ;
   ;{
   ;  int i, sum;
   ;
   ;  sum = 0;
   ;
         xor  di,di
   ;
   ;  for (i=0; i<size; i++)
   ;
         xor  si,si
         jmp   @2@98

   ;
   ;    sum += a[i];
   ;
@2@50:   mov  ax,si
         shl  ax,1
         mov  bx,word ptr [bp+4]
         add  bx,ax
         add  di,word ptr [bx]
         inc  si
@2@98:   cmp  si,word ptr [bp+6]
         jl    @2@50
   ;
   ;  return sum;
   ;
         mov  ax,di
         jmp   @2@146

   ;
   ;}
   ;
@2@146:  pop  di
         pop  si
         pop  bp
         ret

outnum:  db "       ",CR,LF,"$"
summsg:  db "the sum is "
outsum:  db "       ",CR,LF,"$"
funcmsg: db "the sum from the function is "
outfunc: db "       ",CR,LF,"$"