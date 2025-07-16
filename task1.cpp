
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeFile(const string& fileName) {
    ofstream fout(fileName);  // Write mode (overwrites file)
    if (!fout) {
        cout << "Error opening file for writing.\n";
        return;
    }
    string data;
    cout << "Enter text to write to file (end with 'END'):\n";
    while (true) {
        getline(cin, data);
        if (data == "END") break;
        fout << data << endl;
    }
    fout.close();
    cout << "Data written successfully.\n";
}

void appendFile(const string& fileName) {
    ofstream fout(fileName, ios::app);  // Append mode
    if (!fout) {
        cout << "Error opening file for appending.\n";
        return;
    }
    string data;
    cout << "Enter text to append (end with 'END'):\n";
    while (true) {
        getline(cin, data);
        if (data == "END") break;
        fout << data << endl;
    }
    fout.close();
    cout << "Data appended successfully.\n";
}

void readFile(const string& fileName) {
    ifstream fin(fileName);
    if (!fin) {
        cout << "Error opening file for reading.\n";
        return;
    }
    string line;
    cout << "\nContents of the file:\n";
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

int main() {
    string fileName = "sample.txt";
    int choice;

    do {
        cout << "\n====== FILE MANAGEMENT TOOL ======\n";
        cout << "1. Write to File (Overwrite)\n";
        cout << "2. Append to File\n";
        cout << "3. Read from File\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character from previous input

        switch (choice) {
            case 1: writeFile(fileName); break;
            case 2: appendFile(fileName); break;
            case 3: readFile(fileName); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
