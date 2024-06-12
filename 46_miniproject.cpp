#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

// defining a constant size of array for hashcode generation from the elements of array
const int MAX = 36;

// declaring a variable which will contain the previous hashcode
string previous_hash_code = "000000000000";

// this will hold the account for the universal bitcoins
float universal_bitcoins = 1000;

// creating a sender class which will hold the sender details
class Sender
{
public:
    string private_key;
    string public_key;
    float bitcoin = 50;

public:
    Sender()
    {
        cout << "generate the account for sender" << endl;
        cout << "enter your private key:- " << endl;
        cin >> private_key;
        cout << "enter your public key:- " << endl;
        cin >> public_key;
    }
};

// creating a reciever class which will contain the details of the reciever
class Reciever
{
public:
    string private_key;
    string public_key;
    float bitcoin = 50;

public:
    Reciever()
    {
        cout << "generate the account for reciever " << endl;
        cout << "enter your private key:- " << endl;
        cin >> private_key;
        cout << "enter your public key:- " << endl;
        cin >> public_key;
    }
};

// A transaction class which holds the main transaction
class Transaction
{
private:
    float transaction_bitcoin;
    string private_key;
    string public_key;
    string hashcode;
    string choice;

public:
    /*A parametrised constructor of transaction
    with parameters of the sender and reciever is given*/
    Transaction(Sender s1, Reciever r1)
    {

    // for goto in case user wants to make another transaction
    repeat:
        cout << "EXECUTING TRANSACTION" << endl;
        cout << "enter the amount of bitcoin you want to send:-" << endl;
        cin >> transaction_bitcoin;
        cout << "enter the public key of the reciever:- " << endl;
        cin >> public_key;
        cout << "enter the private key of the sender:- " << endl;
        cin >> private_key;

        // will run when the minor verifies the transaction details are correct
        if (minor(s1, r1))
        {
            cout << "\nminor verfied the transaction" << endl;

            // reducing the transacted amount of bitcoins from sender
            s1.bitcoin = s1.bitcoin - transaction_bitcoin;

            // adding the transacted amount of bitcoins from reciever
            r1.bitcoin = r1.bitcoin + transaction_bitcoin;
            Sleep(2000);

            // call of the function for hashcode generation
            hashcode_generation();

            // calling the display function which shows the details of the transaction
            display(s1, r1);

            previous_hash_code = hashcode;
            cout << "\n\n\nDo you wish to execute another transaction?" << endl;
            cout << "type yes or no" << endl;
            cin >> choice;

            // condition according to user choice to continue or not
            if (choice == "yes")
                goto repeat;
            else
                cout << "Successfully Executed" << endl;
        }
        else
        {
            cout << "\ninvalid credentials!!!!!!" << endl;
            return;
        }
    }

    // a function named minor which will verify the valid details in a transaction
    bool minor(Sender s1, Reciever r1);

    // the function to generate unique hashcode each time a transaction is made
    void hashcode_generation();

    // function to display details of transaction
    void display(Sender s1, Reciever r1);
};

/*
  the minor function verifies the private key , public key and if the sender has
  enough amount of bitcoins to give to the reciever
  It has a bool return type which will return true if every detail is correct and will return
  false if any of detail gets wrong
*/
bool Transaction::minor(Sender s1, Reciever r1)
{
    Sleep(1000);
    system("cls");
    cout << "MINORS ARE VERIFYING THE TRANSACTION" << endl;
    int temp = 13;
    while (temp--)
    {
        Sleep(500);
        cout << ".";
    }
    if (private_key != s1.private_key)
        return false;
    else if (public_key != r1.public_key)
        return false;
    else if (transaction_bitcoin > s1.bitcoin)
    {
        cout << "INSUFFICIENT BALANCE!!!!" << endl;
        return false;
    }
    else
        return true;
}

/*
  This is the display fuction which displays that transaction has been successfully
  executed and details such as sent by , recieved by , no. of bitcoins and the unique
  hashcode, also the previous hashcode of the transaction.
*/
void Transaction::display(Sender s1, Reciever r1)
{
    system("cls");
    cout << "Transaction Successfully Executed" << endl;
    cout << "sent by = " << s1.public_key << endl;
    cout << "recieved by = " << r1.public_key << endl;
    cout << "Bitcoin Transacted = " << transaction_bitcoin << endl;
    cout << "hashcode = " << hashcode << endl;
    cout << "previous hashcode = " << previous_hash_code << endl;
    cout << "minor recieved = 12.5 bitcoins" << endl;
    universal_bitcoins = universal_bitcoins - 12.5;
}

/*
  this function generates a unique hashcode everytime a transaction is executed
  hahscode of 12 alphabets long containing numbers and alphabets.
*/

void Transaction::hashcode_generation()
{
    srand(time(0));
    cout << "\nGENERATING HASCHCODE!!" << endl;

    char alphabet[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z', '1', '2',
                          '3', '4', '5', '6', '7', '8', '9', '0'};

    string res = "";
    int temp = 12;
    while (temp--)
    {
        Sleep(600);
        cout << ".";
        res = res + alphabet[rand() % MAX];
    }
    hashcode = res;
    cout << "\nhashcode successfully generated" << endl;
    Sleep(2000);
}

int main()
{
    Sender dev;
    Reciever pranay;
    Transaction(dev, pranay);

    return 0;
}