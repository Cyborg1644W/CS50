#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

void counter(string text, int *c_letter, int *c_word, int *c_sentence);
void calculate_index(float letter_count, float word_count, float sentence_count);

int main(void) {
    int letter_count = 0;
    int word_count = 1;
    int sentence_count = 0;
    string user_text;

    do {
        user_text = get_string("Text: ");
    } while (user_text == NULL);

    counter(user_text, &letter_count, &word_count, &sentence_count);
    calculate_index(letter_count, word_count, sentence_count);
}

void counter(string text, int *c_letter, int *c_word, int *c_sentence) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            (*c_letter)++;
        }
        else if (text[i] == ' ') {
            (*c_word)++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            (*c_sentence)++;
        }
    }
}

void calculate_index(float letter_count, float word_count, float sentence_count) {

    float L = (letter_count / word_count) * 100;
    float S = (sentence_count / word_count) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index > 16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %.0f\n", index);
    }
}
