#include <cs50.h>
#include <stdio.h>
void mario(int height);

int main(void)
{

    int height;

    do
    {
        height = get_int("Please Enter Height (Enter 0 - 8): ");
    }
    while ((height < 1) || (height > 8));
    mario(height);
}

void mario(int height)
{

    for (int row = 1; row < height + 1; row++)
    {
        for (int j = 1; j < height + 1; j++)
        {
            if (j <= (height - row))
            {

                printf(" ");
            }
            else
            {

                printf("#");
            }
        }

        printf("\n");
    }
}
