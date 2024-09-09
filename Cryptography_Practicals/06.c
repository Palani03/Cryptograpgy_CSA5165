#include <stdio.h>
#include <ctype.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return 1;
}
void decryptAffine(const char *text, int a, int b) {
    int a_inv = modInverse(a, 26);
    while (*text) {
        if (isalpha(*text)) {
            int y = toupper(*text) - 'A';
            int x = (a_inv * (y - b + 26)) % 26;
            printf("%c", x + 'A');
        } else {
            printf("%c", *text);
        }
        text++;
    }
    printf("\n");
}
int main() {
    char ciphertext[] = "YOUR CIPHERTEXT HERE";
    int a = 7;
    int b = 19;
    decryptAffine(ciphertext, a, b);
    return 0;
}
