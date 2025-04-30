#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileEncryptor {
private:
    string filename;
    int encryptionKey;

public:
    FileEncryptor(string fname, int key) {
        filename = fname;
        encryptionKey = key;
    }

    void encryptAndWrite(string message) {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error opening file for writing.\n";
            return;
        }

        for (char ch : message) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                ch = (ch - base + encryptionKey) % 26 + base;
            }
            outFile << ch;
        }

        outFile.close();
        cout << "Message successfully encrypted and stored in " << filename << endl;
    }

    string readAndDecrypt() {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Error opening file for reading.\n";
            return "";
        }

        string decrypted = "";
        char ch;
        while (inFile.get(ch)) {
            if (isalpha(ch)) {
                char base = islower(ch) ? 'a' : 'A';
                ch = (ch - base - encryptionKey + 26) % 26 + base;
            }
            decrypted += ch;
        }

        inFile.close();
        return decrypted;
    }

    void displayFileContents() {
        string message = readAndDecrypt();
        if (!message.empty()) {
            cout << "Decrypted Message: " << message << endl;
        }
    }
};

int main() {
    FileEncryptor fe("data.txt", 3);
    int choice;
    string message;

    do {
        cout << "\n1. Encrypt and Save Message\n";
        cout << "2. Read and Decrypt Message\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter a message to encrypt: ";
            getline(cin, message);
            fe.encryptAndWrite(message);
        } else if (choice == 2) {
            cout << "Reading and decrypting file...\n";
            fe.displayFileContents();
        } else if (choice == 3) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}

