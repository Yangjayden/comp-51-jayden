//ATM Simulator
#include <iostream>
using namespace std;

int main() {
double balance = 1000.00;
int choice;
double amount;

cout << "Welcome to Simple ATM Simulator!" << endl;

while (true) {
    cout << "Your current balance is: $" << balance << endl;
    cout << "Menu: "<< endl;
    cout << "1. Check Balance" << endl; 
    cout << "2. Deposit Money" << endl; 
    cout << "3. Withdraw Money" << endl; 
    cout << "4. EXIT" << endl; 
    cout << "Enter your choice: " << endl;
    cin >> choice;

    if (choice == 1) {
    cout << "Your current balance is: $";
}
    else if (choice == 2) {
    cout << "Enter the amount to deposit: $";
    cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! Your New Balance is: $" << balance << endl;
        } 
    else {
        cout << "Enter a positive amount to deposit." << endl;
    }
    }
    else if (choice == 3) {
        cout << "Enter the amount to withdraw: $";
        cin >> amount;
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful! Your new balance is: $" << balance << endl;
    }
    else {
        cout << "Insufficient funds." << endl;
    }
    }
    else if (choice == 4) {
        cout << "Thank you for using the ATM. GOODBYE! " << endl;
        break;
    }
    else {
        cout << "Invalid choice, Please try again." << endl;
    }
}   
}