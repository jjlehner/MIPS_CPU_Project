module S_Register_File(	
	input	logic 			clk, EN , rst , WR , RD,
	input	logic [4:0]		read_address_1, read_address_2, write_address,
	input	logic [31:0]	write_data,	
	output	logic [31:0]	read_data_1,	read_data_2
);

reg[31:0] S_Register_File[0:31];

integer i;

wire sen;

assign sen = clk||rst; //Clock OR Rst are high (rst is active low)
//aDDED ALWAYS FF to make sure it works as a ff
always_ff @ (posedge sen)
begin
    if(EN == 1)
        begin
            if(rst == 1) // if at reset
        
                begin 
                    for(i = 0 ; i <32; i = i+1)
                    
                    begin
                    S_Register_File[i] = 32'h0;
                    end

                    read_data_1 = 32^hx

                end

            else if (rst == 0) //if not at reset

                begin
                
                    case({RD,WR})
                    
                    2'b00: 
                        begin //Nothing going on
                            
                        end
                    2'b01 
                        begin //WR ACTIVE
                            S_Register_File[write_address] = write_data;
                        end
                    2'b10 
                        begin //RD ACTIVE
                            read_data_1 = S_Register_File[read_address_1]
                            read_data_2 = S_Register_File[read_address_2]
                        end
                    2'b11 
                        begin //BOTH RD AND WR ACTIVE
                            read_data_1 = S_Register_File[read_address_1]
                            read_data_2 = S_Register_File[read_address_2]

                            S_Register_File[write_address] = write_data;
                            
                        end
                    
                    default: begin //IF UNDEFINED
                    endcase
                end

            else;
        end
    else;
end

endmodule
	