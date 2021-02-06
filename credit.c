#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Prototype.
int summer(long num);

int main(void)
{
    // Take card number.
    long entry = get_long("Please enter your card number. (Numbers only)\n");
    // Set aside memory/name for string representation of number.
    char str_entry[255];
    // Read number into str_entry.
    sprintf(str_entry, "%ld", entry);

    // If it's divisible by 10,
    if (summer(entry) % 10 == 0)
    {
        // starts with a 4, and has length of 13 or 16,
        if (str_entry[0] == '4' && 
            (strlen(str_entry) == 13 || 
             strlen(str_entry) == 16))
        {
            printf("VISA\n");
        }
        // or starts with 34 or 37, with length 15,
        else if (str_entry[0] == '3' && 
                 strlen(str_entry) == 15)
        {
            if (str_entry[1] == '4' || 
                str_entry[1] == '7')
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        // or starts anywhere from 51 through 55, 
        // with length 16, then print appropriate card.
        else if (str_entry[0] == '5' && 
                 strlen(str_entry) == 16)
        {
            if (str_entry[1] == '1' || 
                str_entry[1] == '2' || 
                str_entry[1] == '3' || 
                str_entry[1] == '4' || 
                str_entry[1] == '5')
            {
                printf("MASTERCARD\n");
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
    // Otherwise, it's invalid.
    else
    {
        printf("INVALID\n");
    }

    return 0;
}

int summer(long num)
// Adds last number to sum, doubling every other
// number, starting with second to last,
// then removes last number till none left.
{
    int sum = 0, i = 0, n;

    // While num above 0,
    while (num)
    {
        // if placeholder, i, is even,
        if (i % 2 == 0)
        {
            // add directly to sum.
            sum += num % 10;
        }
        else
        {
            // Otherwise double last num,
            n = (num % 10) * 2;
            while (n)
            {
                // and add final digits to sum.
                sum += n % 10;
                n /= 10;
            }
        }
        
        // Remove last number from num, increment placeholder.
        num /= 10;
        i++;
    }

    return sum;
}
