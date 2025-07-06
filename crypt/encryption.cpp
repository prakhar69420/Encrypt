#include <cctype>
#include <fstream>
#include <string>
#include "encryption.h"
using namespace std;

bool caesercipher(string& content, bool encrypt) {
    int shift = encrypt ? 3 : -3;

    for (char& ch : content) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
    }

    return true;
}

bool encryptfile(const string& filename, bool encrypt) {
    ifstream inFile(filename);
    if (!inFile) {
        return false;
    }

    string content((istreambuf_iterator<char>(inFile)), {});
    inFile.close();

    if (caesercipher(content, encrypt)) {
        string outName = encrypt ? "encrypted_" + filename : "decrypted_" + filename;
        ofstream outFile(outName);
        if (!outFile) {
            return false;
        }

        outFile << content;
        outFile.close();

        return true;
    }

    return false; // Added return in case cipher fails
}
