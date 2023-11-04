#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
int length;
int vocab;
int sentences;
int index;
float L;
float S;

int main()
{
    char *paragraph = get_string("Enter your text: ");

    int l = 0;
    int v = 1;
    int s = 0;

    for (int i = 0; paragraph[i] != '\0'; i++)
    {

        if (isalpha(paragraph[i]))
        {
            l++;
        }

        else if (paragraph[i] == ' ')
        {
            v++;
        }

        else if (paragraph[i] == '.' || paragraph[i] == '!' || paragraph[i] == '?')
        {
           s++;
        }
    }

    length = l;
    vocab = v;
    sentences = s;

    L = 100.00 * (length /(float) vocab);
    S = 100.00 * (sentences /(float) vocab);

    index = round(0.0588 * L - 0.296 * S - 15.8);

    int n = index;

    if (n < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (n >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n" , n);
    }

}




