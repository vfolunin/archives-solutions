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

    int size, queryCount;
    cin >> size >> queryCount;
    cin.ignore();

    vector<string> a(size);
    for (string &s : a)
        getline(cin, s);

    unordered_map<string, int> index;
    for (int i = 0; i < queryCount; i++) {
        string s;
        getline(cin, s);

        cout << a[index[s]++] << "\n";
    }
}