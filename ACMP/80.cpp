#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void error() {
    cout << "ERROR";
    exit(0);
}

void peekNot(const string &s) {
    if (s.find(cin.peek()) != -1)
        error();
}

char readChar(const string &s) {
    if (s.find(cin.peek()) != -1)
        return cin.get();

    error();
    return 0;
}

int readInt() {
    peekNot(" +");
    
    int res;
    if (cin >> res)
        return res;

    error();
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a = readInt();
    char op = readChar("+-*/");
    int b = readInt();
    readChar("=");
    int c = readInt();
    readChar("\n");

    if (op == '+')
        cout << (a + b == c ? "YES" : "NO");
    else if (op == '-')
        cout << (a - b == c ? "YES" : "NO");
    else if (op == '*')
        cout << (a * b == c ? "YES" : "NO");
    else
        cout << (b && c * b == a ? "YES" : "NO");
}