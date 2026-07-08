#include <stdio.h>
#include <cs50.h>

void count_change(int num);
int get_valid_int();

int main(void) {
    count_change(get_valid_int());

}

void count_change(int num) {
    int count = 0;
    if (num >= 25) {
        count += num/25;
        num = num % 25;
    }
    if(num >= 10) {
        count += num/10;
        num = num % 10;
    }
    if(num >= 5) {
        count += num/5;
        num = num % 5;
    }
    if(num >= 1) {
        count += num;
    }

    printf("%d\n", count);
}

int get_valid_int() {
    int num;
    do {
        num = get_int("Change owed: ");
    } while(num < 0);

    return num;
}
