#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
void get_plaintxt();
void encrypt(int);
void decrypt(int);
unsigned char plaintxt[1000];
unsigned char ciphertxt[1000];
unsigned char rciphertxt[1000];
int main()
{
    srand(time(NULL));
    int key = rand() % 100 + 1;
    get_plaintxt();
    encrypt(key);
    puts("\n\nCipher message: ");
    puts(ciphertxt);
    decrypt(key);
    puts("\n\nRecipher message: ");
    puts(rciphertxt);
}
//..read plain text from text file
void get_plaintxt()
{
    FILE *fptr;
    char ch;
    int i = 0;
    //..open "plaintxt.txt" file for reading mode
    fptr = fopen("plaintxt.txt", "r");
    if (fptr == NULL)
    {
        printf("Error Reading!");
        exit(1);
    }
    //.. read file content char by char into string
    while ((ch = fgetc(fptr)) != EOF)
    {
        plaintxt[i++] = ch;
    }
    plaintxt[i] = '\0';
    puts("\nPlain message: ");
    puts(plaintxt);
    fclose(fptr);
}
void encrypt(int key)
{
    int i = 0;
    FILE *fptr;
    //..open a text file "ciphertxt.txt" for writing mode
    fptr = fopen("ciphertxt.txt", "w");
    if (fptr == NULL)
    {
        printf("Error writing!!");
        exit(1);
    }
    //.. encrypt "plaintxt" and write it into "ciphertxt.txt" file //.. char by char
    printf("\nThe key increments for each character: ");
    while (plaintxt[i] != '\0')
    {
        ciphertxt[i] = plaintxt[i] + key;
        fputc(ciphertxt[i], fptr);
        i++;
        key = ((key + key + 2) * 133) % 100 + 1;
        printf("%d - ", key);
    }
    ciphertxt[i] = '\0';
    fclose(fptr);
}
void decrypt(int key)
{
    int i = 0;
    FILE *fptr;
    //..open a text file "rciphertxt.txt" for writing mode
    fptr = fopen("rciphertxt.txt", "w");
    if (fptr == NULL)
    {
        printf("Error writing!!");
        exit(1);
    }
    //.. decrypt "ciphertxt" and write it into "rciphertxt.txt" file //.. char by char
    while (ciphertxt[i] != '\0')
    {
        rciphertxt[i] = (ciphertxt[i] - key);
        fputc(rciphertxt[i], fptr);
        i++;
        key = ((key + key + 2) * 133) % 100 + 1;
    }
    rciphertxt[i] = '\0';
    fclose(fptr);
}