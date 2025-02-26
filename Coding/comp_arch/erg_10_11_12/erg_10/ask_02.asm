        .data 
PI: .double     3.1415926535897932
        .text 
        j main 

emvadon: 
        ldc1 $f0, PI 
        mul.d $f0, $f0,$f12 
        mul.d $f0,$f0,$f12 
        jr $ra 

main: 
        addiu $t0 , $zero , 10 
        mtc1 $t0 , $f22 
        cvt.d.w $f22,$f22
        mov.s $f12 , $f22 
        jal emvadon 
        mov.s $f20 , $f0