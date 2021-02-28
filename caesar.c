#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        char *a = argv[1];
        int key = atoi(a);
        if (argc!=2 || key == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            string intput = get_string("plaintext: ");

            printf("ciphertext: "); // shifted by 2 == jgnnq

            int encryptor = key%26;

            for (int i = 0, n = strlen(intput); i < n; i++)
            {
                int ch = intput[i]; // 104
                int encrypted;
                // upper case check
                if (ch < 65 || ch > 122)
                {
                    printf("%c", ch);
                }
                else if  (ch > 90 && ch < 97)
                {
                    printf("%c", ch);
                }
                // codition for upper case (65 - 89)
                else if (ch > 65 && ch < 90 && ch+encryptor > 90)
                {
                    encrypted = 64 + (ch + encryptor-90);
                    printf("%c", encrypted);
                }
                    // condition for lower case (97 - 122)
                else if (ch > 97 && ch < 122 && ch+encryptor > 122)
                {
                    encrypted = 96 + (ch + encryptor-122);
                    printf("%c", encrypted);
                }
                else
                {
                    printf("%c", ch+encryptor);
                }
            }
            printf("\n");
            }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
