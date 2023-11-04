#include <stdio.h>
#include <cs50.h>

// Function to validate a credit card number using Luhn's algorithm
bool isLuhnValid(const string cardNumber) {
    int sum = 0;
    int numDigits = 0;
    bool isSecondDigit = false;

    // Calculate the length of the cardNumber
    while (cardNumber[numDigits] != '\0') {
        numDigits++;
    }

    // Traverse the card number from right to left
    for (int i = numDigits - 1; i >= 0; i--) {
        char c = cardNumber[i];

        // Ignore non-digit characters
        if (c < '0' || c > '9') {
            continue;
        }

        // Convert character to integer
        int digit = c - '0';

        // Double every second digit from the right
        if (isSecondDigit) {
            digit *= 2;

            // If the doubled digit is greater than 9, sum its digits
            if (digit > 9) {
                digit = digit / 10 + digit % 10;
            }
        }

        // Add the current digit to the sum
        sum += digit;
        isSecondDigit = !isSecondDigit;
    }

    // The number is valid if the sum is divisible by 10 and there are more than 1 digits
    return numDigits > 1 && sum % 10 == 0;
}
int numDigits;
int main(void)
{
    string cardNumber = get_string("Enter your credit card number: ");


   if (isLuhnValid(cardNumber)) {
      if (numDigits == 15 && (cardNumber[0] == '3' && (cardNumber[1] == '4' || cardNumber[1] == '7'))) {
          printf("AMEX\n");
      } else if (numDigits == 16 && (cardNumber[0] == '5' && (cardNumber[1] >= '1' && cardNumber[1] <= '5'))) {
          printf("MASTERCARD\n");
      } else if ((numDigits == 13 || numDigits == 16) && cardNumber[0] == '4') {
          printf("VISA\n");
      } else {
          printf("INVALID\n");
      }
}
  else
  {
      printf("Invalid credit card number!\n");
  }


    return 0;
}
