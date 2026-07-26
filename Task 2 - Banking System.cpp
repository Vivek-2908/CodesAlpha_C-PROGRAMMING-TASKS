#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Customer {
public:
    int id;
    string name;
};

class Account {
public:
    int accNo;
    double balance;

    Account() {
        balance = 0;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }
};

class Transaction {
public:
    vector<string> history;

    void add(string msg) {
        history.push_back(msg);
    }

    void show() {
        cout << "\nTransaction History:\n";
        for (string s : history)
            cout << s << endl;
    }
};

int main() {
    Customer c;
    Account a1, a2;
    Transaction t;

    int choice;
    double amount;

    cout << "Enter Customer ID: ";
    cin >> c.id;
    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, c.name);

    cout << "Enter Account Number: ";
    cin >> a1.accNo;

    a2.accNo = 2002; // Second account for transfer

    do {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Show Balance\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            cout << "Enter Amount: ";
            cin >> amount;
            a1.deposit(amount);
            t.add("Deposited: " + to_string(amount));
            break;

        case 2:
            cout << "Enter Amount: ";
            cin >> amount;
            a1.withdraw(amount);
            t.add("Withdrawn: " + to_string(amount));
            break;

        case 3:
            cout << "Enter Amount: ";
            cin >> amount;
            if(amount <= a1.balance) {
                a1.balance -= amount;
                a2.balance += amount;
                cout << "Transfer Successful!\n";
                t.add("Transferred: " + to_string(amount));
            } else {
                cout << "Insufficient Balance!\n";
            }
            break;

        case 4:
            cout << "Customer: " << c.name << endl;
            cout << "Account Number: " << a1.accNo << endl;
            cout << "Balance: " << a1.balance << endl;
            break;

        case 5:
            t.show();
            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}
