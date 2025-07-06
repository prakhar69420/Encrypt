#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include "encryption.h"
 using namespace std;

 int main(){

    string fn;
    char mode;

    cout << "Enter Filename" << endl;

    getline(cin >> ws, fn);

    cout << "E? or D?" << endl;

    cin >> mode;

    if(mode=='E' || mode =='e'){
        if(encryptfile(fn, true)){
            cout << "Encrypted" << endl;
        }else{
             cerr<< "Error : Unnable to Perform Encryption" << endl;
        }
    }else if(mode=='D' || mode =='d'){
         if(encryptfile(fn, false)){
            cout << "Decrypted" << endl;
        }else{
             cerr<< "Error : Unnable to Perform Decryption" << endl;
        }
    }else{
        cerr<< "Invalid Input" << endl;
    }
    return 0;
 }