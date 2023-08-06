#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool numLess(string &a, string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(3);
    for (string &s : a)
        cin >> s;

    cout << *max_element(a.begin(), a.end(), numLess);
}