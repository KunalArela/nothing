
#include <stdio.h>

// Structure to represent a bank account
struct Account {
    int accountNumber;
    char accountHolderName[100];
    float balance;
};

int main() {
    // Initialize three bank accounts
    struct Account accounts[3] = {
        {1, "Account 1", 1000.0},
        {2, "Account 2", 2000.0},
        {3, "Account 3", 3000.0}
    };

    int choice, accountChoice, withdrawAmount, depositAmount;

    while (1) {
        // Display main menu
        printf("\nBanking System Menu\n");
        printf("1. Select Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Select account
                printf("Select an account (1/2/3): ");
                scanf("%d", &accountChoice);
                if (accountChoice < 1 || accountChoice > 3) {
                    printf("Invalid account choice. Please choose 1, 2 or 3.\n");
                }
                break;

            case 2:
                // Deposit money
                if (accountChoice == 0) {
                    printf("Please select an account first.\n");
                    break;
                }
                printf("Enter amount to deposit: ");
                scanf("%d", &depositAmount);
                accounts[accountChoice - 1].balance += depositAmount;
                printf("Deposit successful. New balance: %.2f\n", accounts[accountChoice - 1].balance);
                break;

            case 3:
                // Withdraw money
                if (accountChoice == 0) {
                    printf("Please select an account first.\n");
                    break;
                }
                printf("Enter amount to withdraw: ");
                scanf("%d", &withdrawAmount);
                if (withdrawAmount > accounts[accountChoice - 1].balance) {
                    printf("Insufficient balance.\n");
                } else {
                    accounts[accountChoice - 1].balance -= withdrawAmount;
                    printf("Withdrawal successful. New balance: %.2f\n", accounts[accountChoice - 1].balance);
                }
                break;

            case 4:
                // Check balance
                if (accountChoice == 0) {
                    printf("Please select an account first.\n");
                    break;
                }
                printf("Account balance: %.2f\n", accounts[accountChoice - 1].balance);
                break;

            case 5:
                // Exit program
                printf("Thank you for using our banking system. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }
    }

    return 0;
}



