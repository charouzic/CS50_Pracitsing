#include <stdio.h>
#include <cs50.h>

int main(void)
{


    long cardNumber;
    do
    {
        cardNumber = get_long("Number: ");
    }
    while(cardNumber/1000000000%10==0);
    // accessing the last number => cardNumber % 10

    long i;
    long j = 1;
    int checkSum = 0;


    // getting every other digit starting from the end
    for (i = 10; i <= 10000000000000000; i = i*100)
    {
        if ((cardNumber/i%10)*2 >= 10)
        {
            checkSum += (cardNumber/i%100)*2 % 10;
            printf("%li\n", (cardNumber/i%100)*2 % 10);

            checkSum += ((cardNumber/i%10)*2)/10 % 10;
            printf("%li\n", ((cardNumber/i%10)*2)/10 % 10);
        }
        else
        {
            checkSum += (cardNumber/i%10)*2;
        }

    }
    // getting the other numbers
    do
    {
        checkSum += cardNumber/j%10;
        printf("%li\n", cardNumber/j%10);

        j = j*100;
    }
    while(j <= 1000000000000000);


    if (checkSum%10 == 0)
    {
        if (cardNumber/10000000000000%100 == 34 || cardNumber/10000000000000%100 == 37)
        {
            printf("AMEX\n");
        }
        else if (cardNumber/100000000000000%100 >= 51 && cardNumber/100000000000000%100 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (cardNumber/1000000000000%10 == 4 || cardNumber/1000000000000000%10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
        {
            printf("INVALID\n");
        }
}
