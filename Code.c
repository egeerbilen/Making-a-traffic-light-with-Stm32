#include "stm32f10x.h"

int main()
{
	RCC->APB2ENR |= (1 << 2);
	GPIOA->CRL |= ((1 << 5));
	GPIOA->CRL &= ~((1 << 4) | (1 << 7) | (1 << 6));
	GPIOA->CRL |= ((1 << 9));
	GPIOA->CRL &= ~((1 << 8) | (1 << 10) | (1 << 11));
	GPIOA->CRL |= ((1 << 13));
	GPIOA->CRL &= ~((1 << 12) | (1 << 14) | (1 << 15));

	while (1)
	{
		GPIOA->ODR |= (1 << 1);
		for (int j = 0; j < 27000000; j++)
			;
		GPIOA->ODR |= (1 << 2);

		for (int j = 0; j < 3000000; j++)
			;
		GPIOA->ODR &= ~(1 << 1);
		GPIOA->ODR &= ~(1 << 2);

		GPIOA->ODR |= (1 << 3);
		for (int j = 0; j < 15000000; j++)
			;
		GPIOA->ODR &= ~(1 << 3);

		GPIOA->ODR |= (1 << 2);
		for (int j = 0; j < 3000000; j++)
			;
		GPIOA->ODR &= ~(1 << 2);
	}
}
