#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#define ALPHABET_SIZE 26
void generateKey(int key[], int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        key[i] = rand() % ALPHABET_SIZE;
}
void encrypt(char text[], int key[], char result[]) {
    for (int i = 0; text[i]; i++) {
        result[i] = isalpha(text[i]) ? (text[i] + key[i] - (isupper(text[i]) ? 'A' : 'a')) % ALPHABET_SIZE + (isupper(text[i]) ? 'A' : 'a') : text[i];
    }
    result[strlen(text)] = '\0';
}
int main() {
    char plaintext[] = "Hello, World!";
    int len = strlen(plaintext), key[len];
    char ciphertext[len + 1];
    generateKey(key, len);
    encrypt(plaintext, key, ciphertext);
    printf("Plaintext: %s\nKey: ", plaintext);
    for (int i = 0; i < len; i++) printf("%d ", key[i]);
    printf("\nCiphertext: %s\n", ciphertext);
    return 0;
}
Output:
Plaintext: Hello, World!
Key: 10 24 10 6 8 8 1 18 19 18 5 12 23
Ciphertext: Rcvrw, Ohjqp!
