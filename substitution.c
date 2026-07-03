#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void check_valid(string text);
void cypher_text(string key, string text);

int main(int argc, string argv[]) {
    string plainText;

    if(argc != 2) {
        printf("Usage: ./substitution KEY\n");
        return 1;
    } else if(strlen(argv[1]) != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    check_valid(argv[1]);

    do {
        plainText = get_string("plaintext: ");
    } while(plainText == NULL);

    cypher_text(argv[1], plainText);
}

void check_valid(string key) {
    int seen[26] = {0};

    for(int i = 0; i < 26; i++) {

        if(isalpha(key[i]) == 0) {
            printf("Key must only contain alphabetic characters.\n");
        }
        if(key[i] >= 'a' && key[i] <= 'z') {
            if (seen[key[i] - 'a'] != 1) {
                seen[key[i] - 'a'] = 1;
            } else {
                printf("Key must not contain repeated characters.\n");
            }
        } else if (key[i] >= 'A' && key[i] <= 'Z') {
            if (seen[key[i] - 'A'] != 1) {
                seen[key[i] - 'A'] = 1;
            } else{
                printf("Key must not contain repeated characters.\n");
            }
        }
    }
}

void cypher_text(string key, string text) {
    printf("ciphertext: ");
    for(int i = 0; text[i] != '\0'; i++) {
        if(isupper(text[i])) {
            printf("%c", key[text[i] - 'A']);
        } else if(islower(text[i])) {
            printf("%c", key[text[i] - 'a'] + 32);
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
