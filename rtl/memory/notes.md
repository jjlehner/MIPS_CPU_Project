* We're going to assume that our CPU is running at 30MHz, ie 1 clock per 33ns as this is a reasonable clock rate for the [MIPS R3000](https://cgi.cse.unsw.edu.au/~cs3231/doc/R3000.pdf).
* The RAM is partially going to be modelled after [this](https://faculty-web.msoe.edu/johnsontimoj/EE4980/files4980/SDRAM_Spec.pdf). This RAM runs at 133 MHz, ie 1 clock per 7.5ns.
* As we're using DRAM, we need to periodically refresh the values of the capacitors.
* For convenience's sake, we're going to run our memory at 135MHz. This means 1 clock per 7.4ns.
* The read latency is 5.4ns, meaning our hold time is effectively negligable (<1 clock cycle).
* The time to change from one bank to another is 15ns. This is ~2 clock cycles so will have to be accounted for using the wait signal.
* Our memory will be sorted into blocks, banks, columns & rows. We have 8 
* Our memory will auto-refresh when not in use, or when the time since a row was last refreshed is on track to be over 64ms.
* From what I can see there are 2 ways of refreshing the memory, 1 is time efficient, area inefficient and the other the inverse. We will need to store the time since each row was last refreshed somewhere, & theoretically we could skip rows which have been refreshed recently. The issue with this is that we don't know whether there are registers which were skipped which are exceeding 64ms since the last refresh so we would have to implement expensive logic to figure that out as well as to decide whether a row was accessed recently enough that we can skip it.

Memory block layout:

Block 0: Addresses 0x00000000-0x1FFFFFF  
* Bank 0: Addresses 0x00000000-0x07FFFFF  
* Bank 1: Addresses 0x08000000-0x0FFFFFF  
* Bank 2: Addresses 0x10000000-0x17FFFFF  
* Bank 3: Addresses 0x08000000-0x1FFFFFF  

Block 1: Addresses 0x20000000-0x3FFFFFF  
* Bank 0: Addresses 0x20000000-0x27FFFFF  
* Bank 1: Addresses 0x28000000-0x2FFFFFF  
* Bank 2: Addresses 0x30000000-0x37FFFFF  
* Bank 3: Addresses 0x38000000-0x3FFFFFF  

Block 2: Addresses 0x40000000-0x5FFFFFF  
* Bank 0: Addresses 0x40000000-0x47FFFFF  
* Bank 1: Addresses 0x48000000-0x4FFFFFF  
* Bank 2: Addresses 0x50000000-0x57FFFFF  
* Bank 3: Addresses 0x58000000-0x5FFFFFF  

Block 3: Addresses 0x60000000-0x7FFFFFF  
* Bank 0: Addresses 0x60000000-0x67FFFFF  
* Bank 1: Addresses 0x68000000-0x6FFFFFF  
* Bank 2: Addresses 0x70000000-0x77FFFFF  
* Bank 3: Addresses 0x78000000-0x7FFFFFF  

Block 4: Addresses 0x80000000-0x9FFFFFF  
* Bank 0: Addresses 0x80000000-0x87FFFFF  
* Bank 1: Addresses 0x88000000-0x8FFFFFF  
* Bank 2: Addresses 0x90000000-0x97FFFFF  
* Bank 3: Addresses 0x98000000-0x9FFFFFF  

Block 5: Addresses 0xA0000000-0xBFFFFFF  
* Bank 0: Addresses 0xA0000000-0xA7FFFFF  
* Bank 1: Addresses 0xA8000000-0xAFFFFFF  
* Bank 2: Addresses 0xB0000000-0xB7FFFFF  
* Bank 3: Addresses 0xB8000000-0xBFFFFFF <- Program start lives most of the way through here (seriously pick a worse place to make your program lmao)  

Block 6: Addresses 0xC0000000-0xDFFFFFF  
* Bank 0: Addresses 0xC0000000-0xC7FFFFF  
* Bank 1: Addresses 0xC8000000-0xCFFFFFF  
* Bank 2: Addresses 0xD0000000-0xD7FFFFF  
* Bank 3: Addresses 0xD8000000-0xDFFFFFF  

Block 7: Addresses 0xE0000000-0xFFFFFFF  
* Bank 0: Addresses 0xE0000000-0xF7FFFFF  
* Bank 1: Addresses 0xE8000000-0xFFFFFFF  
* Bank 2: Addresses 0xF0000000-0xF7FFFFF  
* Bank 3: Addresses 0xF8000000-0xFFFFFFF  


It is regrettable that the program start location falls in the middle of a block, however it'd need extra logic that I'm simply too busy to implement to not put it there.

The MIPS creators are big dumb for assuming their memory blocks would never be larger than 4MB.