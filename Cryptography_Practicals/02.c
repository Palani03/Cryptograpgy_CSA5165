// Write a C program for monoalphabetic substitution cipher maps a plaintext 
// alphabet to a ciphertext alphabet, so that each letter of the plaintext alphabet
// maps to a single unique letter of the ciphertext alphabet.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100];
    char ciphertext[100];
    char key[27];  
    int i;
    strcpy(key, "QWERTYUIOPASDFGHJKLZXCVBNM");
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    for (i = 0; plaintext[i] != '\0'; ++i) 
        {if (isalpha(plaintext[i])) 
            {if (islower(plaintext[i])) 
                {ciphertext[i] = tolower(key[plaintext[i] - 'a']);} 
            else 
                {ciphertext[i] = key[plaintext[i] - 'A'];}} 
        else 
            {ciphertext[i] = plaintext[i];}}

    ciphertext[i] = '\0';  // Null-terminate the ciphertext string
    printf("Ciphertext: %s\n", ciphertext);
    return 0;}
