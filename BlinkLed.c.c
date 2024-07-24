

#include <stdint.h>



void delay();
void gpio_init();
uint32_t* AHB1ENR=(uint32_t)0x40023830;//Declaring AHB1 register through RCC
uint32_t* GPIOA_MODER=(uint32_t)0x40020000;//Declaring GPIOA moder register
uint32_t* GPIOA_ODR=(uint32_t)0x40020014 ;//Declaring GPIOA ODR register


int main(void)
{
	gpio_init();
   while(1){
	   *GPIOA_ODR |=(1<<5);
	   delay();
	   *GPIOA_ODR &= ~(1<<5); // Turn LED off (clear PA5)
	   delay();

   }

}
void gpio_init(){
	*AHB1ENR |=(1<<0);
	*GPIOA_MODER &=~(1<<11);
	*GPIOA_MODER |= (1<<10);

}
void delay()
{
    int count;

    for(count = 0; count < 500000; count++) {
        // This empty loop will create a delay, you might need to adjust this
    }
}
