        .data 
consta: .float 5.5
constb: .float 2.0
constc: .float 1.0
        .text
        j main

ekthetis: 
        and $t0, $t0, $zero
        mtc1 $t0 , $f4 
        cvt.s.w $f4, $f4 

        la $t0 , constc
        lwc1 $f6, 0($t0)

        addiu $t0,$zero,1
        mtc1 $t0 , $f0
        cvt.s.w $f0 , $f0 
        
        and $t0,$zero,$t0
        mtc1 $t0 , $f8
        cvt.s.w $f8 , $f8 

loop: 
       c.lt.s $f14 ,$f8 
       bc1t endloop
        mul.s $f0,$f0,$f12
        add.s $f8,$f8,$f6
        j loop

endloop: 
        jr $ra 


main: 
       la $t0 , consta
       lwc1 $f12, 0($t0)
       la $t0 , constb
       lwc1 $f14, 0($t0)
       jal ekthetis
       mov.s $f20,$f0
