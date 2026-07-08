#include <cs50.h>
#include <stdio.h>
#include <string.h>

int get_value(string word,int values[]);

int main(void) {
    int scrabble[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = get_value(word1, scrabble);
    int score2 = get_value(word2, scrabble);

    if(score1 > score2) {
        printf("Player 1 wins!\n");
    } else if(score1 < score2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }
}

// 97 - 122(a-z),   65-90 (A-Z)
int get_value(string word,int values[]) {
    int points = 0;
    for(int i = 0, length = strlen(word); i < length; i++) {
        if (word[i] >= 97 && word[i] <= 122) {
            points += values[word[i] - 97];
        } else if((word[i] >= 65 && word[i] <= 90)) {
            points += values[word[i] - 65];
        }
    }

    return points;
}
