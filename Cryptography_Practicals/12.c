#include <stdio.h>
#include <string.h>

int mod(int a, int m) {
    return (a % m + m) % m;
}
void hillEncrypt(int key[3][3], char* text, int len) {
    for (int i = 0; i < len; i += 3) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            for (int k = 0; k < 3; k++)
                sum += key[j][k] * (text[i + k] - 'A');
            text[i + j] = mod(sum, 26) + 'A';
        }
    }
    printf("Ciphertext: %s\n", text);
}
int main() {
    int key[3][3];
    char text[100];
    printf("Enter 3x3 key matrix:\n");
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) scanf("%d", &key[i][j]);
    printf("Enter plaintext (uppercase): ");
    scanf("%s", text);
    int len = strlen(text);
    while (len % 3 != 0) text[len++] = 'X';
    hillEncrypt(key, text, len);
    return 0;
}
Output:
Enter 3x3 key matrix:
1 2 3
2 3 4
5 6 7
Enter plaintext (uppercase): HELLO
Ciphertext: WWHEMT
