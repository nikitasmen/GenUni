   
# Άσκηση ύψωσης ενός πραγματικού αριθμού
# σε οποιαδήποτε ακέραια δύναμη (μη αναδρομικά).
    .data
msgBase: .asciiz "Give base : "
msgExpo: .asciiz "Give exponent : "
msgRes: .asciiz "The result is "
    .text
    j main
power: 
    addi $t0,$zero,1 # αλλιώς $t0 <- 1
    mtc1 $t0,$f4 # μεταφορά στο $f4
    cvt.s.w $f4,$f4 # και μετατροπή σε 1.0 (α.α.)
    mov.s $f0,$f4 # Mεταφορά στο $f0
    addu $t2, $zero, $a0 # $t2 <- $a0
    slt $t0, $a0, $zero # Αν $a0 < 0 => $t0 <- 1, αλλιώς $t0 <- 0
    beq $t0, $zero, endAbs # Αν $t0 = 0 => endAbs
    nor $t2, $t2,$zero # $t2 <- συμπλήρωμα ως προς 1 του $t2
    addiu $t2, $t2, 1 # $t2 <- $t2 + 1 (συμπλήρωμα ως προς 2)
endAbs: 
    addi $t1, $zero, 0 # $t1 <- 0 (i<-0)
forLoop: 
    slt $t0, $t1, $t2 # Αν i < abs(e) => $t0<-1, αλλιώς $t0<-0
    beq $t0, $zero, endFor # Αν $t0 = 0 => άλμα στην endFor
    mul.s $f0,$f0,$f12 # $f0 <- $f0 x $f12
    addi $t1,$t1,1 # $t1 <- $t1 + 1
    j forLoop # άλμα στην forLoop
endFor: 
    slt $t0, $a0,$zero # Αν e < 0 => $t0 <- 1, αλλιώς $t0 <- 0
    beq $t0, $zero, end # Αν $t0 = 0 => end
    div.s $f0, $f4, $f0 # $f0 <- 1 / $f0
    end: jr $ra # Επιστροφή
main: 
    addi $v0,$zero,4 # (print string)
    la $a0,msgBase
    syscall
    addi $v0,$zero,6 # (read float)
    syscall
    mov.s $f12,$f0 # Μεταφορά του πρώτου ορίσματος
    addi $v0,$zero,4 # (print string)
    la $a0,msgExpo
    syscall
    addi $v0,$zero,5 # (read integer)
    syscall
    add $a0,$zero,$v0 # Μεταφορά του δεύτερου ορίσματος
    jal power # Κλήση της power
    addi $v0,$zero,4 # (print string)
    la $a0,msgRes
    syscall
    addi $v0,$zero,2 # (print float)
    mov.s $f12,$f0
    syscall # Εμφάνιση αποτελέσματος