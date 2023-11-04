// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//#####################################

#define BLOCKSIZE 16

int16_t buffer[BLOCKSIZE];

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

//#####################################

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    //####

    // TODO: Copy header from input file to output file

    uint8_t header[HEADER_SIZE];

    fread(header, 1, HEADER_SIZE, input);
    fwrite(header, 1, HEADER_SIZE, output);

    //####

    while (fread(buffer, sizeof(int16_t), BLOCKSIZE, input) == BLOCKSIZE)
    {
        for (int i = 0; i < BLOCKSIZE; i++)
        {
            buffer[i] = (int16_t) (buffer[i] * factor);
        }

        fwrite(buffer, sizeof(int16_t), BLOCKSIZE, output);
    }

    fclose(input);
    fclose(output);
}
