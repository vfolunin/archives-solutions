#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    getline(cin, a);
    getline(cin, b);

    map<char, int> count;
    for (char c : a)
        count[c]++;
    for (char c : b)
        count[c]--;

    for (auto &[c, k] : count)
        if (k)
            cout << c;
}