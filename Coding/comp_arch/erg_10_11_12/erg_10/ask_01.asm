        j main 

celsius: 
        addiu $t0,$zero,32 
        mtc1 $t0 , $f4 
        cvt.s.w $f4 , $f4 
        sub.s $f0 ,$f1,$f4

        addiu $t0 , $zero ,5 
        mtc1 $t0,$f4 
        cvt.s.w $f4 , $f4 

        addiu $t0 , $zero ,9 
        mtc1 $t0,$f8 
        cvt.s.w $f8 , $f8 
        
        div.s $f6,$f4,$f8
        mul.s $f0 , $f0 , $f6 
        jr $ra 


main:   addiu $t0 , $zero , 140 
        mtc1 $t0 , $f22 
        cvt.s.w $f22,$f22
        mov.s $f12 , $f22 
        jal celsius
        mov.s $f20 , $f0