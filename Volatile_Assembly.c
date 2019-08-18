    
/**Level 0 optimization	
	8:         uint32_t value =0; 
0x08000350 2000      MOVS          r0,#0x00
     9:         uint32_t *p = (uint32_t*)SRAM_Address1; 
    10:         //p is a pointer type variable that stores the data of type uint32. Typecasted SRAM_Address1 to become uint32_t type 
    11:          
0x08000352 4904      LDR           r1,[pc,#16]  ; @0x08000364
    12:         while(1) 
    13:         { 
0x08000354 E002      B             0x0800035C
    14:                 value = *p; //Value reads data at p address which is *p 
0x08000356 6808      LDR           r0,[r1,#0x00]
    15:                 if(value) 
0x08000358 B100      CBZ           r0,0x0800035C
    16:                 break; 
    17:                  
    18:         } 
    19:          
0x0800035A E000      B             0x0800035E
0x0800035C E7FB      B             0x08000356
0x0800035E BF00      NOP           
    20:         while(1); 
0x08000360 BF00      NOP           
0x08000362 E7FE      B             0x08000362

/** Level 3 optimization
     9:         uint32_t *p = (uint32_t*)SRAM_Address1; 
    10:         //p is a pointer type variable that stores the data of type uint32. Typecasted SRAM_Address1 to become uint32_t type 
    11:          
    12:         while(1) 
    13:         { 
0x08000340 4802      LDR           r0,[pc,#8]  ; @0x0800034C
    14:                 value = *p;     //Value reads data at p address which is *p 
    15:                 // 
0x08000342 6800      LDR           r0,[r0,#0x00]
    16:                 if(value) 
    17:                 break; 
    18:                  
    19:         } 
    20:          
0x08000344 2800      CMP           r0,#0x00
0x08000346 D0FD      BEQ           0x08000344	/Problem with this optimization is the value of r0 is not updated as it doesn't to LDR
    21:         while(1); 
0x08000348 E7FE      B             0x08000348