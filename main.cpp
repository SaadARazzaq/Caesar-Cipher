#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void encryptAndWriteToFile(const string &story) {
    fstream Myfile;
    Myfile.open("story.txt", ios::out);
    if (Myfile.is_open()) {
        for (int i = 0; i < story.length(); i++) {
            Myfile << int(story[i]); // Write ASCII values to the file
        }
    }
    Myfile.close();
}

void decryptAndPrintFromFile() {
    fstream Myfile;
    cout << "The deciphered numbers form the story:\n";
    Myfile.open("story.txt", ios::in);
    if (Myfile.is_open()) {
        string line;
        while (getline(Myfile, line)) {
            int num = 0;
            for (int i = 0; i < line.length(); i++) {
                num = num * 10 + (line[i] - '0'); // Convert digits to an integer
                if (num >= 32 && num <= 122) { // ASCII range for printable characters
                    char ch = static_cast<char>(num); // Convert integer to character
                    cout << ch; // Print the character
                    num = 0; // Reset the integer
                }
            }
        }
    }
    Myfile.close();
}

int main() {
    int choice;
    string story;

    do {
        cout << "Menu:\n";
        cout << "1. Encrypt and write to file\n";
        cout << "2. Decrypt and print from file\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Clear the input buffer
                cout << "Enter a story: ";
                getline(cin, story);
                encryptAndWriteToFile(story);
                break;
            case 2:
                decryptAndPrintFromFile();
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
