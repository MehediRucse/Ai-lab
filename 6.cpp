#include<bits/stdc++.h>
using namespace std;

long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

vector<long long> splitMessage(string message, int chunkSize) {
    vector<long long> chunks;
    for (size_t i = 0; i < message.length(); i += chunkSize) {
        string chunk = message.substr(i, chunkSize);
        chunks.push_back(stoll(chunk));
    }
    return chunks;
}

int main() {
    long long e = 79;
    long long d = 1019;
    long long n = 3337;

    string message = "6882326879666683";

    vector<long long> chunks = splitMessage(message, 3);

    string encryptedString;
    for (long long chunk : chunks) {
        long long encrypted = powerMod(chunk, e, n);
        encryptedString += to_string(encrypted) + " ";
    }

    cout << "Concatenated Encrypted String: " << encryptedString << endl;

    string decryptedString;
    size_t pos = 0;
    while ((pos = encryptedString.find(' ')) != string::npos) {
        string token = encryptedString.substr(0, pos);
        long long encryptedChunk = stoll(token);
        long long decrypted = powerMod(encryptedChunk, d, n);
        decryptedString += to_string(decrypted);
        encryptedString.erase(0, pos + 1);
    }

    cout << "Concatenated Decrypted String: " << decryptedString << endl;

    return 0;
}
