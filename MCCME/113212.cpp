#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string decode(string &code) {
    int controlBitCount = 1, messageBitCount = code.size() - 1;
    while ((1LL << controlBitCount) < controlBitCount + messageBitCount + 1) {
        controlBitCount++;
        messageBitCount--;
    }

    int syndrome = 0;
    for (int controlBit = 0; controlBit < controlBitCount; controlBit++) {
        int xorSum = 0;
        for (int bit = 0; bit < code.size(); bit++)
            if ((bit + 1) & (1 << controlBit))
                xorSum ^= (code[bit] - '0');
        syndrome ^= xorSum << controlBit;
    }

    if (syndrome)
        code[syndrome - 1] ^= 1;

    string message(messageBitCount, '0');
    for (int codeI = 0, messageI = 0; codeI < code.size(); codeI++)
        if (codeI & (codeI + 1))
            message[messageI++] = code[codeI];

    return message;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string code;
    cin >> code;

    cout << decode(code);
}