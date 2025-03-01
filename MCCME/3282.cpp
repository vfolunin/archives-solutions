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

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    sort(a.begin(), a.end(), [](string &lhs, string &rhs) {
        return lhs.size() < rhs.size();
    });

    for (string &s : a)
        cout << s << "\n";
}