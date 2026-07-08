#include <cs50.h>
#include <stdio.h>

//func prototype
long get_credit_num();
int count_digit(long num);
int get_first_num(long num);
bool checksum(long credit);


int main(void) {
    long creditNum = get_credit_num();
    int digit = count_digit(creditNum);
    int firstNum = get_first_num(creditNum);
    bool isValid = checksum(creditNum);


    if (isValid) {
        if (digit == 15 && (firstNum == 34 || firstNum == 37)) {  //AMEX
            printf("AMEX\n");
        } else if (digit == 16 && (firstNum >= 51 && firstNum <= 55)) {  // MASTERCARD
            printf("MASTERCARD\n");
        } else if ((digit == 13 || digit == 16) && firstNum/10 == 4) {  //VISA
            printf("VISA\n");
        }  else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }

    return 0;
}

long get_credit_num() {
    long num = get_long("Number: ");
    return num;
}

int count_digit(long num) {
    int counter = 0;
    while(num > 0) {
        num /= 10;
        counter++;
    }
    return counter;
}

int get_first_num(long num) {
    while(num > 99) {
        num /= 10;
    }
    return num;
}

bool checksum(long credit) {
    int counter = 0;
    int total = 0;
    int temp = 0 ;
    while(credit > 0) {
        if(counter % 2 == 0) {
            total += credit % 10;
        } else {
            temp = (credit % 10) * 2;
            if(temp > 9) {
                total += temp % 10;
                total += temp / 10;
            } else {
                total += temp;
            }
        }
        counter++;
        credit /= 10;
    }
    if (total % 10 == 0) {
        return true;
    }
    return false;

}
