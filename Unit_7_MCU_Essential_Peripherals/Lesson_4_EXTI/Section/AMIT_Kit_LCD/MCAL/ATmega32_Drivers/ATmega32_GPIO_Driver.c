/*
 * ATmega32_GPIO_Driver.c
 *
 * Created: 2/18/2022 8:48:49 AM
 *  Author: Mina Karam
 */ 

#include "ATmega32_GPIO_Driver.h"

/**========================================================
 *@Fn                   - MCAL_GPIO_Init
 *@Brief                - initialize the GPIOx PINy according to config instance PinConfig.
 *@param[in]            - GPIOx : x can be (A..D) to select the GPIO peripheral.
 *@param[in]            - PinConfig : pointer to GPIO_PinConfig_t that contains pin/port configuration
 *@retval               - None
 *Note                  - None
 */
void MCAL_GPIO_Init (GPIO_Typedef_t * GPIOx, GPIO_PinConfig_t * PinConfig)
{
    switch (PinConfig->GPIO_PinNumber)
    {   
        case GPIO_PIN_0:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.bits.DD0     = 0b0;
                    GPIOx->PORT.bits.PORT0  = 0b0;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.bits.DD0    = 0b0;
                    GPIOx->PORT.bits.PORT0  = 0b1;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                {
                    GPIOx->DDR.bits.DD0    = 0b1;
                    GPIOx->PORT.bits.PORT0   = 0b0;
                    break;
                }
            }
            break;
        }
        case GPIO_PIN_1:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.bits.DD1    = 0b0;
                    GPIOx->PORT.bits.PORT1  = 0b0;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.bits.DD1    = 0b0;
                    GPIOx->PORT.bits.PORT1  = 0b1;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                {
                    GPIOx->DDR.bits.DD1    = 0b1;
                    GPIOx->PORT.bits.PORT1  = 0b0;
                }
            }
            break;
        }
        case GPIO_PIN_2:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.bits.DD2    = 0b0;
                    GPIOx->PORT.bits.PORT2  = 0b0;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.bits.DD2    = 0b0;
                    GPIOx->PORT.bits.PORT2  = 0b1;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                    GPIOx->DDR.bits.DD2    = 0b1;
                    GPIOx->PORT.bits.PORT2  = 0b0;
                    break;
            }
            break;
        }
        case GPIO_PIN_3:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.bits.DD3    = 0b0;
                    GPIOx->PORT.bits.PORT3  = 0b0;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.bits.DD3    = 0b0;
                    GPIOx->PORT.bits.PORT3  = 0b1;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                    GPIOx->DDR.bits.DD3    = 0b1;
                    GPIOx->PORT.bits.PORT3  = 0b0;
                    break;
            }
            break;
        }
        case GPIO_PIN_4:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.bits.DD4    = 0b0;
                    GPIOx->PORT.bits.PORT4  = 0b0;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.bits.DD4    = 0b0;
                    GPIOx->PORT.bits.PORT4  = 0b1;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                    GPIOx->DDR.bits.DD4    = 0b1;
                    GPIOx->PORT.bits.PORT4  = 0b0;
                    break;
            }
            break;
        }
        case GPIO_PIN_5:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.bits.DD5    = 0b0;
                    GPIOx->PORT.bits.PORT5  = 0b0;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.bits.DD5    = 0b0;
                    GPIOx->PORT.bits.PORT5  = 0b1;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                    GPIOx->DDR.bits.DD5    = 0b1;
                    GPIOx->PORT.bits.PORT5  = 0b0;
                    break;
            }
            break;
        }
        case GPIO_PIN_6:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.bits.DD6    = 0b0;
                    GPIOx->PORT.bits.PORT6  = 0b0;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.bits.DD6    = 0b0;
                    GPIOx->PORT.bits.PORT6  = 0b1;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                    GPIOx->DDR.bits.DD6    = 0b1;
                    GPIOx->PORT.bits.PORT6  = 0b0;
                    break;
            }
            break;
        }
        case GPIO_PIN_7:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.bits.DD7    = 0b0;
                    GPIOx->PORT.bits.PORT7  = 0b0;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.bits.DD7    = 0b0;
                    GPIOx->PORT.bits.PORT7  = 0b1;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                    GPIOx->DDR.bits.DD7    = 0b1;
                    GPIOx->PORT.bits.PORT7  = 0b0;
                    break;
            }
            break;
        }
        case GPIO_PORT:
        {
            switch(PinConfig->GPIO_PinMode)
            {
                case GPIO_MODE_INPUT_Hiz:
                {
                    GPIOx->DDR.DDR     = 0x00;
                    GPIOx->PORT.PORT    = 0x00;
                    break;
                }
                case GPIO_MODE_INPUT_PU:
                {
                    GPIOx->DDR.DDR     = 0x00;
                    GPIOx->PORT.PORT    = 0xFF;
                    break;
                }
                case GPIO_MODE_OUTPUT_PP:
                {
                    GPIOx->DDR.DDR     = 0xFF;
                    GPIOx->PORT.PORT    = 0x00;
                    break;
                }
            }
            break;
        }
    }
}

/**========================================================
 *@Fn                   - MCAL_GPIO_DeInit
 *@Brief                - Reset the GPIOx Registers.
 *@param[in]            - GPIOx : x can be (A..D) to select the GPIO peripheral.
 *@retval               - None
 *Note                  - None
 */
void MCAL_GPIO_DeInit(GPIO_Typedef_t * GPIOx)
{
    GPIOx->DDR.DDR     = 0x00;
    GPIOx->PORT.PORT    = 0x00;
}

/**========================================================
 *@Fn                   - MCAL_GPIO_ReadPin
 *@Brief                - Reads the GPIOx PINy Input Value.
 *@param[in]            - GPIOx : x can be (A..D) to select the GPIO peripheral.
 *@param[in]            - PinNumber : specifies the PIN to be read.
 *@retval               - either one of two states --> Check : @ref GPIO_PIN__STATE_define
 *Note                  - None
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_Typedef_t * GPIOx, uint8_t PinNumber)
{
    uint8_t PinState = 0;

    switch(PinNumber)
    {
        case GPIO_PIN_0:
        {
            PinState = (uint8_t)(GPIOx->PIN.bits.PIN0);
            break;
        }
        case GPIO_PIN_1:
        {
            PinState = (uint8_t)(GPIOx->PIN.bits.PIN1);
            break;
        }
        case GPIO_PIN_2:
        {
            PinState = (uint8_t)(GPIOx->PIN.bits.PIN2);
            break;
        }
        case GPIO_PIN_3:
        {
            PinState = (uint8_t)(GPIOx->PIN.bits.PIN3);
            break;
        }
        case GPIO_PIN_4:
        {
            PinState = (uint8_t)(GPIOx->PIN.bits.PIN4);
            break;
        }
        case GPIO_PIN_5:
        {
            PinState = (uint8_t)(GPIOx->PIN.bits.PIN5);
            break;
        }
        case GPIO_PIN_6:
        {
            PinState = (uint8_t)(GPIOx->PIN.bits.PIN6);
            break;
        }
        case GPIO_PIN_7:
        {
            PinState = (uint8_t)(GPIOx->PIN.bits.PIN7);
            break;
        }
    }
    return PinState;
}

/**========================================================
 *@Fn                   - MCAL_GPIO_ReadPort
 *@Brief                - Reads the GPIOx Input Value.
 *@param[in]            - GPIOx : x can be (A..D) to select the GPIO peripheral.
 *@retval               - The input value of GPIOx
 *Note                  - None
 */
uint8_t MCAL_GPIO_ReadPort(GPIO_Typedef_t * GPIOx)
{
    uint8_t PortState = 0x00;
    PortState = (uint8_t)(GPIOx->PIN.PIN);
    return PortState;
}

/**========================================================
 *@Fn                   - MCAL_GPIO_WritePin
 *@Brief                - Writes either one of @ref GPIO_PIN__STATE_define value on the GPIOx PINy.
 *@param[in]            - GPIOx : x can be (A..D) to select the GPIO peripheral.
 *@param[in]            - PinNumber : specifies the PIN to be read.
 *@param[in]            - data : specifies one of @ref GPIO_PIN__STATE_define to be written
 *@retval               - None
 *Note                  - None
 */
void MCAL_GPIO_WritePin(GPIO_Typedef_t * GPIOx, uint8_t PinNumber, uint8_t data)
{
    switch(PinNumber)
    {
        case GPIO_PIN_0:
        {
            if(data)
                GPIOx->PORT.bits.PORT0 = 0b1;
            else
                GPIOx->PORT.bits.PORT0 = 0b0;
            break;
        }
        case GPIO_PIN_1:
        {
            if(data)
                GPIOx->PORT.bits.PORT1 = 0b1;
            else
                GPIOx->PORT.bits.PORT1 = 0b0;
            break;
        }
        case GPIO_PIN_2:
        {
            if(data)
                GPIOx->PORT.bits.PORT2 = 0b1;
            else
                GPIOx->PORT.bits.PORT2 = 0b0;
            break;
        }
        case GPIO_PIN_3:
        {
            if(data)
                GPIOx->PORT.bits.PORT3 = 0b1;
            else
                GPIOx->PORT.bits.PORT3 = 0b0;
            break;
        }
        case GPIO_PIN_4:
        {
            if(data)
                GPIOx->PORT.bits.PORT4 = 0b1;
            else
                GPIOx->PORT.bits.PORT4 = 0b0;
            break;
        }
        case GPIO_PIN_5:
        {
            if(data)
                GPIOx->PORT.bits.PORT5 = 0b1;
            else
                GPIOx->PORT.bits.PORT5 = 0b0;
            break;
        }
        case GPIO_PIN_6:
        {
            if(data)
                GPIOx->PORT.bits.PORT6 = 0b1;
            else
                GPIOx->PORT.bits.PORT6 = 0b0;
            break;
        }
        case GPIO_PIN_7:
        {
            if(data)
                GPIOx->PORT.bits.PORT7 = 0b1;
            else
                GPIOx->PORT.bits.PORT7 = 0b0;
            break;
        }
    }
}

/**========================================================
 *@Fn                   - MCAL_GPIO_WritePort
 *@Brief                - Writes data on the GPIOx .
 *@param[in]            - GPIOx : x can be (A..D) to select the GPIO peripheral.
 *@param[in]            - data : specifies the data to be written
 *@retval               - None
 *Note                  - None
 */

void MCAL_GPIO_WritePort(GPIO_Typedef_t * GPIOx, uint8_t data)
{
    GPIOx->PORT.PORT = data;
}

/**========================================================
 *@Fn                   - MCAL_GPIO_TogglePin
 *@Brief                - Toggles the GPIOx PINy.
 *@param[in]            - GPIOx : x can be (A..D) to select the GPIO peripheral.
 *@param[in]            - PinNumber : specifies the PIN to be read.
 *@retval               - None
 *Note                  - None
 */
void MCAL_GPIO_TogglePin(GPIO_Typedef_t * GPIOx, uint8_t PinNumber)
{
    switch(PinNumber)
    {
        case GPIO_PIN_0:
        {
            GPIOx->PORT.bits.PORT0 ^= 0b1;
            break;
        }
        case GPIO_PIN_1:
        {
            GPIOx->PORT.bits.PORT1 ^= 0b1;
            break;
        }
        case GPIO_PIN_2:
        {
            GPIOx->PORT.bits.PORT2 ^= 0b1;
            break;
        }
        case GPIO_PIN_3:
        {
            GPIOx->PORT.bits.PORT3 ^= 0b1;
            break;
        }
        case GPIO_PIN_4:
        {
            GPIOx->PORT.bits.PORT4 ^= 0b1;
            break;
        }
        case GPIO_PIN_5:
        {
            GPIOx->PORT.bits.PORT5 ^= 0b1;
            break;
        }
        case GPIO_PIN_6:
        {
            GPIOx->PORT.bits.PORT6 ^= 0b1;
            break;
        }
        case GPIO_PIN_7:
        {
            GPIOx->PORT.bits.PORT7 ^= 0b1;
            break;
        }
    }
}