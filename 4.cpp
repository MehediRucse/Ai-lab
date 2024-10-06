
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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

int main()
{
    string plainText;
    ifstream in("input.txt", ios::in);
    getline(in, plainText);

    int width;
    cout << "Enter the width for encryption: ";
    cin >> width;

    string encryptedText = transpositionEncrypt(plainText, width);
    string cipher = transpositionEncrypt(encryptedText, width);
    string temp = transpositionDecrypt(cipher, width);
    string decryptedText = transpositionDecrypt(encryptedText, width);

    cout << "Input Text: " << plainText << endl;
    cout << "Ciphertext :" << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
