#include "stm32f10x.h"
#include "delay_ms.h"
#define PC13_ON CLEAR_BIT(GPIOC->ODR,GPIO_ODR_ODR13)
#define PC13_OFF SET_BIT(GPIOC->ODR,GPIO_ODR_ODR13)
#define PA0_ON SET_BIT(GPIOA->ODR,GPIO_ODR_ODR0)
#define PA0_OFF CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR0)
#define PA1_ON SET_BIT(GPIOA->ODR,GPIO_ODR_ODR1)
#define PA1_OFF CLEAR_BIT(GPIOA->ODR,GPIO_ODR_ODR1)
//----------------------------------------------------------

		
	int main (void) {
			
				
			//RCC->APB2RSTR  ;
			RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
			RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
				
			GPIOC->CRH &= ~GPIO_CRH_CNF13;
			GPIOC->CRH |= GPIO_CRH_MODE13_0;
				
			GPIOA->CRL &= ~GPIO_CRL_CNF0;
			GPIOA->CRL |= GPIO_CRL_MODE0_0;
			GPIOA->CRL &= ~GPIO_CRL_CNF1;
			GPIOA->CRL |= GPIO_CRL_MODE1_0;
			
		
	while(1)
	{
		
	  PC13_ON;
		delay_ms(400);
		PA0_ON;
		PC13_OFF;
		delay_ms(400);
		PA1_ON;
		PA0_OFF;	
		delay_ms(400);
	
		PA1_OFF;
		
	}
	}
