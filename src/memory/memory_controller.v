/* moduledoc

  All data coming in or out of the CPU travels through the memory controller.  
  This includes both signals to peripherals and data coming in or out of memory.  
  As we don't know what is being connected to the other end, we have to make the memory controller very general purpose.  
  Rather than connecting to Avalon-MM Slaves directly, our memory controller (the Avalon-MM Master) will send requests to the interconnect, which translates addresses to their physical location.

  # Interaction with slaves

  The memory controller can be connected to multiple slaves, and can exchange requests with each of them.  
  Rather than connecting to a slave directly, the memory controller is more often than not connected through an interconnect fabric.  
  We're going to assume that this is the case here, as doing so will allow for a wider variety of configurations.  
  As such, we will only be sending control signals to the interconnect, which is assumed to be implemented by the testbench or components our CPU is connected to.  
  This means that the interconnect must resolve our generalised write, read, lock, etc. signals and send them only to the correct slave depending on the address.

  ## Input
  
  | Name                 | Width | Description                                                                                            |
  | :------------------- | ----: | :----------------------------------------------------------------------------------------------------- |
  | Read_Data            |    32 | The data which is being sent by a slave in a read operation                                            |
  | Response             |     2 | The response code from a slave following a request                                                     |
  | Wait_Request         |     1 | A signal sent by a slave when it is currently busy and cannot process an operation                     |
  | Read_Data_Valid      |     1 | A signal sent by a slave to indicate that it has received a read request and has started processing it |
  | Write_Response_Valid |     1 | A sent by a slave to indicate that it has received a write request and has started processing it       |
  
  ## Output

  | Name         | Width | Description                                                                                   |
  | :----------- | ----: | :-------------------------------------------------------------------------------------------- |
  | Address      |    32 | The word-aligned address of the memory data we want to read/write                             |
  | Byte_Enable  |     4 | The bytes which are to be read or written to by the CPU                                       |
  | Debug_Access |     1 | ? - Either we ignore it or it can edit the cache                                              |
  | Read         |     1 | Boolean indicating whether a read operation is being requested                                |
  | Write        |     1 | Boolean indicating whether a write operation is being requested                               |
  | Write_Data   |    32 | The data which is to be sent to a slave in a write operation                                  |
  | Lock         |     1 | A signal sent to a slave to indicate that only that master should be able to interact with it |

  There is also the potential to include burst signals but AFAIK I don't think we need them?  
  | Burst_Count | ? | Used somewhere when sending bursts of data to memory |

  # Interaction with the CPU

  ##

*/


module memory_controller (

  );

endmodule