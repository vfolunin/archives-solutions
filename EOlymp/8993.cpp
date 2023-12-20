#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readCount() {
    string s;
    cin >> s;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;
    return count;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> aCount = readCount();
    vector<int> bCount = readCount();

    for (int i = 0; i < aCount.size(); i++) {
        if (aCount[i] < bCount[i]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Ok";
}