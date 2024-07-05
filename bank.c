#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct { // Structure for account
    int accountNumber; // Account number
    char name[100]; // Account holder's name
    double balance; // Account balance
} Account; // Account

void createAccount(Account accounts[], int *numAccounts); // Function to create a new account
void deposit(Account *account, double amount); // Function to deposit money into an account
void withdraw(Account *account, double amount); // Function to withdraw money from an account
void displayAccount(const Account *account); // Function to display account information
Account* findAccount(Account accounts[], int numAccounts, int accountNumber); // Function to find an account by account number

int main() { // Main function
    Account accounts[MAX_ACCOUNTS]; // Array of accounts
    int numAccounts = 0; // Number of accounts
    int choice; // User's choice

    do { // Main menu loop
        printf("\nBankacılık Uygulaması\n"); // Display menu
        printf("1. Hesap oluştur\n"); // Create account
        printf("2. Para yatır\n"); // Deposit money
        printf("3. Para çek\n"); // Withdraw money
        printf("4. Bakiye görüntüle\n"); // Display account balance
        printf("5. Çıkış\n"); // Exit
        printf("Seçiminizi yapın: "); // Prompt user for choice
        scanf("%d", &choice); // Read user's choice

        switch (choice) { // Switch statement for user's choice
            case 1: // Create account
                createAccount(accounts, &numAccounts); // Call createAccount function
                break; // Break out of switch statement
            case 2: { // Deposit money
                int accountNumber; // Account number
                double amount; // Amount to deposit
                printf("Hesap numarası: "); // Prompt user for account number
                scanf("%d", &accountNumber); // Read account number
                Account *account = findAccount(accounts, numAccounts, accountNumber); // Find account by account number
                if (account != NULL) { // If account is found
                    printf("Yatırılacak miktar: "); // Prompt user for amount to deposit
                    scanf("%lf", &amount); // Read amount to deposit
                    deposit(account, amount); // Call deposit function
                } else { // If account is not found
                    printf("Hesap bulunamadı!\n"); // Display error message
                }
                break; // Break out of switch statement
            }
            case 3: { // Withdraw money
                int accountNumber; // Account number
                double amount; // Amount to withdraw
                printf("Hesap numarası: "); // Prompt user for account number
                scanf("%d", &accountNumber); // Read account number
                Account *account = findAccount(accounts, numAccounts, accountNumber); // Find account by account number
                if (account != NULL) { // If account is found
                    printf("Çekilecek miktar: "); // Prompt user for amount to withdraw
                    scanf("%lf", &amount); // Read amount to withdraw
                    withdraw(account, amount); // Call withdraw function
                } else { // If account is not found
                    printf("Hesap bulunamadı!\n"); // Display error message
                }
                break; // Break out of switch statement
            }
            case 4: { // Display account balance
                int accountNumber; // Account number
                printf("Hesap numarası: "); // Prompt user for account number
                scanf("%d", &accountNumber); // Read account number
                Account *account = findAccount(accounts, numAccounts, accountNumber); // Find account by account number
                if (account != NULL) { // If account is found
                    displayAccount(account); // Call displayAccount function
                } else { // If account is not found
                    printf("Hesap bulunamadı!\n"); // Display error message
                }
                break; // Break out of switch statement
            }
            case 5: // Exit
                printf("Çıkılıyor...\n"); // Display exit message
                break; // Break out of switch statement
            default: // Invalid choice
                printf("Geçersiz seçim!\n"); // Display error message
        }
    } while (choice != 5); // Loop until user chooses to exit

    return 0; // Return 0 to indicate successful execution
}

void createAccount(Account accounts[], int *numAccounts) { // Function to create a new account
    if (*numAccounts >= MAX_ACCOUNTS) { // If maximum number of accounts is reached
        printf("Maksimum hesap sayısına ulaşıldı!\n"); // Display error message
        return; // Return from function
    }
    printf("Hesap numarası: "); // Prompt user for account number
    scanf("%d", &accounts[*numAccounts].accountNumber); // Read account number
    printf("Ad: "); // Prompt user for account holder's name
    scanf("%s", accounts[*numAccounts].name); // Read account holder's name
    accounts[*numAccounts].balance = 0.0; // Set account balance to 0
    (*numAccounts)++; // Increment number of accounts
    printf("Hesap başarıyla oluşturuldu!\n"); // Display success message
}

void deposit(Account *account, double amount) { // Function to deposit money into an account
    if (amount > 0) { // If amount is positive
        account->balance += amount; // Add amount to account balance
        printf("Para başarıyla yatırıldı!\n"); // Display success message
    } else { // If amount is negative or zero
        printf("Geçersiz miktar!\n"); // Display error message
    }
}

void withdraw(Account *account, double amount) { // Function to withdraw money from an account
    if (amount > 0 && account->balance >= amount) { // If amount is positive and account balance is sufficient
        account->balance -= amount; // Subtract amount from account balance
        printf("Para başarıyla çekildi!\n"); // Display success message
    } else { // If amount is negative, zero, or insufficient balance
        printf("Geçersiz miktar veya yetersiz bakiye!\n"); // Display error message
    }
}

void displayAccount(const Account *account) { // Function to display account information
    printf("Hesap numarası: %d\n", account->accountNumber); // Display account number
    printf("Ad: %s\n", account->name); // Display account holder's name
    printf("Bakiye: %.2f\n", account->balance); // Display account balance
}

Account* findAccount(Account accounts[], int numAccounts, int accountNumber) { // Function to find an account by account number
    for (int i = 0; i < numAccounts; i++) { // Loop through accounts
        if (accounts[i].accountNumber == accountNumber) { // If account number matches
            return &accounts[i]; // Return pointer to account
        }
    }
    return NULL; // Return NULL if account is not found
}
