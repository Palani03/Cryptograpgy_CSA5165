// Write a C program for Playfair algorithm is based on the use of a 5 X 5 matrix 
// of letters constructed using a keyword. Plaintext is encrypted two letters at 
// a time using this matrix.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

int main() {
    char key[100], text[100];
    char matrix[SIZE][SIZE];
    int alphabets[26] = {0};  // Array to keep track of letters already used
    int i, j, k, index = 0;

    // Input the keyword
    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline character

    // Combine 'I' and 'J'
    alphabets['J' - 'A'] = 1;

    // Fill the matrix with the key
    for (k = 0; key[k] != '\0'; k++) {
        char c = toupper(key[k]);
        if (c < 'A' || c > 'Z' || alphabets[c - 'A']) continue;  // Skip non-letters or already added letters
        matrix[index / SIZE][index % SIZE] = c;
        alphabets[c - 'A'] = 1;
        index++;
    }

    // Fill the matrix with the remaining letters
    for (i = 0; i < 26; i++) {
        if (alphabets[i] == 0) {
            matrix[index / SIZE][index % SIZE] = 'A' + i;
            index++;
        }
    }

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline character

    // Preprocess the plaintext
    int len = strlen(text);
    char processedText[100];
    int pIndex = 0;

    for (i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            processedText[pIndex++] = toupper(text[i]);
        }
    }
    processedText[pIndex] = '\0';

    // Insert 'X' between repeated characters in pairs
    for (i = 0; i < pIndex; i += 2) {
        if (processedText[i] == processedText[i+1]) {
            memmove(&processedText[i+1], &processedText[i], pIndex - i + 1);
            processedText[i+1] = 'X';
            pIndex++;
        }
    }

    // If the length of processedText is odd, add an 'X' at the end
    if (pIndex % 2 != 0) {
        processedText[pIndex++] = 'X';
        processedText[pIndex] = '\0';
    }

    // Encrypt the processed text
    for (i = 0; i < pIndex; i += 2) {
        int row1, col1, row2, col2;

        // Find positions of the first letter in the matrix
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (matrix[j][k] == processedText[i]) {
                    row1 = j;
                    col1 = k;
                }
                if (matrix[j][k] == processedText[i+1]) {
                    row2 = j;
                    col2 = k;
                }
            }
        }

        // Apply Playfair cipher rules
        if (row1 == row2) {
            // Same row, shift right
            processedText[i] = matrix[row1][(col1 + 1) % SIZE];
            processedText[i+1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            // Same column, shift down
            processedText[i] = matrix[(row1 + 1) % SIZE][col1];
            processedText[i+1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            // Rectangle swap
            processedText[i] = matrix[row1][col2];
            processedText[i+1] = matrix[row2][col1];
        }
    }

    // Output the ciphertext
    printf("Ciphertext: %s\n", processedText);

    return 0;
}
