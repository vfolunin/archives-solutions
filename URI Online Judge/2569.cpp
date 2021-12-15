#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int convert(string s) {
    for (char &c : s)
        if (c == '7')
            c = '0';
    return stoi(s);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string sa, op, sb;
    cin >> sa >> op >> sb;

    int a = convert(sa);
    int b = convert(sb);
    int c = (op == "+" ? a + b : a * b);
    string sc = to_string(c);

    cout << convert(sc) << "\n";
}