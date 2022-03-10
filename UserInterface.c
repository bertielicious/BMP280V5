#include "config.h"
#include "writePCF8583.h"
#include "decToBcd.h"
#include "setColumnAddress.h"
#include "setPageAddress.h"
#include "oLedWrite.h"
#include "selectDigit.h"
#include "writeColon.h"

/********************User interface************************/
/*Overview: This function disables the clock counting, then allows the input of current time
Input: */
uint8_t stopCounting;
void UserInterface(uint8_t state)
{
   
   
    
    stopCounting = decToBcd(128);
    writePCF8583(0xa0, 0x00, stopCounting);// stop the clock counting, might need to clear seconds
    
    
    switch(state)
    {
    case 1:
        writeColon(2,0,'S', 8);// write 'Set time on page 0
        writeColon(10,0,'e', 8);
        writeColon(18,0,'t', 8);
        writeColon(34,0,'t', 5);
        writeColon(42,0,'i', 5);
        writeColon(50,0,'m', 8);
        writeColon(58,0,'e', 8);
        writeColon(66,0,'Q', 8);
        break;
    
        case 2:
        writeColon(2,2,'h', 8);
        writeColon(10,2,'o', 8);
        writeColon(18,2,'u', 8);
        writeColon(26,2,'r', 8);
        writeColon(34,2,'s', 8);
        
        break;
        
        
        case 3:
        
                if( NO == LO && (setHours >=0 && setHours <12))
                {
                    
                    writeColon(42, 2, setHours, 8);
                    setHours--;
                }
        break;
            
  
    
    }

}