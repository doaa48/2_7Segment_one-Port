#include"avr/io.h"
#include"util/delay.h"
#include "BIT_MATH.h"

int main (void)
{
	/*Numbers from 0 to 9 In Hexa form*/
	int arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xFF,0x6F};


	DDRA=0xFF;
	PORTA=0x00;
	DDRD=0xFF;
	PORTD=0x00;

	while(1)
	{
		/*Dozens Part*/
		for(int j=0 ;j<10;j++)
		{

			/*Ones Part*/
			for(int i=0 ;i<10;i++)
			{
				/*delay half second to take turns with 10ms to make */
				for(int k=0;k<50;k++)
				{
						SET_BIT(PORTD,0);
						CLR_BIT(PORTD,1);
						PORTA=arr[j];
						_delay_ms(10);

						CLR_BIT(PORTD,0);
						SET_BIT(PORTD,1);
						PORTA=arr[i];
						_delay_ms(10);
				}

			}

		}


	}
	return 0;
}
