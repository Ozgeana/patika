// Your First C++ Program

#include <iostream>
#include <string.h>

void ReverseText(char *text) {
    int length = strlen(text);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = text[i];
        text[i] = text[j];
        text[j] = temp;
    }
}

int main() {
    char text[100];

    printf("Metni girin: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Newline karakterini kaldır

    ReverseText(text);

    printf("Ters çevrilen metin: %s\n", text);

    return 0;
}