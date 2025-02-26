    .data
Array1: .word 11,12,13,14,15,16,17,18,19,20
Array2: .word 0,0,0,0,0,0,0,0,0,0   # Κάνει αρχικοποίηση, είναι προτιμότερο το .space 40
Array3: .space 40
Array4: .word 10
    .text
    j Main
    PrIntArr: addu $t0, $zero, $a0      # Αρχή Πίνακα
    and $t1, $zero, $t1                 # Αρχικοποίηση μετρητή
    Loop: slt $t2, $t1, $a1             # Αν $t1 < $a1 => $t2<-1
    beq $t2, $zero, EndLoop             # αλλιώς $t2<-0
    addiu $v0, $zero, 1                 # Υπηρεσία print int
    sll $t2,$t1,2                       # Επί τέσσερα
    addu $t3, $t0, $t2                  # Η διεύθυνση του επόμενου στοιχείου
    lw $a0, 0($t3)                      # Τοποθέτηση στο $a0 του επόμενου
    syscall
    addi $t1, $t1, 1                    # Αύξηση του μετρητή κατά ένα
    addiu $v0, $zero, 11                # Υπηρεσία print char
    addiu $a0, $zero, 32                # Τοποθέτηση στο $a0 του κενού χαρακτήρα
    syscall
    j Loop
    EndLoop: addiu $v0, $zero, 11       # Υπηρεσία print char
    addiu $a0, $zero, 10                # Τοποθέτηση στο $a0 χαρακτήρα νέας γραμμής
    syscall
    jr $ra                              # Επιστροφή από την διαδικασία PrIntArr

    RandArr: addu $t0, $zero, $a0       # Αρχή πίνακα
    addu $t4, $zero, $a1                # Πλήθος στοιχείων
    and $t1, $zero, $t1                 # Αρχικοποίηση μετρητή
    Loop2: slt $t2, $t1, $t4            # Αν $t1 < $a1 => $t2<-1
    beq $t2, $zero,EndLoop2             # αλλιώς $t2<-0
    addiu $v0, $zero, 42                # Κωδικός υπηρεσίας 42 (random int range)
    addiu $a1, $zero, 50                # Για τιμές στο [0, 50)
    syscall
    sll $t2,$t1,2                       # Επί τέσσερα
    addu $t3, $t0, $t2                  # Η διεύθυνση του επόμενου στοιχείου
    addiu $a0, $a0,30                   # Ψευδοτυχαία τιμή στο [30, 80)
    sw $a0, 0($t3)                      # Τοποθέτηση του $a0 στον πίνακα
    syscall
    addi $t1, $t1, 1                    # Αύξηση του μετρητή κατά ένα
    j Loop2                     
    EndLoop2: jr $ra                    # Επιστροφή από την διαδικασία RandArr

    SumArr: and $t0, $zero, $t0         # Αρχικοποίηση μετρητή
    Loop3: slt $t1, $t0, $a3            # Αν $t1 < $a3 => $t1<-1
    beq $t1, $zero,EndLoop3             # αλλιώς $t1<-0
    sll $t1,$t0,2                       # Επί τέσσερα
    addu $t2, $a1, $t1                  # Διεύθυνση στοιχείου Array1[i]
    lw $t3, 0($t2)                      # Στο $t3 το στοιχείο Array1[i]
    addu $t2, $a2, $t1                  # Διεύθυνση στοιχείου Array2[i]
    lw $t4, 0($t2)                      # Στο $t4 το στοιχείο Array2[i]
    add $t5, $t3, $t4                   # Στο $t5 το άθροισμα Array1[i] + Array2[i]
    addu $t2, $a0, $t1                  # Διεύθυνση στοιχείου Array3[i]
    sw $t5, 0($t2)                      # Αποθήκευση του αθροίσματος στη θέση Array3[i]
    addi $t0, $t0, 1                    # Αύξηση του μετρητή κατά ένα
    j Loop3
    EndLoop3: jr $ra                    # Επιστροφή από την διαδικασία SumArr

    Main: la $a0, Array1                # Πρώτο όρισμα
    addiu $a1, $zero, 10                # Δεύτερο όρισμα
    jal PrIntArr                        # Εμφάνιση πίνακα 1
    la $a0, Array2                      # Πρώτο όρισμα
    addiu $a1, $zero, 10                # Δεύτερο όρισμα
    jal RandArr                         # Γέμισμα πίνακα 2  

    la $a0, Array2                      # Πρώτο όρισμα
    addiu $a1, $zero, 10                # Δεύτερο όρισμα
    jal PrIntArr                        # Εμφάνιση πίνακα 2
    la $a0, Array3                      # Πρώτο όρισμα
    la $a1, Array1                      # Δεύτερο όρισμα
    la $a2, Array2                      # Τρίτο όρισμα
    addiu $a3, $zero, 10                # Τέταρτο όρισμα
    jal SumArr                          # Πρόσθεση πινάκων (Array3<=Array1+Array2)
    la $a0, Array3                      # Πρώτο όρισμα
    addiu $a1, $zero, 10                # Δεύτερο όρισμα
    jal PrIntArr                        # Εμφάνιση πίνακα 3