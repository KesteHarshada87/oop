#include <iostream>
#include <iomanip>
using namespace std;

void credit(int initial[], int &num) {
    int money;
    cout << "Enter amount you want to deposit: ";
    cin >> money;
    if (money <= 0) {
        cout << "Invalid amount!\n";
        return;
    }
    initial[num] = initial[num - 1] + money;
    num++; 
    cout << "\nUpdated Balances:\n";
    for (int i = 0; i < num; i++) {
        cout << right << setw(10) << "Cr" << " " 
             << right << setw(10) << initial[i] << endl;
    }
}
void debit(int initial[], int &num) {
    int money;
    cout << "Enter amount you want to withdraw: ";
    cin >> money;
    if (money <= 0) {
        cout << "Invalid amount!\n";
        return;
    }

    if (initial[num - 1] < money) {
        cout << "Insufficient balance! Transaction failed.\n";
        return;
    }


    initial[num] = initial[num - 1] - money;
    num++;

    cout << "\nUpdated Balances:\n";
    for (int i = 0; i < num; i++) {
        cout << right << setw(10) << "Dr" << " " 
             << right << setw(10) << initial[i] << endl;
    }
}

int main() {
    int initial[50]; 
    int num = 1, choice; 
    cout << "Enter initial deposit amount: ";
    cin >> initial[0];

    if (initial[0] < 0) {
        cout << "Invalid input.\n";
        return 1;
    }
    int totalTransactions;
    cout << "How many transactions do you want to make? ";
    cin >> totalTransactions;

    if (totalTransactions <= 0) {
        cout << "Invalid number of total transactions.\n";
        return 1;
    }
    for (int i = 0; i < totalTransactions; i++) {
        cout << "\nDo you want to deposit money?";
        cout << "\nClick 1 for deposit, 0 for withdrawal: ";
        cin >> choice;

        if (choice == 1) {
            credit(initial, num);
        } 
        else {
            debit(initial, num);
        }
    }
    cout << "\nFinal Account Balance: " << initial[num - 1] << endl;
    return 0;
}
