#include <cs50.h>
#include <stdio.h>

int main(void)
{

     while (true)
     {
        int a = get_int("Please Enter Height , 1 to 9 (Enter 0 or a negative value to exit): ");

        if (a <= 0 || a > 8)
        {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        else
        {

            for (int i = 1; i <= a; i++)
            {
                for (int space = (a - i); space >= 0; space--)
                {
                    printf(" ");
                }
                for (int j = 1; j <= i; j++)
                {
                    printf("#");
                }



                for (int space = 1; space >= 0; space--)
                {
                    printf(" ");
                }
                for (int j = 1; j <= i; j++)
                {
                    printf("#");
                }

                printf("\n");

            }

        }



    }
    return 0;

}