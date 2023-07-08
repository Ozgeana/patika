#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    User newUser;

    printf("Isim: ");
    scanf("%s", newUser.name);

    printf("Hesap Numarasi: ");
    scanf("%d", &newUser.accountNumber);

    printf("Baslangic Bakiyesi: ");
    scanf("%lf", &newUser.balance);

    users[userCount++] = newUser;
    printf("Yeni kullanici kaydi olusturuldu.\n");
}

User* login() {
    int accountNumber;
    printf("Hesap Numarasi: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < userCount; i++) {
        if (users[i].accountNumber == accountNumber) {
            return &users[i];
        }
    }

    printf("Hesap bulunamadi.\n");
    return NULL;
}

void viewAccount(User* user) {
    printf("Isim: %s\n", user->name);
    printf("Hesap Numarasi: %d\n", user->accountNumber);
    printf("Bakiye: %.2lf\n", user->balance);
}

void deposit(User* user) {
    double amount;
    printf("Yatirilacak Miktar: ");
    scanf("%lf", &amount);

    user->balance += amount;
    printf("Yatirma islemi tamamlandi. Yeni bakiye: %.2lf\n", user->balance);
}

void withdraw(User* user) {
    double amount;
    printf("Cekilecek Miktar: ");
    scanf("%lf", &amount);

    if (amount > user->balance) {
        printf("Yetersiz bakiye.\n");
    } else {
        user->balance -= amount;
        printf("Cekme islemi tamamlandi. Yeni bakiye: %.2lf\n", user->balance);
    }
}

void saveUserData() {
    FILE* file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%d %s %.2lf\n", users[i].accountNumber, users[i].name, users[i].balance);
    }

    fclose(file);
    printf("Kullanici bilgileri kaydedildi.\n");
}

void loadUserData() {
    FILE* file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("Dosya acilamadi.\n");
        return;
    }

    userCount = 0;
    while (fscanf(file, "%d %s %lf", &users[userCount].accountNumber, users[userCount].name, &users[userCount].balance) == 3) {
        userCount++;
    }

    fclose(file);
    printf("Kullanici bilgileri yuklendi.\n");
}

int main() {
    int choice;
    User* currentUser = NULL;

    while (1) {
        printf("\n--- Banka Hesap Yonetimi ---\n");
        printf("1. Yeni Hesap Olustur\n");
        printf("2. Hesaba Giris\n");
        printf("3. Hesap Bilgilerini Goruntule\n");
        printf("4. Para Yatirma\n");
        printf("5. Para Cekme\n");
        printf("6. Kullanici Bilgilerini Kaydet\n");
        printf("7. Kullanici Bilgilerini Yukle\n");
        printf("0. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                saveUserData();
                printf("Program sonlandiriliyor...\n");
                exit(0);
            case 1:
                registerUser();
                break;
            case 2:
                currentUser = login();
                break;
            case 3:
                if (currentUser != NULL) {
                    viewAccount(currentUser);
                } else {
                    printf("Once hesaba giris yapmaniz gerekiyor.\n");
                }
                break;
            case 4:
                if (currentUser != NULL) {
                    deposit(currentUser);
                } else {
                    printf("Once hesaba giris yapmaniz gerekiyor.\n");
                }
                break;
            case 5:
                if (currentUser != NULL) {
                    withdraw(currentUser);
                } else {
                    printf("Once hesaba giris yapmaniz gerekiyor.\n");
                }
                break;
            case 6:
                saveUserData();
                break;
            case 7:
                loadUserData();
                break;
            default:
                printf("Gecersiz secim.\n");
        }
    }

    return 0;
}

