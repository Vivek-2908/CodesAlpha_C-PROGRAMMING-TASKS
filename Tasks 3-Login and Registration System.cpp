#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int ch;
    string user, passwrd, u, p;

    cout << "1. Register\n2. Login\nEnter Choice: ";
    cin >> ch;

    if (ch == 1) {
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> passwrd;

        ofstream file("user.txt");
        file << user << " " << passwrd;
        file.close();

        cout << "Registration Successful!";
    }
    else if (ch == 2) {
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> passwrd;

        ifstream file("user.txt");
        file >> u >> p;
        file.close();

        if (user == u && passwrd == p)
            cout << "Login Successful!";
        else
            cout << "Invalid Username or Password!";
    }

    return 0;
}
