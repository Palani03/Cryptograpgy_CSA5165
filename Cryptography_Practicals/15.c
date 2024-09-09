#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void countFrequency(const char *text, int freq[]) {
    for (int i = 0; text[i]; i++) 
        if (isalpha(text[i])) freq[toupper(text[i]) - 'A']++;
}
void decrypt(const char *cipher, int key, char *plain) {
    for (int i = 0; cipher[i]; i++)
        plain[i] = isalpha(cipher[i]) ? 'A' + (toupper(cipher[i]) - 'A' - key + ALPHABET_SIZE) % ALPHABET_SIZE : cipher[i];
    plain[strlen(cipher)] = '\0';
}
void frequencyAttack(const char *cipher, int top) {
    int freq[ALPHABET_SIZE] = {0};
    countFrequency(cipher, freq);
    int max_index = 0;
    for (int i = 1; i < ALPHABET_SIZE; i++) 
        if (freq[i] > freq[max_index]) max_index = i;
    int key = (max_index - ('E' - 'A') + ALPHABET_SIZE) % ALPHABET_SIZE;
    char plaintext[strlen(cipher) + 1];
    printf("Top %d possible plaintexts:\n", top);
    for (int i = 1; i <= top; i++) {
        decrypt(cipher, key, plaintext);
        printf("%d. Key = %d: %s\n", i, key, plaintext);
        key = (key + 1) % ALPHABET_SIZE;
    }
}
int main() {
    char ciphertext[] = "Zpv xibu, bu uif hbnf jt b hppe hbnf jt ibse up kfu."; 
    frequencyAttack(ciphertext, 10);
    return 0;
}
Output:
Top 10 possible plaintexts:
1. Key = 23: CSY ALEX, EX XLI KEQI MW E KSSH KEQI MW LEVH XS NIX.
2. Key = 24: BRX ZKDW, DW WKH JDPH LV D JRRG JDPH LV KDUG WR MHW.
3. Key = 25: AQW YJCV, CV VJG ICOG KU C IQQF ICOG KU JCTF VQ LGV.
4. Key = 0: ZPV XIBU, BU UIF HBNF JT B HPPE HBNF JT IBSE UP KFU.
5. Key = 1: YOU WHAT, AT THE GAME IS A GOOD GAME IS HARD TO JET.
6. Key = 2: XNT VGZS, ZS SGD FZLD HR Z FNNC FZLD HR GZQC SN IDS.
7. Key = 3: WMS UFYR, YR RFC EYKC GQ Y EMMB EYKC GQ FYPB RM HCR.
8. Key = 4: VLR TEXQ, XQ QEB DXJB FP X DLLA DXJB FP EXOA QL GBQ.
9. Key = 5: UKQ SDWP, WP PDA CWIA EO W CKKZ CWIA EO DWNZ PK FAP.
10. Key = 6: TJP RCVO, VO OCZ BVHZ DN V BJJY BVHZ DN CVMY OJ EZO.
