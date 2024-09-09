#include <stdio.h>
#include <string.h>
#include <ctype.h>
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}
char affineEncrypt(char p, int a, int b) {
    if (isalpha(p)) {
        int base = islower(p) ? 'a' : 'A';
        return ((a * (p - base) + b) % 26 + 26) % 26 + base;
    }
    return p;
}
char affineDecrypt(char c, int a, int b) {
    if (isalpha(c)) {
        int base = islower(c) ? 'a' : 'A';
        int aInv = modInverse(a, 26);
        if (aInv == -1) return c;
        return ((aInv * (c - base - b + 26)) % 26 + 26) % 26 + base;
    }
    return c;
}
int main() {
    int a, b;
    char plaintext[1000], ciphertext[1000], decryptedText[1000];
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';
    printf("Enter 'a' (coprime to 26): ");
    scanf("%d", &a);
    if (gcd(a, 26) != 1) {
        printf("'a' must be coprime to 26.\n");
        return 1;
    }
    printf("Enter 'b': ");
    scanf("%d", &b);
    for (int i = 0; plaintext[i]; i++) {
        ciphertext[i] = affineEncrypt(plaintext[i], a, b);
    }
    ciphertext[strlen(plaintext)] = '\0';
    printf("Encrypted Text: %s\n", ciphertext);
    for (int i = 0; ciphertext[i]; i++) {
        decryptedText[i] = affineDecrypt(ciphertext[i], a, b);
    }
    decryptedText[strlen(ciphertext)] = '\0';
    printf("Decrypted Text: %s\n", decryptedText);
    return 0;
}
