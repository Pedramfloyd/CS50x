#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int get_cents(void);

int get_cents(void)
{
    int cents;

    do
    {
        cents = get_int("how many cents the customer is owed ?");
    }
    while (cents <= 0);
    return cents;
}

int main(void)
{
    int cents = get_cents();
    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    int coins = quarters + dimes + nickels + pennies;

    printf("All Coins:%i\n", coins);
    return 0;
}

int calculate_quarters(int cents)
{
    int quarters = 0;

    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    return quarters;
}

int calculate_dimes(int cents)
{
    int dims = 0;

    while (cents >= 10)
    {
        dims++;
        cents = cents - 10;
    }
    return dims;
}

int calculate_nickels(int cents)
{
    int nickels = 0;

    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;

    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
