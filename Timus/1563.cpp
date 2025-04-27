#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    cin.ignore();

    unordered_set<string> seen;
    int res = 0;
    for (int i = 0; i < size; i++) {
        string s;
        getline(cin, s);

        res += seen.count(s);
        seen.insert(s);
    }

    cout << res;
}