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

    string s;
    cin >> s;

    vector<int> count(10);
    for (char c : s)
        if (isdigit(c))
            count[c - '0']++;

    bool found = 0;
    for (int i = 0; i < count.size(); i++) {
        if (count[i] > 1) {
            cout << i;
            found = 1;
        }
    }

    if (!found)
        cout << "NO";
}