#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    char aBuf[20], bBuf[20], cBuf[20];
    scanf(" %[0-9]+%[0-9]=%[0-9]", aBuf, bBuf, cBuf);

    string a = aBuf, b = bBuf, c = cBuf;    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());

    printf("%s", stoi(a) + stoi(b) == stoi(c) ? "True\n" : "False\n");

    return a != "0" || b != "0" || c != "0";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}