    data
Orio: .float 1.0e-6
Msg1: .asciiz "Give real number : "
Msg2: .asciiz "The function exp() is : "
    .text
    j Main

Exp: 
    and $t0,$zero,$zero # Αρχικοποίηση μετρητή i <- 0 (μηδένιση)
    mtc1 $zero,$f0 # Μεταφορά του μηδενός στο $f0
    cvt.s.w $f0, $f0 # Μετατροπή σε α.α. (Y <-0.0)
    addi $t1, $zero, 1 # Φόρτωση $t1 <- 1
    mtc1 $t1, $f8 # Μεταφορά της μονάδας στο $f8
    cvt.s.w $f8, $f8 # Μετατροπή σε α.α. (d <-1.0) f8 <- 1.0
    mov.s $f10,$f8 # Μεταφορά στο $f10 (p <-1.0) f10 <- 1.0
    mov.s $f16,$f8 # Μεταφορά στο $f16 (oros <-1.0) f16 <- 1.0
    la $t1, Orio # Φόρτωση της διεύθυνσης της ετικέτας Orio στον $t1
    lwc1 $f4, 0($t1) # Φόρτωση του ορίου στον καταχωριστή $f4 ($f4 <- 1.0e-6)

Loop:
    abs.s $f18, $f16 # Μεταφορά της απόλυτης τιμής του όρου στον $f18
    c.le.s $f4,$f18 # Αν 1.0e-6 <= |oros| τότε flag0 <- True, αλλιώς flag0 <- False
    bc1f End # αν flag0 = False τότε άλμα στην ετικέτα End
    add.s $f0,$f0,$f16 # y <- y + oros
    addi $t0,$t0,1 # i <- i + 1
    mul.s $f8,$f8,$f12 # d <- d * x
    mtc1 $t0,$f18 # Μεταφορά της τιμής του μετρητή i στον $f18
    cvt.s.w $f18,$f18 # Μετατροπή σε απλή ακρίβεια { $f18 <- (float)i }
    mul.s $f10,$f10,$f18 # p <- p * i
    div.s $f16, $f8,$f10 # oros <- d / p
    j Loop # Άλμα στην ετικέτα Loop

End:
    jr $ra # Επιστροφή στην Main

Main: 
    addi $v0,$zero,4 # Υπηρεσία 4 (print string)
    la $a0,Msg1 # Τοποθέτηση στον $a0 της διεύθυνσης της συμβολοσειράς msg1
    syscall # Εμφανίζει το μήνυμα 1
    addi $v0,$zero,6 # Υπηρεσία 6 (read float)
    syscall # Διαβάζει έναν αρθμό (float) και τον τοποθετεί στο $f0
    mov.s $f12,$f0 # Τοποθετεί το όρισμα για την exp στον $f12
    jal Exp # Κλήση συνάρτησης
    addi $v0,$zero,4 # Υπηρεσία 4 (print string)
    la $a0,Msg2 # Τοποθέτηση στον $a0 της διεύθυνσης της συμβολοσειράς msg2
    syscall # Εμφανίζει το μήνυμα 2
    addi $v0,$zero,2 # Υπηρεσία 2 (print float)
    mov.s $f12,$f0 # Τοποθετεί την απάντηση exp (από τον $f0) στον $f12
    syscall # Εμφανίζει το αποτέλεσμα στην οθόνη