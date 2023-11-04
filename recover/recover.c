#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//######################################

#define BLOCKSIZE 512
#define FILENAME_LENGTH 8

//#######################################

int main(int argc, char *argv[1])
{
    if (argc != 2)
    {
        printf("Error: Enter one address.\n");
        return 1;
    }

    //####

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Error: Could not open image. Please try again.\n");
        return 1;
    }

    //####

    char jpeg_filename[FILENAME_LENGTH];

    int jpeg_count = 0;

    FILE *outfile = NULL;

    unsigned char buffer[BLOCKSIZE];

    //####

    while (fread(buffer, 1, BLOCKSIZE, file) == BLOCKSIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {

            if (outfile != NULL)
            {
                fclose(outfile);
            }

            sprintf(jpeg_filename, "%03d.jpg", jpeg_count);
            jpeg_count++;

            outfile = fopen(jpeg_filename, "w+");

            if (outfile == NULL)
            {
                fclose(file);
                printf("Error: Could not create image\n");
                return 1;
            }
        }

        //####

        if (outfile != NULL)
        {

            if (fwrite(buffer, 1, BLOCKSIZE, outfile) != BLOCKSIZE)
            {
                fclose(outfile);
                fclose(file);
                printf("Error writing file");
                return 1;
            }
        }
    }

    //##################

    if (outfile != NULL)
    {
        fclose(outfile);
    }

    if (ferror(file))
    {
        fclose(file);
        printf("Error reading file");
        return 1;
    }

    fclose(file);
    return 0;
}
