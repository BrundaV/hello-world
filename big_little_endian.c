/* FILE NAME : big_little_endian.c
*  DESCRIPTION : Program to check whether the machine on which this code runs is little endian or big endian
*  and convert it into big endian if it is little endian and vive-versa.
*  CREATED BY : Brunda V
*  Emp ID : 213448
*/

/*--------------Includes------------------------------------*/
#include<stdio.h>
#include<stdint.h>

/*--------------Public Functions----------------------------*/
void endian_conv(void);

/*---------------Global variables-------------------------- */
uint32_t b0,b1,b2,b3
int x=0x320a10ca,conv_x;
unsigned char *c=(unsigned char *)&x;

/*-------------Main function--------------------------------*/
int main()
{
    int i;
    // printing all the elements of character array formed by converting int x to char array
    for(i=0;i<sizeof(c);i++)
    {
        printf("%02x ",c[i]);
    }

    //if((0x00000011&c[0])==(x&0x11000000))-for just char

     printf("\n Endianness of the machine : ");

     // checking for the endianness of the machine
    if(c[0]==(x&0x000000ff))
        {printf("Little endian");}
    else
        {printf("Big endian"); }

    // Function to convert the machine into big endian if it is little endian and vive-versa.
    endian_conv();

    return 0;
}

// endian_conv() function definition
void endian_conv()
{
    //generating byte-reversed x
        b0=(x & 0x000000ff)<<24u;
        b1=(x & 0x0000ff00)<<8u;
        b2=(x & 0x00ff0000)>>8u;
        b3=(x & 0xff000000)>>24u;
        conv_x=b0|b1|b2|b3;
        printf("\n The initial value of x : %x",x);
        int temp=c[0];

        // storing byte reversed value of x into the memory where x is stored
        *(&x)=conv_x;
        printf("\n The new value stored : %x",x);

        printf("\n Endianness after conversion : ");

    // Checking if the machine is endian converted
        if(temp==(conv_x&0x000000ff))
            {printf("Little endian\n");}
        else
            {printf("Big endian\n"); }

}
