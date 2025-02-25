    .data 
PI: .double     3.1415926535897932
const2: .double  2.0
        .text 
        j main 

emvadon: 
        ldc1 $f0, PI 
        ldc1 $f2 , const2
    
        mul.d $f2,$f2,$f0 
        mul.d $f2,$f2,$f12

        mul.d $f0, $f0,$f12 
        mul.d $f0,$f0,$f12 
    
        jr $ra 

main: 
        addiu $t0 , $zero , 10 
        mtc1 $t0 , $f22 
        cvt.d.w $f22,$f22
        mov.d $f12 , $f22 
        jal emvadon 
        mov.d $f20 , $f0
        