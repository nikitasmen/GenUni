# Άσκηση ύψωσης ενός πραγματικού αριθμού
# σε οποιαδήποτε ακέραια δύναμη (αναδρομικά).
    .data
msgBase: .asciiz "Give base : "
msgExpo: .asciiz "Give exponent : "
msgRes: .asciiz "The result is "
    .text
    j main
power: 
    addi $sp,$sp,-8 # Δημιουργία χώρου στην στοίβα για δύο λέξεις
    sw $ra,4($sp) # Τοποθέτηση στην στοίβα του $ra
    sw $a0,0($sp) # Τοποθέτηση στην στοίβα του $ra
    bne $a0,$zero,L1 # Αν ο εκθέτης διάφορος του 0 => L1
    addiu $t0,$zero,1 # Φόρτωση στο $t0 <- 1,
    mtc1 $t0,$f0 # μεταφορά στο $f0
    cvt.s.w $f0,$f0 # και μετατροπή σε 1.0 (α.α.)
    j Exit # Άλμα στην Exit
L1: 
    slt $t0,$zero,$a0 # Αν εκθέτης < 0 => $t0<-1, αλλιώς $t0<-0
    beq $t0,$zero,L2 # Αν $t0 = 0 => άλμα στο L2
    addi $a0,$a0,-1 # $a0 <- $a0 - 1
    jal power # Κλήση της power
    mul.s $f0,$f0,$f12 # $f0 <- $f0 x $f12
    j Exit # Άλμα στην Exit
L2: 
    addi $a0,$a0,1 # $a0 <- $a0 + 1
    jal power # Κλήση της power
    div.s $f0,$f0,$f12 # $f0 <- $f0 / $f12
Exit: 
    lw $ra,4($sp) # Αποκατάσταση του $ra
    lw $a0,0($sp) # Αποκατάσταση του $a0
    addi $sp,$sp,8 # Επαναφορά του δείκτη στοίβας
    jr $ra # Επιστροφή
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