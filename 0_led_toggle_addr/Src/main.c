//Where is the LED connected?
//Port: A
//Pin: 5

#define PERIPH_BASE				(0x40000000UL)
#define AHB1PERIPH_OFFSET		(0x00020000UL)
#define AHB1PERIPH_BASE			(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET			(0x0000UL)	// 0x 0000 0000

#define GPIOA_BASE 				(AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET			(0X30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET			(0X00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))
#define OD_R_OFFSET				(0x14UL)
#define GPIOA_0D_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))


#define GPIOAEN					(1U<<0) //	0b 0000 0000 0000 0000 0000 0000 0000 0001


#define PIN5					(1U<<5)
#define LED_PIN					PIN5


//set pin 10 to 1 and pin 11 to 0
/*
 * (1UL<<10) 	// Sets bit 10 to 1
 * &=~(1UL<<11)	// Sets bit 11 and only bit 11 to 0
 * */

/* rcc_ahb1enr reg = 0b 0000 0000 0000 0000 0001 1111 0000 0000 -> 	original value
 * 																	we don't want to wipe
 * rcc_ahb1enr reg = 0b 0000 0000 0000 0000 0000 0000 0000 0001 ->  all previous bits
 *
 *
 * rcc_ahb1enr reg |= 0b 0000 0000 0000 0000 0001 1111 0000 0001 -> this is what we want
 * */

int main(void)
{
	/* 1. Enable clock access to GPIOA */
	RCC_AHB1EN_R |= GPIOAEN;	// "|" is the OR operator -> no bit besides bit 1 changes

	/* 2. Set PA5 as output pin*/
	GPIOA_MODE_R |=  (1UL<<10); 	// Sets bit 10 to 1
	GPIOA_MODE_R &=~ (1UL<<11);		// Sets bit 11 and only bit 11 to 0

	while(1)
	{
		/*5. Experiment 3: toggle PA5 (blinking LED)*/
		GPIOA_0D_R ^= LED_PIN;
		for(int i = 0; i < 100000; i++){}
	}
}
