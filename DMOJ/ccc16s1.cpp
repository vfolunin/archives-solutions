#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> read() {
    string s;
    cin >> s;

    vector<int> count(26);
    for (char c : s)
        if (c != '*')
            count[c - 'a']++;
    return count;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> aCount = read();
    vector<int> bCount = read();

    for (int i = 0; i < aCount.size(); i++) {
        if (aCount[i] < bCount[i]) {
            cout << "N";
            return 0;
        }
    }

    cout << "A";
}