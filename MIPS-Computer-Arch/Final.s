# Convert C++ to MIPS
# Address of unsigned short val is in $s3. 
#Preserve the behavior of original C++ Code.

# for (unsigned int i=0; i<val; i++)
#       val--;

lhu $t1, 0($s3)         # Load 2 byte val to $t1
add $t0, $zero, $zero     #init counter i=0

loop:
    beq $t1, $t0, end   # base case i==val, end loop 
    addiu $t1, $t1, -1  # val --
    addiu $t0, $t0, 1   # i++
    j loop              # jump back to loop header
end:
    sh $t1, 0($s3)

#lhu unsigned short, sh for 2 bytes (unsigned short)
#lw, sw - word size, 4 bytes
#li load immediate (pseudo)
#bgeu $t0, $t1, label (pseudo)
#sltu unsigned compare

#2
#A MULT function takes values from $a0 and $a1 and are multiplied, returning the product to $v0. Write a function POW that takes values from $a0 and $a1 and returns $v0 the value: a0^a1, using MULT function for multiplication. Parameters for POW are guaranteed to be small (no overflow) positive integers. 

POW:
    beq $a1, $zero, re_1       # if exponent is 0, return 1
    addiu $t0, $zero, 1     # initialize counter to 1
    beq $a1, $t0, re_a0 # if exp =1, return a0

    addi $sp, $sp, -12       #decrement stack ptr to alloc stack space
    sw $ra, 0($sp)          # save return addr on stack
    sw $t0, 4($sp)          # t0
    sw $t1, 8($sp)          # t1

    # Initialize counter and exponent
    addu $t0, $zero, $zero  #counter = 0
    addu $t1, $a1, $zero    #t1=a1 exponent
    addu $v0, $a0, $zero    #v0 = a0 for a0 * a0 (initial product)
    addu $a1, $a0, $zero    #a1 =  a0 for a0 * a0 (first MULT call)

loop:
    beq $t0, $t1, end       #branch when counter = a0^a1
    jal MULT
    addu $a1, $v0, $zero    # a1=v0 so a0 * v0 for next MULT call
    addiu $t0, $t0, 1       # counter++
    j loop                  # jump back to loop header

re_1:
    addiu $v0, $zero, 1     # return 1 if exponent is 0
    jr $ra

re_a0:
    addu $v0, $a0, $zero    # return a0 if exponent is 1
    jr $ra

end:
    lw $ra, 0($sp)          #restore return address from stack
    lw $t0, 4($sp)          #restore t0 from stack
    lw $t1, 8($sp)          #restore t1 from stack
    addi $sp, $sp, 12       #increment stack pointer to deallocate space
    jr $ra


#Comment: Does not preserve one or more needed temporary registers other than $ra before function call OR does not preserve saved registers before use. And - using uninitialized register value. 

