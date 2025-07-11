#include "stm32f10x.h"                  // Device header
#include "SysTick.h"
#include "gp_drive.h"
#include "CAN_Drive.h"

void SystemInitClock(void)
{
    RCC->CR |= RCC_CR_HSEON; // Enable HSE
    while (!(RCC->CR & RCC_CR_HSERDY)); // Wait for HSE to be ready

    RCC->CFGR |= RCC_CFGR_PLLSRC; // HSE oscillator clock selected as PLL input clock
    RCC->CFGR |= RCC_CFGR_PLLMULL9; // PLL input clock x 9

    RCC->CR |= RCC_CR_PLLON; // Enable PLL
    while (!(RCC->CR & RCC_CR_PLLRDY)); // Wait for PLL to be ready

    RCC->CFGR |= RCC_CFGR_SW_PLL; // PLL selected as system clock
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL); // Wait for PLL to be used as system clock

    SystemCoreClockUpdate(); // Update SystemCoreClock variable
}

int main()
{
uint32_t received_id;
uint8_t received_data[8];
uint8_t received_length;
uint8_t test_data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

	SystemInitClock();
	//CAN_init(1);
	
	CAN_init(2); // Initialize CAN1

    // Test sending a message
    CAN_SendMessage(CAN2, 0x123, test_data, 8);

    while (1)
    {
        // Check if a message is received
        if (CAN_ReceiveMessage(CAN2, &received_id, received_data, &received_length) == 0)
        {
            // Message received successfully
            init_GP(PA,13,OUT50,O_GP_PP);
					  toggle_GP(PA,13);
        }
    }
		
		
		/*
		RCC->APB2ENR |= 0x4; //Enabled Port GPIO-A
		GPIOA->CRL |= 0b1000; //Setting Port A's pin 0 as input - PA0 -> Input
		//IDR register is used to check the input pin status 
		//You can run loop to check the status of PA0 if(GPIOA->IDR & 0x1) which says if IDR0 is 1 then write any statement which you want to do
		GPIOA->CRL |= 0x30; //set the Pin-1 of GPIOA as output check reference manual
		//Now just like IDR for input ODR is there which is Output data register
		GPIOA->ODR |= 0x2; //Set the PinA to HIGH
		
		*/
}
