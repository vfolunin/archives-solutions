#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rotate(string &s) {
    int sum = 0;
    for (char c : s)
        sum += c - 'A';
    for (char &c : s)
        c = (c - 'A' + sum) % 26 + 'A';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string cypher;
    cin >> cypher;

    string a = cypher.substr(0, cypher.size() / 2);
    string b = cypher.substr(cypher.size() / 2);

    rotate(a);
    rotate(b);

    for (int i = 0; i < a.size(); i++)
        a[i] = (a[i] - 'A' + b[i] - 'A') % 26 + 'A';

    cout << a;
}