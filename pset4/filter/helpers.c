#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



// Convert image to grayscale
//added 2 to the row array to prevent runtime error.
void grayscale(int height, int width, RGBTRIPLE image[height + 2][width])
{
    if (height == -1)
    {
        return;
    }

    grayscale(height - 1, width, image);

    //loop Through the intrnal array and change the falue of each pixle.
    for (int i = 0; i < width; i++)
    {
        float x = image[height][i].rgbtBlue + image[height][i].rgbtGreen + image[height][i].rgbtRed;
        int avg = round(x / 3);
        image[height][i].rgbtBlue = avg;
        image[height][i].rgbtGreen = avg;
        image[height][i].rgbtRed = avg;
    }

    return;
}

// Reflect image horizontally
//added 2 to height to prevent runtime error.
void reflect(int height, int width, RGBTRIPLE image[height + 2][width])
{
    if (height == -1) 
    {
        return;
    }

    reflect(height - 1, width, image);

    //added 2 to height to prevent runtime error.
    RGBTRIPLE(*temp)[width] = calloc(height + 2, width * sizeof(RGBTRIPLE));
    //make sure that we got a valid pointer back.
    if (temp == NULL)
    {
        fprintf(stderr, "Not enough memory to store temp.\n");
        return;
    }

    for (int j = width - 1; j >= 0; j--)
    {
        temp[height][(width - 1) - j] = image[height][j];
    }
    for (int j = 0; j < width; j++)
    {
        image[height][j] = temp[height][j];
    }
    free(temp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*temp)[width] = calloc(height, sizeof(RGBTRIPLE) * width);
    if (temp == NULL)
    {
        fprintf(stderr, "Not enough memory to store temp.\n");
        return;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float x[3] = {0, 0, 0};
            int count = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int n = j - 1; n <= j + 1; n++)
                {
                    count++;
                    // condition if it is out side the boundries of the image
                    if (k < 0 || k > height - 1 || n < 0 || n > width - 1)
                    {
                        count--;
                    }
                    else
                    {
                        x[0] += temp[k][n].rgbtBlue;
                        x[1] += temp[k][n].rgbtGreen;
                        x[2] += temp[k][n].rgbtRed;
                    }


                }
            }
            image[i][j].rgbtBlue = round(x[0] / count);
            image[i][j].rgbtGreen = round(x[1] / count);
            image[i][j].rgbtRed = round(x[2] / count);
        }
    }
    free(temp);
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // to make temp... place to store all the content of image in it.
    RGBTRIPLE(*temp)[width] = calloc(height, sizeof(RGBTRIPLE) * width);
    if (temp == NULL)
    {
        fprintf(stderr, "Not enough memory to store temp.\n");
        return;
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    
    //the kernels of wich we use to modify the image
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // x and y to store all the values after * by Gx and Gy.
            float x[3] = {0, 0, 0};
            float y[3] = {0, 0, 0};
            int count = 9;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int n = j - 1; n <= j + 1; n++)
                {
                    if (k < 0 || n < 0 || k > height - 1 || n > width - 1)
                    {
                        for (int p = 0; p < 3; p++)
                        {
                            x[p] += 0;
                        }
                        for (int p = 0; p < 3; p++)
                        {
                            y[p] += 0;
                        }
                    }
                    else
                    {
                        // 0 for Blue , 1 for Green and 2 for Red.
                        x[0] += (Gx[k - (i - 1)][n - (j - 1)] * temp[k][n].rgbtBlue);
                        y[0] += (Gy[k - (i - 1)][n - (j - 1)] * temp[k][n].rgbtBlue);

                        x[1] += (Gx[k - (i - 1)][n - (j - 1)] * temp[k][n].rgbtGreen);
                        y[1] += (Gy[k - (i - 1)][n - (j - 1)] * temp[k][n].rgbtGreen);

                        x[2] += (Gx[k - (i - 1)][n - (j - 1)] * temp[k][n].rgbtRed);
                        y[2] += (Gy[k - (i - 1)][n - (j - 1)] * temp[k][n].rgbtRed);
                    }
                }
            }
            // to store the values of the pixels
            int GXY[3];
            GXY[0] = round(sqrt((x[0] * x[0]) + (y[0] * y[0])));
            GXY[1] = round(sqrt((x[1] * x[1]) + (y[1] * y[1])));
            GXY[2] = round(sqrt((x[2] * x[2]) + (y[2] * y[2])));
            
            for (int p = 0; p < 3; p++)
            {
                if (GXY[p] > 255)
                {
                    GXY[p] = 255;
                }
            }
            //modify the pixels in the accual image.
            image[i][j].rgbtBlue = GXY[0];
            image[i][j].rgbtGreen = GXY[1];
            image[i][j].rgbtRed = GXY[2];


        }
    }

    free(temp);
    return;
}


