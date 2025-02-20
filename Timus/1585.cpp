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
    cin.ignore();

    unordered_map<string, int> count;
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        string s;
        getline(cin, s);

        maxCount = max(maxCount, ++count[s]);
    }

    for (auto &[s, count] : count)
        if (count == maxCount)
            cout << s;
}