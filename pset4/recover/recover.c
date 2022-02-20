#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // make sure the user typed one line argment.
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    //open the memory card and make sure thar we got a valid pointer back.
    FILE *imgfile = fopen(argv[1], "r");
    if (imgfile == NULL)
    {
        fprintf(stderr, "Can't open file\n");
        return 2;
    }
    //aloccate a memory to store the image & make sure we got valid pointer.
    BYTE *image = malloc(sizeof(BYTE) * 512);
    if (image == NULL)
    {
        fprintf(stderr, "Can't allocate memory\n");
        fclose(imgfile);
        return 3;
    }
    //count the number of files we opened.
    int count = 0;
    // allocate a momery of size 3 chars for image name.
    char *s = malloc(sizeof(char));
    // used to name the images files ###.jpg where ### is three digit intger.
    sprintf(s, "%03i.jpg", count);
    //open a file to write an image in it & make sure we got valid pointer back.
    FILE *newimg = fopen(s, "w");
    if (newimg == NULL)
    {
        fprintf(stderr, "Can't allocate file for image\n");
        free(image);
        fclose(imgfile);
        return 4;
    }

    //check if we reached the end of the file.
    while (fread(image, sizeof(BYTE), 512, imgfile) >= 512)
    {
        // make sure it is jpeg.
        if (image[0] == 0xff && image[1] == 0xd8 && image[2] == 0xff && ((image[3] & 0xe0) == 0xe0))
        {
            //if it is the first jpeg we read.
            if (count == 0)
            {
                fwrite(image, sizeof(BYTE), 512, newimg);
                count++;
            }
            else
            {
                fclose(newimg);
                sprintf(s, "%03i.jpg", count);
                newimg = fopen(s, "w");
                fwrite(image, sizeof(BYTE), 512, newimg);
                count++;
            }
        }
        else
        {
            if (count > 0)
            {
                fwrite(image, sizeof(BYTE), 512, newimg);
            }

        }
    }
    fclose(newimg);
    fclose(imgfile);
    free(image);
    free(s);
    return 0;
}
