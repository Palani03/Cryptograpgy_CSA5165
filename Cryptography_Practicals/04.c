// Write a C program for polyalphabetic substitution cipher uses a separate 
// monoalphabetic substitution cipher for each successive letter of plaintext. 
// depending on a key.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];
    int i, j = 0, keyLength, textLength;

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove newline character

    // Input the key
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline character

    // Calculate the lengths of the text and the key
    textLength = strlen(plaintext);
    keyLength = strlen(key);

    // Convert key to uppercase
    for (i = 0; i < keyLength; i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt the plaintext
    for (i = 0; i < textLength; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            char keyChar = toupper(key[j % keyLength]) - 'A';  // Calculate the shift using the key

            ciphertext[i] = ((plaintext[i] - base + keyChar) % 26) + base;
            j++;
        } else {
            ciphertext[i] = plaintext[i];  // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0';  // Null-terminate the ciphertext string

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
