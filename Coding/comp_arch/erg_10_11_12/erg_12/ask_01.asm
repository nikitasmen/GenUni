     and $t0, $zero, $t0 # i <- 0
     and $t1, $zero, $t1 # s <- 0
Loop: 
    slti $t2, $t0, 5 # αν i<5 =>$t2 <- 1, αλλιώς $t2 <- 0
    beq $t2, $zero, Endloop # αν $t2=0 τότε άλμα στην Endloop
    add $t1, $t1, $t0 # s <- s + i
    addi $t0, $t0, 1 # i <- i + 1
    j Loop
Endloop:
