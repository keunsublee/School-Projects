.data
num1:  .word  5        # Declare a memory location 'num1' and store the value 5.
num2:  .word  3        # Declare a memory location 'num2' and store the value 3.
result: .word 0        # Declare a memory location 'result' and initialize it to 0.

.text
.globl main
main:
    lw $t0, num1       # Load the value of 'num1' into $t0.
    lw $t1, num2       # Load the value of 'num2' into $t1.
    add $t2, $t0, $t1  # Add values in $t0 and $t1 and store the result in $t2.
    sw $t2, result     # Store the result in 'result'.

    # Exit program
    li $v0, 10          # Load syscall code for program exit into $v0.
    syscall             # Execute the syscall.


#SUB
.data
num1:  .word  8        # Declare a memory location 'num1' and store the value 8.
num2:  .word  3        # Declare a memory location 'num2' and store the value 3.
result: .word 0        # Declare a memory location 'result' and initialize it to 0.

.text
.globl main
main:
    lw $t0, num1       # Load the value of 'num1' into $t0.
    lw $t1, num2       # Load the value of 'num2' into $t1.
    sub $t2, $t0, $t1  # Subtract the value in $t1 from $t0 and store the result in $t2.
    sw $t2, result     # Store the result in 'result'.

    # Exit program
    li $v0, 10          # Load syscall code for program exit into $v0.
    syscall             # Execute the syscall.



# calculate address of arr[k + 5]
addu $t0, $s1, $s1  # $t0 = 2*k. This is done by adding k to itself.
addiu $t0, $t0, 5  # $t0 = 2*k + 5. This is done by adding 5 to the result of the previous operation.
sll $t0, $t0, 2  # $t0 = 4*(2*k + 5) to account for size of int. This is done by shifting the bits of the result of the previous operation to the left by 2 places, which is equivalent to multiplying by 4.
addu $t0, $s0, $t0  # $t0 = &arr[2*k + 5]. This is done by adding the base address of the array (stored in $s0) to the result of the previous operation.

# load arr[k + 5] into $t1
lw $t1, 0($t0)  # This loads the value at the memory address calculated above into register $t1.

# add 6 to arr[k + 5]
addiu $t1, $t1, 6  # This adds 6 to the value loaded into register $t1.

# calculate address of arr[2*k + 3]
addu $t2, $s1, $s1  # $t2 = 2*k. This is done by adding k to itself.
addiu $t2, $t2, 3  # $t2 = 2*k + 3. This is done by adding 3 to the result of the previous operation.
sll $t2, $t2, 2  # $t2 = 4*(2*k + 3) to account for size of int. This is done by shifting the bits of the result of the previous operation to the left by 2 places, which is equivalent to multiplying by 4.
addu $t2, $s0, $t2  # $t2 = &arr[2*k + 3]. This is done by adding the base address of the array (stored in $s0) to the result of the previous operation.

# store result in arr[2*k + 3]
sw $t1, 0($t2)   # This stores the value in register t1 (which is arr[k+5]+6) into memory at address calculated above (which is &arr[2*k+3]).
