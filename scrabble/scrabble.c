#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int n = strlen(word1);
    int m = strlen(word2);

    for (int i = 0; i < n; i++)

    {
        word1[i] = toupper(word1[i]);
    }

    for (int i = 0; i < m; i++)

    {
        word2[i] = toupper(word2[i]);
    }

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)

    {
        printf("Player 1 Wins!...\n");
    }

    else if (score1 < score2)

    {
        printf("Player 2 Wins!...\n");
    }

    else

    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(string word)

{
    int sum = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        int index = word[i] - 'A';
        if (index >= 0 && index < 26)
        {
            sum += POINTS[index];
        }
    }

    return sum;
}
