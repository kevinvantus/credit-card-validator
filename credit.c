#include <stdio.h>
#include <cs50.h>

int getSumOfProductsDigits(long number);
int getSumOfDigitsNotMultiplied(long number);
void checkValidity(int cv);
void checkCardType(long number, int check);

int main(void)
{
    // Prompt user for credit card number
    long cardNumber = get_long("Card Number: ");

    int sumOfProductsDigits = getSumOfProductsDigits(cardNumber);
    //printf("\nSum of products digits: %i\n", sumOfProductsDigits);

    int sumOfDigitsNotMultiplied = getSumOfDigitsNotMultiplied(cardNumber);
    //printf("\nSum of digits not multiplied: %i\n", sumOfDigitsNotMultiplied);

    int checksum = sumOfProductsDigits + sumOfDigitsNotMultiplied;
    //printf("Checksum: %i\n", checksum);

    // checkValidity(checksum);

    // Check whether card is Visa, MasterCard, or American Express and card validity
    checkCardType(cardNumber, checksum);
}


// Add all the digits of the products together
int getSumOfProductsDigits(long number)
{
    int digits, sumOfDigits = 0, twiceDigits;

    // Calculate checksum
    while (number > 0)
    {
        digits = (number % 100) / 10;

        twiceDigits = digits * 2;

        if(twiceDigits >= 10)
        {
            twiceDigits = (twiceDigits / 10) + (twiceDigits % 10);
        }

        // Add products digits together
        sumOfDigits += twiceDigits;

        // Multiply each digit by 2
        //printf("%i ", twiceDigits);

        number = number / 100;
    }

    return sumOfDigits;
}

int getSumOfDigitsNotMultiplied(long number)
{
    int digits, sum = 0;

    while(number > 0)
    {
        digits = number % 10;

        if(digits >= 10)
        {
            digits = (digits / 10) + (digits % 10);
        }

        //printf("%i ", digits);

        sum += digits;

        number = number / 100;
    }
    return sum;
}

// Check for card validity
// void checkValidity(int cv)
// {
//     if(cv % 10 == 0)
//     {
//         printf("VALID\n");
//     }
//     else
//     {
//         printf("INVALID\n");
//     }
// }

//(number >= 370000000000000))
void checkCardType(long number, int check)
{
    bool isValid = (check % 10 == 0);
    int amex34 = ((number >= 340000000000000) && (number < 350000000000000));
    int amex37 = ((number >= 370000000000000) && (number < 380000000000000));
    int master = ((number >= 5100000000000000) && (number < 5600000000000000));
    int visa13 = ((number >= 4000000000000) && (number < 5000000000000));
    int visa16 = ((number >= 4000000000000000) && (number < 5000000000000000));

    if((amex34 || amex37) && isValid)
    {
        printf("AMEX\n");
    }
    else if((visa13 || visa16) && isValid)
    {
        printf("VISA\n");
    }
    else if(master && isValid)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}