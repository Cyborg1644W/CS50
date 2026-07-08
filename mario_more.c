#include <cs50.h>
#include <stdio.h>

// constants
#define MIN_HEIGHT 1
#define MAX_HEIGHT 8

// prototype
int get_height();
void display_pyramid(int size);

int main(void)
{
    int height = get_height();
    display_pyramid(height);

    return 0;
}

int get_height()
{
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < MIN_HEIGHT || height > MAX_HEIGHT);
    return height;
}

void display_pyramid(int size)
{
    int counter = 1; //

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - counter; j++)
        { // space
            printf(" ");
        }
        for (int j = 0; j < counter; j++)
        { // left hashes
            printf("#");
        }

        printf("  "); // middle

        for (int j = 0; j < counter; j++)
        { // rigt hashes
            printf("#");
        }
        counter++;
        printf("\n");
    }
}
