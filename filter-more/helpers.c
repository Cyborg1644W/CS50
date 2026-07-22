#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = 0;
            avg += image[i][j].rgbtBlue;
            avg += image[i][j].rgbtGreen;
            avg += image[i][j].rgbtRed;

            avg = (avg + 1) / 3;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        int tempBlue = 0;
        int tempGreen = 0;
        int tempRed = 0;
        for (int j = 0, half = width / 2; j < half; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //copy image
    RGBTRIPLE duplicated[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            duplicated[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalBlue = 0;
            int totalGreen = 0;
            int totalRed = 0;
            int counter = 0;

            for (int r = i - 1; r <= i + 1; r++)
            {
                for(int c = j - 1; c <= j + 1; c++)
                {
                    if (r >= 0 && c >= 0 && r < height && c < width)
                    {
                        counter++;
                        totalBlue += duplicated[r][c].rgbtBlue;
                        totalGreen += duplicated[r][c].rgbtGreen;
                        totalRed += duplicated[r][c].rgbtRed;
                    }
                }
            }
        image[i][j].rgbtBlue = (totalBlue + counter / 2) / counter;
        image[i][j].rgbtGreen = (totalGreen + counter / 2) / counter;
        image[i][j].rgbtRed = (totalRed + counter / 2) / counter;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalX = 0;
            int totalY = 0;
        }
    }
    return;
}
