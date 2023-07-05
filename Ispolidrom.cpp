#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char *word)
{
    int length = strlen(word);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        if (word[i] != word[j])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char word[100];

    printf("Kelimeyi girin: ");
    scanf("%s", word);

    if (isPalindrome(word))
    {
        printf("%s bir polindromdur.\n", word);
    }
    else
    {
        printf("%s bir polindrom değildir.\n", word);
    }

    return 0;
}