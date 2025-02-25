	.data 
msg1: .asciiz "Enter radius"
msg2: .asciiz "The circumference is: "
msg3: .asciiz "The area is: " 
pi: 	  .float 3.14
	.text
	j main 
	
 circumference:
 	la $t0 , pi 
 	lwc1 $f4 , 0($t0) #pi
 	
 	mtc1 $a0 , $f6 #radius
 	cvt.s.w $f6 , $f6
 	
 	addi $t0 ,$zero , 2 
 	mtc1 $t0 , $f8
 	cvt.s.w $f8 ,$f8 #2 
 	
 	mul.s $f4,$f4 , $f6
 	mul.s $f0,$f4 , $f8 #$f0 <- 2*pi*r
 	jr $ra 
 	
 area:
 	la $t0,pi 
 	lwc1 $f4 , 0($t0) #pi
 	
 	mtc1 $a0 , $f6 #radius
 	cvt.s.w $f6 , $f6
 	
 	mul.s $f6,$f6 ,$f6 
 	mul.s $f2 , $f4,$f6 
 	jr $ra 
	
main: 
    # Print msg1
   addiu $v0, $zero,4
    la $a0,msg1
    syscall

    # Read integer
    addi $v0,$zero, 5
    syscall
    
    add $s0 , $zero , $v0 
    add $a0 , $zero , $s0 
    jal  circumference
    addi $v0 , $zero , 4 
    la $a0 , msg2 
    syscall  			#print msg2 
    addi $v0 , $zero , 2 
    mov.s $f12 , $f0 
    syscall  			#print circumference
    add $a0 , $zero , $s0 
    jal area 
     addi $v0 , $zero , 4 
    la $a0 , msg3 
    syscall  			#print msg2 
    addi $v0 , $zero , 2 
    mov.s $f12 , $f2 
    syscall  			#print circumference
    
    
    