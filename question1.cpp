
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

string transpositionEncrypt(const string &text, int width)
{
    string encryptedText;
    int n = text.length();

    for (int col = 0; col < width; col++)
    {
        for (int row = col; row < n; row += width)
        {
            encryptedText += text[row];
        }
    }

    return encryptedText;
}

string transpositionDecrypt(const string &cipherText, int width)
{
    int n = cipherText.length();
    string decryptedText(n, ' ');

    int idx = 0;
    for (int col = 0; col < width; ++col)
    {
        for (int row = col; row < n; row += width)
        {
            decryptedText[row] = cipherText[idx++];
        }
    }
    return decryptedText;
}


int main(){

    string text;
    ifstream in("input.txt", ios::in);
    getline(in, text);
    int shift = 5;
    int width = 5;

    string c1 = encryption(text, shift);
    string t1 = transpositionEncrypt(c1, width);
    string t2 = transpositionDecrypt(t1, width);
    string c2 = decryption(t2, shift);

    cout<<"Plaintext: "<<text<<endl;
    cout<<"Encrypted msg: "<<t1<<endl;
    cout<<"Decrypted msg: "<<c2<<endl;


}
