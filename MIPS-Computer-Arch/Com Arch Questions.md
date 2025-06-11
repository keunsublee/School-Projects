1. **What is a program?** 
   - It is a sequence of instructions that (CPU) executes to accomplish a particular goal.

2. **What is data?** 
   - Data refers to the raw facts and figures that are processed by a computer program. It can be numbers, text, images, or any information that is used, manipulated, and processed by software.

3. **What does it mean to run the program?** 
   - Running a program means executing its instructions or code in a computer. It involves the CPU executing each instruction in sequence, following the program's logic, and producing the desired output.

4. **What computer component executes programs?** 
   - CPU interprets and executes program.

5. **Where is the running program stored? What else is stored there?** 
   - RAM (Random Access Memory). In addition to the program code, RAM also stores data that the program is currently working with, program variables, and the stack for function calls.

6. **What do we know about RAM memory?** 
   - RAM is a type of computer memory that is random-access, meaning you can access any location in memory with roughly the same speed. It is volatile, data is lost when the computer is powered off or restarted.

7. **What is memory stall?** 
   - A memory stall, also known as a memory access stall or memory latency, occurs when the CPU has to wait for data to be retrieved from memory. This can slow down program execution.

8. **What long-term storage do we have?** 
   - Long-term storage typically refers to storage devices like hard drives and solid-state drives (SSDs), where data can be stored for an extended period, even when the computer is powered off.

9. **What is an executable file?** 
   - An executable file is a type of computer file that contains a program or application in a format that can be directly run or executed by the computer's operating system. It typically has the necessary instructions for the CPU to carry out the program's tasks.

10. **How does the speed of CPU, RAM, and hard disk compare to each other?** 
    - CPUs are much faster than both RAM and hard disks. RAM is faster than hard disks, but it is still significantly slower than the CPU. Hard disks are the slowest of the three for data access.

11. **What is a machine cycle?** 
    - A machine cycle is the basic operation performed by the CPU. It typically consists of fetching an instruction from memory, decoding the instruction, executing it, and writing back the results if necessary.

12. **What are the basic steps of a machine cycle?** 
    - The basic steps of a machine cycle are Fetch, Decode, Execute, and Write Back (if necessary). These steps are performed for each instruction in the program.

13. **What does frequency measure? What is the measurement unit of frequency?** 
    - Frequency measures the number of cycles or events that occur in a unit of time. The measurement unit of frequency is Hertz (Hz), which represents cycles or events per second.

14. **What is CPU clock? What is CPU frequency?** 
    - The CPU clock is a signal that synchronizes the operations of the CPU. CPU frequency, often referred to as clock speed, is the number of clock cycles the CPU can execute in one second. It is measured in Hertz (Hz).

15. **What is a CPU core? What does it mean "quad-core CPU," "octa-core CPU"?** 
    - A CPU core is an individual processing unit within a CPU that can execute instructions independently. A quad-core CPU has four such cores, while an octa-core CPU has eight. The term "core" indicates the number of processing units available for parallel processing.

16. **How does memory look like?** 
    - Memory is often depicted as a linear array of bytes, where each byte is assigned a unique address. It's like a large sequence of storage locations, each capable of storing 8 bits (a byte).

17. **What is a byte? What is a bit? How many bits are in a byte?** 
    - A byte is a unit of digital information storage that consists of 8 bits. A bit is the smallest unit of data, representing a binary value of 0 or 1.

18. **What is a memory address?** 
    - A memory address is a unique identifier for a specific location in computer memory (RAM) where data can be stored or retrieved.

19. **What is the memory address of a larger chunk of memory?** 
    - A memory address can specify any location within the entire range of memory, from the start (address 0) to the maximum address supported by the system.

20. **What is the length of a memory address? What does it mean "32-bit address"?** 
    - The length of a memory address refers to the number of bits used to represent a memory location. A "32-bit address" means that the memory system can address 2^32 (approximately 4.3 billion) unique memory locations.

21. **How much memory can we address/use with the given length of memory address?** 
    - With a 32-bit memory address, a computer can theoretically address up to 4 gigabytes (GB) of memory.

22. **How long should memory addresses be to address a given amount of memory?** 
    - The length of memory addresses required to address a given amount of memory is determined by the formula: 2^n, where "n" is the number of bits in the address. For example, to address 1 terabyte (1 TB) of memory, you would need a 40-bit address.

23. **Can memory contain nothing at all?** 
    - Usually some type of garbage data

24. **What is the relationship between a C++ variable, RAM, and memory address?** 
    - In C++, variables are stored in RAM, and each variable is associated with a unique memory address that allows the program to access its data.

25. **What is a C++ pointer?** 
    - A C++ pointer is a variable that stores the memory address of another variable. It allows you to manipulate and access data indirectly by referencing the memory location of another variable.

26. **What is the most common size of the following C++ data types: char, short, int, long, long long, float, double? Does signed/unsigned affect those sizes?** 
    - The sizes of C++ data types can vary depending on the platform, but common sizes are:
      - char: 1 byte
      - short: 2 bytes
      - int: 4 bytes
      - long: 4 or 8 bytes
      - long long: 8 bytes
      - float: 4 bytes
      - double: 8 bytes
      - The "signed" or "unsigned" modifier can affect the range of values that a data type can hold, but it usually doesn't impact the size.

27. **Hexadecimal numbers. Why do we use them? How to convert from hexadecimal to binary and back quickly?**
    - Hexadecimal numbers are used because they provide a concise way to represent binary data. Each hexadecimal digit corresponds to four binary bits. To convert between hexadecimal and binary, group hexadecimal digits in sets of four and replace them with their binary equivalent. To convert from binary to hexadecimal, group binary digits in sets of four, replace them with their hexadecimal equivalent, and pad with leading zeros if necessary.



1. **What is a "word"?**
- A "word" in computer architecture typically refers to the natural unit of data that a CPU operates on. It can vary in size depending on the architecture but is often 32 bits (4 bytes) or 64 bits (8 bytes).

2. **What is PC?**
- PC stands for "Program Counter." It is a register in the CPU that keeps track of the address of the next instruction to be executed.

3. **What is the language that the CPU understands?**
- The CPU understands a low-level language known as machine code or binary code, consisting of binary instructions that represent specific operations.

4. **How can we execute a program written in higher-level languages?**
- Programs written in higher-level languages are typically compiled or interpreted into machine code that the CPU can execute. Compilers and interpreters are tools used to translate high-level language code into machine code.

5. **What is a compiler? What are compiler advantages?**
- A compiler is a tool that translates high-level source code into machine code ahead of time. Compiler advantages include faster execution (no need for on-the-fly translation), potential for code optimization, and protection of source code.

6. **What is an interpreter? What are interpreter advantages?**
- An interpreter is a tool that translates high-level source code into machine code. Interpreter advantages include platform independence, ease of debugging, and the ability to modify code without recompilation.

7. **Performance: What is CPU frequency? What is CPU clock device? What is a cycle? Does CPU frequency affect computer performance? Does CPU frequency fully define computer performance? Name other factors that define computer performance. What are the software factors that affect execution speed? What hurts program execution speed more: weak hardware or inefficient program code? What is the most reliable way to compare performance of different computers? Why a single benchmark isn't enough, and we use benchmark suites?**
- CPU frequency, or clock speed, refers to the number of clock cycles the CPU can execute per second. It does impact performance but doesn't fully define it. Other factors that influence performance include the number of CPU cores, CPU architecture, RAM performance, cache efficiency, and software factors like program efficiency and compiler efficiency. Inefficient program code can significantly hurt execution speed. Comparing performance between different computers is best done using benchmark suites because a single benchmark may not represent all aspects of performance effectively.

8. **Prefixes k, M, G, ki, Mi, Gi, p, n.**
- These are prefixes used to represent multiples of a base unit (e.g., bytes). For example:
  - k (kilo): 1 kilobyte (KB) = 1,024 bytes
  - M (mega): 1 megabyte (MB) = 1,024 kilobytes
  - G (giga): 1 gigabyte (GB) = 1,024 megabytes
  - ki (kibi): 1 kibibyte (KiB) = 1,024 bytes (used in binary contexts)

9. **How do you compare execution times of two programs?**
 measure the ratio of their execution times.

10. **What is average CPI? What is the measurement unit of average CPI? What is dynamic instruction count? What is the measurement unit of dynamic instruction count? Equations that connect execution time, total number of cycles, CPU frequency (also known as clock rate), cycle duration, average CPI, dynamic instruction count.**
- Average CPI (Cycles Per Instruction) measures the average number of clock cycles required for each instruction to execute. The unit of measurement for average CPI is "cycles per instruction." Dynamic instruction count represents the total number of instructions executed during a program's run. Equations connecting these concepts include:
  - Execution Time (ET) = (Dynamic Instruction Count) x (Average CPI) / (CPU Frequency)
  - CPU Frequency (Clock Rate) = 1 / (Cycle Duration)

11. **What is a CPU instruction?**
- A CPU instruction is a single CPU operation or unit of work the CPU executes.

12. **What is an instruction set (often abbreviated as ISA)?**
- An instruction set architecture (ISA) is a specification that defines the set of instructions that a CPU can execute. It includes details about the available operations, data types, and addressing modes supported by the CPU.

13. **What is CPU architecture?**
- CPU architecture refers to the design and organization of a CPU, including the instruction set, number and size of registers, word size, addressing modes, and other fundamental specifications that define how the CPU operates.

14. **What is specified in CPU architecture?**
- CPU architecture specifies the instruction set, the number and size of registers, the word size (data size the CPU can operate on), addressing modes, and other key parameters that guide the design and behavior of the CPU.

15. **What is assembly language?**
- Assembly language is a low-level programming language that uses mnemonics and symbols to represent CPU instructions. It is a human-readable form of machine code and closely corresponds to the instructions the CPU understands.

16. **What are the main properties of assembly languages?**
- The main properties of assembly languages are that they closely represent CPU instructions and are architecture-specific, meaning each CPU architecture has its own assembly language.

17. **List some assembly languages you've heard of.**
- Common assembly languages include MIPS for older CPUs, x86 for Intel-style CPUs, and ARM 8 for smartphone CPUs.

18. **What are pseudo-instructions?**
- Pseudo-instructions are not actual machine instructions but are higher-level abstractions provided by some assembly languages for convenience. They are translated into real machine code by the assembler. 

19. **How many general-purpose registers do MIPS CPUs have? How big is each MIPS general-purpose register?**
- MIPS CPUs typically have 32 general-purpose registers. Each MIPS general-purpose register is 32 bits in size.

20. **Can a register store nothing at all? Can some bits in a register store nothing at all?**
- Registers can store data, but they can also store special values like zero or undefined values. Individual bits in a register can represent specific data or be unused, depending on the context.

21. **Name some MIPS general-purpose registers.**
- MIPS general-purpose registers include $s0 - $s7, $t0 - $t7, and $zero (which is a special register often used to represent the value zero).

22. **What is stored in the register $zero? Are we allowed to change its content?**
- The register $zero typically holds the value zero. You are not allowed to change its content, and attempting to do so would have no effect.

23. **Instructions add, addi, sub. How to use them correctly?** 
    - The "add" instruction is used to add two registers and store the result in a destination register. The "addi" instruction adds a register and an immediate value. The "sub" instruction subtracts two registers and stores the result in a destination register. Correct usage involves following the instruction format and using "$" with register names.

24. **What is an immediate value?**
- An immediate value is a constant value that is directly specified in an instruction. It can be used as an operand or an argument in some instructions.

25. **What is another way to pass values to instructions?**
- Another way to pass values to instructions is by specifying the name of a register that contains the value you want to use as an operand.

26. **If an instruction wants to see an immediate value as a certain parameter, can we replace it with the register name?**
- No, you cannot replace an immediate value with a register name if the instruction expects a specific immediate value. Similarly, you cannot replace a register name with an immediate value if the instruction expects a register as an operand.

27. **Where is a variable stored?**
- Variables are typically stored in RAM, which is the computer's main memory. The variable's value is read from and written to RAM when needed.

28. **What is loading the register?**
- Loading the register refers to the process of transferring data from memory (RAM) into a CPU register, making it available for use in CPU operations.

29. **What is storing to RAM?**
- Storing to RAM refers to the process of transferring data from a CPU register into memory (RAM) so that it can be preserved for future use.

30. **Endianess. Big-endian and little-endian.**
- Endianness refers to the byte order in which multi-byte data types are stored in memory. In big-endian systems, the most significant byte is stored at the lowest memory address. In little-endian systems, the least significant byte is stored at the lowest memory address.

31. **What should we do to use the value of a variable?**
- To use the value of a variable, you need to load it from RAM into a CPU register.

32. **When does a variable become modified?**
- A variable becomes modified after its value is changed in a CPU register and needs to be stored back in RAM to preserve the new value.

33. **2’s complement representation of signed integers.**
- 2's complement is a method for representing signed integers in binary. In this representation, the most significant bit (leftmost) is the sign bit (0 for positive, 1 for negative), and the rest of the bits represent the magnitude of the integer using two's complement arithmetic.

34. **Unsigned integer representation.**
- Unsigned integers are represented using a straightforward binary representation, with no sign bit. All bits contribute to the magnitude of the number.

35. **Know how to determine numeric limits for both 2’s complement and unsigned representations when given the number of bits.**
- For a given number of bits, you can calculate the numeric limits of 2's complement and unsigned representations. For 2's complement, the range is from -2^(n-1) to 2^(n-1) - 1, where "n" is the number of bits. For unsigned, the range is from 0 to 2^n - 1.

36. **Be ready to use lw, lh, lb, lhu, lbu, sw, sh, sb.**
- These are MIPS instructions for loading (lw, lh, lb, lhu, lbu) and storing (sw, sh, sb) data in memory. They specify the size of the data to load/store and the addressing mode.

37. **How do we specify memory address in loading and storing instructions?**
- Memory addresses in loading and storing instructions are specified as an offset from a base register. The format typically used is "offset(base_register)."

38. **Are we allowed to use any other address specification format other than immediate_offset(register) for load and store instructions in our course?**
- In your course, you may be restricted to using the immediate offset format for load and store instructions.

39. **What is the difference between lh and lhu, between lb and lbu?**
- "lh" loads a half-word (16 bits) from memory, while "lhu" loads an unsigned half-word (16 bits). "lb" loads a byte (8 bits) from memory, while "lbu" loads an unsigned byte (8 bits). The difference is in how the sign bit is treated.

40. **Why we don’t need an swu instruction? Pay attention, this instruction doesn’t exist.**
- An "swu" instruction doesn't exist because storing a word is inherently unsigned. There's no concept of a signed word in memory.

41. **Why we don’t need separate signed and unsigned versions for storing instructions.**
- Storing instructions (sw, sh, sb) don't distinguish between signed and unsigned data because the data is simply stored as a sequence of bits in memory. The interpretation of the data as signed or unsigned is a matter of how it's used by the program, not how it's stored.

42. **j instruction. Label. Does a label exist as a separate item in the compiled program code? What does a label turn into in the compiled program code? Instructions beq and bne. What unconditional jumps do you know (j)? What conditional jumps or branches do you know (beq, bne)?**
- The "j" instruction is used for unconditional jumps. Labels are used to mark locations in the program code, and they don't exist as separate items in compiled code; they turn into memory addresses of the labeled instructions. The "beq" and "bne" instructions are used for conditional branches. "j" is an example of an unconditional jump, while "beq" and "bne" are examples of conditional jumps.

43. **Instructions slt, slti, sltu, sltiu.**
- These instructions are used for comparing values and setting a destination register based on the result of the comparison. "slt" compares two registers and sets the destination to 1 if the first is less than the second. "slti" compares a register and an immediate value. "sltu" is the same as "slt" but treats values as unsigned. "sltiu" is the same as "sltu" but compares with an immediate value.

44. **Be able to give an example of two parameters in the form of bit patterns that produce different results in slt and sltu.**
- For "slt," a result of 1 indicates that the first value is less than the second, even if they're treated as signed. For "sltu," a result of 1 indicates that the first value is less than the second when they are treated as unsigned. An example could involve comparing two numbers that have different signs, where "slt" produces a 1, and "sltu" produces a 0.

45. **Be ready to implement common C++ statements like for, while, do-while, if-else, switch in MIPS. You should be able to preserve C++ behavior of those statements completely.** 
    - Implementing common C++ control statements in MIPS assembly requires careful management of conditional branches and loops to replicate the behavior of C++ constructs. This often involves using conditional branch instructions like "beq" and "bne" and loop control instructions like "j" (unconditional jump). The goal is to preserve the logical flow and behavior of the C++ code when translating it to MIPS assembly.
