#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
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

    vector<string> b(size);
    for (string &s : b)
        cin >> s;

    unordered_map<string, string> partner;
    for (int i = 0; i < a.size(); i++)
        partner[a[i]] = b[i];

    for (auto &[a, b] : partner) {
        if (a == b || partner[b] != a) {
            cout << "bad";
            return 0;
        }
    }

    cout << "good";
}