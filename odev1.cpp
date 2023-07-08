#include <stdio.h>

#define MAX_SIZE 100

int findMax(int arr[], int size) {
    int max = arr[0]; // Başlangıçta en büyük sayıyı dizinin ilk elemanı olarak varsayalım

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int n;
    int arr[MAX_SIZE];

    printf("Dizi boyutunu girin (1-%d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Geçersiz dizi boyutu!\n");
        return 0;
    }

    printf("Diziyi girin:\n");
    for (int i = 0; i < n; i++) {
        printf("Eleman %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = findMax(arr, n);

    printf("En büyük sayı: %d\n", max);

    return 0;
}
