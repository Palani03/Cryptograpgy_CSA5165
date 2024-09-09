#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
const float english_frequencies[ALPHABET_SIZE] = { 
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 
    0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 
    0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 
    0.01974 
};
void countFrequency(const char *text, float freq[]) {
    int total_letters = 0;
    for (int i = 0; text[i]; ++i)
        if (isalpha(text[i])) freq[toupper(text[i]) - 'A']++, total_letters++;
    for (int i = 0; i < ALPHABET_SIZE; ++i) freq[i] /= total_letters;
}
float chiSquare(const float observed[], const float expected[]) {
    float chi_square = 0.0;
    for (int i = 0; i < ALPHABET_SIZE; ++i)
        if (expected[i] > 0) 
            chi_square += (observed[i] - expected[i]) * (observed[i] - expected[i]) / expected[i];
    return chi_square;
}
void decrypt(const char *ciphertext, const char key[], char *plaintext) {
    for (int i = 0; ciphertext[i]; ++i) 
        plaintext[i] = isalpha(ciphertext[i]) ? key[toupper(ciphertext[i]) - 'A'] : ciphertext[i];
    plaintext[strlen(ciphertext)] = '\0';
}
void frequencyAttack(const char *ciphertext, int top) {
    float observed_freq[ALPHABET_SIZE] = {0}, chi_square[ALPHABET_SIZE];
    countFrequency(ciphertext, observed_freq);
    for (int shift = 0; shift < ALPHABET_SIZE; ++shift) {
        float shifted_freq[ALPHABET_SIZE] = {0};
        for (int i = 0; i < ALPHABET_SIZE; ++i) 
            shifted_freq[(i + shift) % ALPHABET_SIZE] = observed_freq[i];
        chi_square[shift] = chiSquare(shifted_freq, english_frequencies);
    }
    printf("Top %d possible plaintexts:\n", top);
    for (int rank = 1; rank <= top; ++rank) {
        int min_index = 0;
        for (int i = 1; i < ALPHABET_SIZE; ++i) 
            if (chi_square[i] < chi_square[min_index]) min_index = i;
        char plaintext[strlen(ciphertext) + 1], key[ALPHABET_SIZE];
        for (int i = 0; i < ALPHABET_SIZE; ++i) 
            key[i] = 'A' + (i + min_index) % ALPHABET_SIZE;
        decrypt(ciphertext, key, plaintext);
        printf("%d. Key: %s\n   Plaintext: %s\n   Chi-Square: %.4f\n", rank, key, plaintext, chi_square[min_index]);
        chi_square[min_index] = 1000.0;
    }
}
int main() {
    char ciphertext[] = "Wklv lv dq rqob prgh.";
    frequencyAttack(ciphertext, 10);
    return 0;
}
Output:
Top 10 possible plaintexts:
1. Key: XYZABCDEFGHIJKLMNOPQRSTUVWa
   Plaintext: THIS IS AN ONLY MODE.
   Chi-Square: 0.6451
2. Key: LMNOPQRSTUVWXYZABCDEFGHIJKa
   Plaintext: HVWG WG OB CBZM ACRS.
   Chi-Square: 3.0234
3. Key: EFGHIJKLMNOPQRSTUVWXYZABCDa
   Plaintext: AOPZ PZ HU VUSF TVKL.
   Chi-Square: 3.2706
4. Key: WXYZABCDEFGHIJKLMNOPQRSTUVa
   Plaintext: SGHR HR ZM NMKX LNCD.
   Chi-Square: 4.2176
5. Key: DEFGHIJKLMNOPQRSTUVWXYZABCa
   Plaintext: ZNOY OY GT UTRE SUJK.
   Chi-Square: 4.3316
6. Key: RSTUVWXYZABCDEFGHIJKLMNOPQa
   Plaintext: NBCM CM UH IHFS GIXY.
   Chi-Square: 4.3853
7. Key: QRSTUVWXYZABCDEFGHIJKLMNOPa
   Plaintext: MABL BL TG HGER FHWX.
   Chi-Square: 4.7609
8. Key: IJKLMNOPQRSTUVWXYZABCDEFGHa
   Plaintext: ESTD TD LY ZYWJ XZOP.
   Chi-Square: 6.3476
9. Key: KLMNOPQRSTUVWXYZABCDEFGHIJa
   Plaintext: GUVF VF NA BAYL ZBQR.
   Chi-Square: 7.5272
10. Key: PQRSTUVWXYZABCDEFGHIJKLMNOa
   Plaintext: LZAK AK SF GFDQ EGVW.
   Chi-Square: 7.7744
