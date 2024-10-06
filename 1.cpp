#include<bits/stdc++.h>
using namespace std;

string encryption (string text, int shift){
    string result;

    for(auto &i : text){
        if(i>='A' && i<='Z'){
            result += (i-'A'+shift)%26 + 'A';
        }
        else if(i>='a' && i<='z'){
            result += (i-'a'+shift)%26 + 'a';
        }
        else result += i;

    }
    return result;
}

string decryption (string text, int shift){
    string result;

    for(auto &i : text){
        if(i>='A' && i<='Z'){
            result += (i-'A'- shift + 26)%26 + 'A';
        }
        else if(i>='a' && i<='z'){
            result += (i - 'a' - shift + 26)%26 + 'a';
        }
        else result += i;

    }
    return result;
}

int main(){

    string text;
    ifstream in("input.txt");
    getline(in, text);
    int shift = 3;

    string enc, dec;

    enc = encryption(text, shift);
    dec = decryption(enc, shift);
    cout<<"Original text: "<<text<<endl;
    cout<<"Encryption :"<<enc<<endl;
    cout<<"Decryption :"<<dec<<endl;

}
