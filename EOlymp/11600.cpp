#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getProduct(string &s) {
    int res = 1;
    for (char c : s)
        res = (res * (c - 'A' + 1)) % 47;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    cout << (getProduct(a) == getProduct(b) ? "GO" : "STAY");
}