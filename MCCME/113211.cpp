#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string encode(string &message) {
    int controlBitCount = 1;
    while ((1 << controlBitCount) < controlBitCount + message.size() + 1)
        controlBitCount++;

    string code(controlBitCount + message.size(), '0');
    for (int codeI = 0, messageI = 0; codeI < code.size(); codeI++)
        if (codeI & (codeI + 1))
            code[codeI] = message[messageI++];

    for (int controlBit = 0; controlBit < controlBitCount; controlBit++) {
        int xorSum = 0;
        for (int bit = 0; bit < code.size(); bit++)
            if ((bit + 1) & (1 << controlBit))
                xorSum ^= (code[bit] - '0');
        code[(1 << controlBit) - 1] += xorSum;
    }

    return code;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string message;
    cin >> message;

    cout << encode(message);
}