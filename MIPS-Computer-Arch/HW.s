#Write a MIPS function COUNT_BITS that takes a value from $a0 and returns in $v0 number of set digits in $a0. Again, "set digit" means digit that equals to 1.In your functionon, please DON'T use s-registers. You can still use t-registers and $zero register.

COUNT_BITS:
    # Initialize registers
    add $v0, $zero, $zero    # v0 = 0, stores final count of set bits
    add $t0, $zero, $zero    # t0 = 0, counter for set bits
    addi $t1, $zero, 1       # t1 = 1, mask for checking bits
    addi $t2, $zero, 32      # t2 = 32, loop counter for 32 bits

loop:
    # Check if current bit in a0 is set
    and $t3, $a0, $t1        # t3 = a0 AND t1 (mask), isolates current bit
    beq $t3, $zero, skip_inc # if t3 = 0, bit is not set, skip increment
    addi $t0, $t0, 1         # increment t0 if bit is set (t3 != 0)

skip_inc:
    sll $t1, $t1, 1          # shift mask left by 1 for next bit
    addi $t2, $t2, -1        # decrement loop counter
    bne $t2, $zero, loop     # if t2 != 0, continue looping

    # Return result
    add $v0, $t0, $zero      # move t0 (bit count) to v0
    jr $ra                   # return to caller


#HW 6
#Write in MIPS the implementa�on of the following pseudocode:
# func�on gcd(a, b)
#   while b ≠ 0
#   t := b
#   b := a mod b
#   a := t
# return a
#Your implementa�on should take parameter a from $a2 and parameter b from $a3. It returns the result to register $v1. Both a and b are unsigned 4-byte integers. Now, someone wrote a func�on MOD for you. The func�on MOD takes a and b from the registers $a0 and $a1 respec�vely and returns the value (a mod b) in the register $v1. Keep in mind, a-registers and v-registers behave like t-registers: they aren't preserve across func�on call. In other words, prepare that a�er the func�on call all those registers can change.
gcd:
 addi $sp, $sp, -16 #stack pointer to make space for 16 bytes on the stack
 sw $a2, 0($sp) # a2 to stack (saving original a on the stack in case needed a�er
other func�on calls)
 sw $a3, 4($sp) # a3 to stack (original b)
 sw $t0, 8($sp) # t0 to stack (original t)
 sw $ra, 12($sp) # ra to stack (original ra)
loop:
 beq $a3, $zero, end_loop # Base case: b == 0, jump to end_loop; if not, con�nue loop
 add $t0, $a3, $zero # t = b, store a3 (b) in t0 (t)
 #save registers to stack before MOD in case modified in MOD
 addi $sp, $sp, -8 #stack pointer to allocate 12 bytes of space on stack
 sw $a2, 0($sp) #a2 to stack (save a2 register on stack for ‘loop stack frame’,
different from a2 in ‘gcd stack frame‘)
 sw $a3, 4($sp) #a3 to stack (loop stack frame b)
 sw $t0, 8($sp) #updated t value in t0 to stack (loop stack frame t)
 add $a0, $a2, $zero #store a into register a0 (Mod a param) before calling MOD
 add $a1, $a3, $zero #store b into register a1 (Mod b param) before calling MOD
 jal MOD #call MOD
 lw $a2, 0($sp) #load a2 in case modified in MOD (not really needed because
will be overwriten anyway)
 lw $a3, 4($sp) #load a3 in case modified in MOD (not needed but just in case)
 lw $t0, 8($sp) #load t0 from stack (needed)
 addi $sp, $sp, 12 #stack pointer to deallocate 12 bytes of space
 add $a3, $v1, $zero # Put MOD result into b ($a3) for b = a mod b
 add $a2, $t0, $zero # a2 = a = t
 add $v1, $a2, $zero #put a into v1 to return a
 j loop
end_loop:
 add $v1, $a2, $zero #put a into v1 to return a
 #load a2, a3, v0, v1, t0 from the stack
 lw $a2, 0($sp) #load original a2 from gcd
 lw $a3, 4($sp) #load original a3 from gcd
 lw $t0, 8($sp) #load original t0 from gcd
 lw $ra, 12($sp) #load original ra from gcd
 addi $sp, $sp, 16 #adjust stack pointer for 16 bytes
 jr $ra # return to the callin



 #HW
 #Assignment: Finding lightest package
.data
packages:
    .space 12            # Space for 3 Package structures (each with 12 bytes)
    # Fill in the package data (id, weight, address) here

.text
main:
    # Load the base address of the packages array into $s2 (as provided)
    la $s2, packages

    # Initialize the lightest weight to a large value
    li $s0, 4294967295   # Set to the maximum possible 32-bit unsigned value

    # Loop counter
    li $t0, 0

loop:
    # Calculate the address of the current package (packages[$t0])
    mul $t1, $t0, 12    # Each Package is 12 bytes, so multiply index by 12
    add $t1, $t1, $s2  # Add the base address to get the address of the current package

    # Load the weight of the current package into $t2 (offset +2)
    lw $t2, 2($t1)

    # Compare the weight with the lightest weight found so far
    blt $t2, $s0, update_lightest

    # Increment the loop counter
    addi $t0, $t0, 1

    # Check if we've processed all 3 packages
    li $t3, 3
    beq $t0, $t3, done

    # If not, continue the loop
    j loop

update_lightest:
    # If the current weight is lighter, update $s0
    move $s0, $t2

    # Increment the loop counter
    addi $t0, $t0, 1

    # Check if we've processed all 3 packages
    li $t3, 3
    beq $t0, $t3, done

    # If not, continue the loop
    j loop

done:
    # At this point, $s0 contains the weight of the lightest package

    # Exit the program
    li $v0, 10
    syscall



#HW
.data
    packages: .space 300  # This declares a space in the data segment of memory for the `packages` array. Each package is 100 bytes, so for 3 packages we need 300 bytes.

.text
    addiu $s2, $zero, packages  # This loads the base address of the `packages` array into register `$s2`.
    ori $t0, $zero, 0x7FFFFFFF  # This initializes register `$t0` with the maximum possible value. This will be used to keep track of the minimum weight found so far.
    ori $t1, $zero, 0  # This initializes register `$t1` with zero. This will be used as an index to iterate over the `packages` array.

loop:
    addu $t2, $s2, $t1  # This calculates the address of the current package by adding the base address of the `packages` array and the current index.
    lw $t3, 2($t2)  # This loads the weight of the current package into register `$t3`. The weight is at an offset of 2 bytes from the start of the package.
    sltu $t4, $t3, $t0  # This compares the current weight with the minimum weight found so far. If the current weight is less, it sets `$t4` to 1; otherwise, it sets `$t4` to 0.
    beq $t4, $zero, update_min  # If `$t4` is not zero (i.e., if the current weight is less than the minimum found so far), it branches to `update_min`.
    addiu $t1, $t1, 100  # If `$t4` is zero (i.e., if the current weight is not less than the minimum), it increments `$t1` by 100 to move to the next package.
    sltiu $at, $t1, 300  
    bne $at, $zero, loop  # If `$t1` is less than 300 (i.e., if we have not reached the end of the `packages` array), it branches back to `loop`.

update_min:
    addu $t0, $zero, $t3  # This updates `$t0` with the current weight. This happens when we have found a package with a smaller weight.
    addiu $t1, $t1, 100  # This increments `$t1` by 100 to move to the next package.
    sltiu $at, $t1, 300  
    bne $at, $zero, loop  # If `$t1` is less than 300 (i.e., if we have not reached the end of the `packages` array), it branches back to `loop`.

end:
    addu $s0, $zero,
