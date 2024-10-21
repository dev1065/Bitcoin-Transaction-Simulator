#include <bits/stdc++.h>
// #include <windows.h>
using namespace std;

const int MAX = 36;
string previous_hash_code = "000000000000";
float universal_bitcoins = 1000;

// Sender class
class Sender {
public:
    string private_key;
    string public_key;
    float bitcoin = 50;

public:
    Sender() {
        cout << "Generate the account for sender" << endl;
        cout << "Enter your private key: ";
        cin >> private_key;
        cout << "Enter your public key: ";
        cin >> public_key;
    }
};

// Receiver class
class Reciever {
public:
    string private_key;
    string public_key;
    float bitcoin = 50;

public:
    Reciever() {
        cout << "Generate the account for receiver" << endl;
        cout << "Enter your private key: ";
        cin >> private_key;
        cout << "Enter your public key: ";
        cin >> public_key;
    }
};

// Base class Verifier for dynamic polymorphism
class Verifier {
public:
    virtual bool verify(Sender s1, Reciever r1, float transaction_bitcoin, string private_key, string public_key) = 0; // Pure virtual function
};

// Derived class MinorVerifier for verifying transactions
class MinorVerifier : public Verifier {
public:
    bool verify(Sender s1, Reciever r1, float transaction_bitcoin, string private_key, string public_key) override {
        cout << "MINORS ARE VERIFYING THE TRANSACTION";
        int temp = 13;
        while (temp--) {
            Sleep(500);
            cout << ".";
        }
        // Verification logic
        if (private_key != s1.private_key) {
            cout << "\nInvalid sender's private key!" << endl;
            return false;
        } else if (public_key != r1.public_key) {
            cout << "\nInvalid receiver's public key!" << endl;
            return false;
        } else if (transaction_bitcoin > s1.bitcoin) {
            cout << "\nINSUFFICIENT BALANCE!!!!" << endl;
            return false;
        }
        return true;
    }
};

// Transaction class
class Transaction {
private:
    float transaction_bitcoin;
    string private_key;
    string public_key;
    string hashcode;
    string choice;

public:
    Transaction(Sender s1, Reciever r1, Verifier* verifier) {
        repeat:
        cout << "EXECUTING TRANSACTION" << endl;
        cout << "Enter the amount of bitcoin you want to send: ";
        cin >> transaction_bitcoin;
        cout << "Enter the public key of the receiver: ";
        cin >> public_key;
        cout << "Enter the private key of the sender: ";
        cin >> private_key;

        // Use polymorphism to verify the transaction
        if (verifier->verify(s1, r1, transaction_bitcoin, private_key, public_key)) {
            cout << "\nTransaction verified by minor" << endl;

            // Update bitcoin balances
            s1.bitcoin -= transaction_bitcoin;
            r1.bitcoin += transaction_bitcoin;
            Sleep(2000);

            // Generate hashcode and display transaction
            hashcode_generation();
            display(s1, r1);

            previous_hash_code = hashcode;

            cout << "\n\nDo you wish to execute another transaction? (yes/no): ";
            cin >> choice;
            if (choice == "yes") {
                goto repeat;
            } else {
                cout << "Successfully Executed" << endl;
            }
        } else {
            cout << "\nInvalid credentials or insufficient balance!" << endl;
            return;
        }
    }

    // Function to generate a unique hashcode
    void hashcode_generation() {
        srand(time(0));
        cout << "\nGENERATING HASHCODE!!" << endl;

        char alphabet[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                              'h', 'i', 'j', 'k', 'l', 'm', 'n',
                              'o', 'p', 'q', 'r', 's', 't', 'u',
                              'v', 'w', 'x', 'y', 'z', '1', '2',
                              '3', '4', '5', '6', '7', '8', '9', '0'};

        string res = "";
        int temp = 12;
        while (temp--) {
            Sleep(600);
            cout << ".";
            res += alphabet[rand() % MAX];
        }
        hashcode = res;
        cout << "\nhashcode successfully generated" << endl;
        Sleep(2000);
    }

    // Display transaction details
    void display(Sender s1, Reciever r1) {
        system("cls");
        cout << "Transaction Successfully Executed" << endl;
        cout << "Sent by = " << s1.public_key << endl;
        cout << "Received by = " << r1.public_key << endl;
        cout << "Bitcoin Transacted = " << transaction_bitcoin << endl;
        cout << "Hashcode = " << hashcode << endl;
        cout << "Previous hashcode = " << previous_hash_code << endl;
        cout << "Minor received = 12.5 bitcoins" << endl;
        universal_bitcoins -= 12.5;
    }
};

// Main function
int main() {
    Sender dev;
    Reciever pranay;

    // Create a verifier object for minor
    MinorVerifier minor_verifier;

    // Execute the transaction using dynamic polymorphism
    Transaction(dev, pranay, &minor_verifier);

    return 0;
}
