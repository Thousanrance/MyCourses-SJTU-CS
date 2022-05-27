# Assignment One

1.  *Which part is central to the Von Neumann architecture?* 

   *A. Input B. Output C. CU D. ALU E. Memory* 

   **Answer: D**

2. *Briefly describe the main difference between the Von Neumann architecture and the Harvard architecture and their pros and cons.*

   **Answer: For Von Neumann architecture, both instructions and data are stored in a single memory. For Harvard architecture, instructions are stored in instruction memory, data in data memory. Von Neumann architecture is more efficient, better performance, but prone to error. The Harvard architecture is more reliable, but less efficient and performs worse.** 

3. *Briefly describe the concept of micro-processor, micro-computer, and micro-computer system and their components.* 

   **Answer: A micro-processor is the CPU circuitry that can been reduced to IC scale, consisting of ALU, CU, and registers and contains no RAM, ROM, or I/O ports.**

   **A microcomputer is a small electronic computer composed of large scale integrated circuits, consisting of CPU, memory, I/O ports and bus which interconnects all parts together.**

   **Micro-computer system is a kind of computer system, consisting of micro-computer, peripheral I/O devices and software(system software and application software).** 

4. *What is the memory hierarchy and why?* 

   **Answer: Memory hierarchy is the order of different memory systems in computer architecture. Each layer has a higher speed, lower latency, and a smaller capacity than the next. The core of the memory hierarchy is that, for each k, the faster and smaller storage devices in the kth layer serve as a cache for the larger and slower memory devices in the k +1th layer. This can speed up data access, achieve better performance considering the limitation of hardware.** 

5. *If the width of the address bus and the data bus in one micro-computer is 20-bit and 32-bit, respectively, then what is the address space range and what is the size of a word for this computer?* 

   **Answer: The address space range is 2^20 bits or 1M. The size of a word for this computer is 32-bit.** 

6. *What does “system bus” mean in a micro-computer? What kinds of information can be conveyed on the system bus?* 

   **Answer: System bus connects major computer components(processor, memory, I/O). 系统总线上传输的信息包括数据信息、地址信息和控制信息。**

7. *When there are multiple modules connected to the system bus, why do we need some method of arbitration? Briefly describe the two main methods that deal with bus arbitration.* 

   **Answer: (1) Because all the modules want to convey information through system bus. But each time there is only one module can use it.** 

   **(2) Centralized: bus controller is responsible for allocating time on a bus.** 

   **Distributed: each module has access control logic and they collaborate.**

8. *What are the two solutions for addressing I/O devices? Briefly describe the features of each solution.* 

   **Answer: Memory-mapped I/O and isolated I/O.** 

   **(1) Memory-mapped I/O: there is only one single address space for both memory and I/O. Status and data registers of I/O modules are treated as memory locations. CPU uses the same machine instructions to access both.** 

   **(2) Isolated I/O: there are two separate address spaces for memory and I/O modules. CPU uses different sets of accessing instructions.** 

9. *What does the Moore’s Law talk about?* 

   **Answer:  Moore's law is the empirical observation that the complexity of integrated circuits, with respect to minimum component cost, doubles every 24 months.** 

10. *Convert the following hexadecimal numbers to decimal.* 

    *1) A3.3H* **= 168.1875**

    *2) 129.CH* **= 297.75**

    *3) AC.DCH* **= 172.859375**

    *4) FAB.3H* **= 4011.1875**

11. *Convert the following decimal numbers to binary, octal, and hexadecimal.* 

    *1) 23* **=  (10111)B = (27)O = (17)H**

    *2) 107* **=  (1101011)B = (153)O = (6B)H**

    *3) 1238* **=  (10011010110)B = (2326)O = (4D6)H**

    *4) 92* **=  (1011100)B = (134)O = (5C)H**