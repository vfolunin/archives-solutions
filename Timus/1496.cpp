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

    unordered_map<string, int> count;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        count[s]++;
    }

    for (auto &[s, count] : count)
        if (count > 1)
            cout << s << "\n";
}