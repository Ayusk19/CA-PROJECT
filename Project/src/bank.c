#include <stdio.h>
#include <stdlib.h>

// Structure to store account information
struct Account {
    int accountNumber;
    char accountHolder[50];
    float balance;
};

// Function to create a new account
void createAccount(struct Account accounts[], int *count) {
    if (*count < 100) {
        printf("Enter account holder's name: ");
        scanf("%s", accounts[*count].accountHolder);
        
        printf("Enter initial balance: ");
        scanf("%f", &accounts[*count].balance);
        
        // Account number
        void createAccount(struct Account accounts[], int *count) {
    if (*count < 100) {
        printf("Enter account holder's name: ");
        scanf("%s", accounts[*count].accountHolder);
        
        printf("Enter account number: "); // Prompt for a custom account number
        scanf("%d", &accounts[*count].accountNumber);
        
        printf("Enter initial balance: ");
        scanf("%f", &accounts[*count].balance);
        
        (*count)++;
        printf("Account created successfully.\n");
    } else {
        printf("Maximum account limit reached.\n");
    }
}

        (*count)++;
        printf("Account created successfully. Account number: %d\n", accounts[*count - 1].accountNumber);
    } else {
        printf("Maximum account limit reached.\n");
    }
}

// Function to deposit money into an account
void deposit(struct Account accounts[], int count, int accountNumber, float amount) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accounts[i].balance += amount;
            printf("Amount deposited successfully. New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdraw(struct Account accounts[], int count, int accountNumber, float amount) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully. New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to check account balance
void checkBalance(struct Account accounts[], int count, int accountNumber) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    struct Account accounts[100]; // Array to store account information
    int accountCount = 0; // Counter to keep track of the number of accounts
    
    int choice;
    
    do {
        printf("\033[34m\nBank Management System\n");
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount(accounts, &accountCount);
                break;
            case 2: {
                int accountNumber;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(accounts, accountCount, accountNumber, amount);
                break;
            }
            case 3: {
                int accountNumber;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(accounts, accountCount, accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                checkBalance(accounts, accountCount, accountNumber);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
