

#include "1.MCAL/TIMER/Timer.h"

#include "4.LIB/Platform_Types.h"
#include "4.LIB/Std_Types.h"
#include "4.LIB/Bit_Math.h"
#include "4.LIB/hw_gpio.h"

#include "1.MCAL/GPIO/INC/GPIO_Interface.h"

extern volatile char LED_TOGLLE;

extern volatile char Pressed;
int main(void)
{

    const GPIO_Config_t Config[4] ={{GPIO_PORTD,GPIO_PIN0,GPIO_PIN_INPUT,GPIO_PIN_ALTFUNC,GPIO_PIN_PUSHPULL,GPIO_PIN_PULLUP,GPIO_2MA_DRIVE,GPIO_ALTFUNC7},
                                    {GPIO_PORTF,GPIO_PIN1,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                    {GPIO_PORTF,GPIO_PIN2,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
                                    {GPIO_PORTF,GPIO_PIN3,GPIO_PIN_OUTPUT,GPIO_PIN_DIGITAL,GPIO_PIN_PUSHPULL,GPIO_PIN_FLOATING,GPIO_2MA_DRIVE,GPIO_ALTFUNC0},
    };

    GPIO_Init(Config, 4);



//  timer_Init(wTimer2, edgeTime ,up ,timerA,240000000,nigative);

    int capturedVal=0;
    while(1)
    {
        if(Pressed == 1)
        {
            Pressed =0;
            capturedVal = WTIMER2_TAR_R;
            if(capturedVal <= 80000000)
            {
                SET_BIT(GPIO_PORTF_DATA_R,1);
                CLR_BIT(GPIO_PORTF_DATA_R,2);
                CLR_BIT(GPIO_PORTF_DATA_R,3);

            }
            else if(capturedVal <= 160000000)
            {
                SET_BIT(GPIO_PORTF_DATA_R,2);
                CLR_BIT(GPIO_PORTF_DATA_R,1);
                CLR_BIT(GPIO_PORTF_DATA_R,3);

            }
            else if(capturedVal <= 240000000)
            {
                SET_BIT(GPIO_PORTF_DATA_R,3);
                CLR_BIT(GPIO_PORTF_DATA_R,1);
                CLR_BIT(GPIO_PORTF_DATA_R,2);
            }

        }
    }

    return 0;
}
