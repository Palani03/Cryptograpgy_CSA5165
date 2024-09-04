// Write a C program for Caesar cipher involves replacing each letter of the alphabet with the letter
// standing k places further down the alphabet. for k in the range 1 through 25.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
    {char text[100];
    int k, i;
    char ch;
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  
    printf("Enter shift (1-25): ");
    scanf("%d", &k);
    if (k < 1 || k > 25) 
        {printf("Invalid shift value. It must be between 1 and 25.\n");
        return 1;}
    k = k % 26;
    for (i = 0; text[i] != '\0'; ++i) 
        {ch = text[i];
        if (islower(ch)) 
            {ch = ch + k;
            if (ch > 'z') 
                {ch = ch - 'z' + 'a' - 1;}
            text[i] = ch;}
        else if (isupper(ch)) 
            {ch = ch + k;
            if (ch > 'Z') 
                {ch = ch - 'Z' + 'A' - 1;}
            text[i] = ch;}}
    printf("Encrypted text: %s\n", text);
    return 0;}
