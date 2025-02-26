        .data

consta: .float 5.5
constb: .float 2.0
result: .float 0.0
        
        .text
        j main
    
power:
    mov.s $f2, $f12
    mov.s $f3, $f14
    
    c.eq.s $f3, $f31, return_one
    
    c.eq.s $f3, 1.0, return_base
    
    div.s $f2, $f2, $f12  # divide base by itself
    sub.s $f3, $f3, 1.0  # decrement exponent
    jal power             # recursive call
    mul.s $f12, $f12, $f2  # multiply result by base
    mov.s $f0,$f12
    
    jr $ra
    
return_one:
    li.s $f0, 1.0
    jr $ra
    
return_base:
    jr $ra

main:
    lwc1 $f12, consta
    lwc1 $f14, constb    
    jal power
    mov.s $f20, $f0
