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

    string s;
    cin >> s;

    unordered_set<int> values;

    sort(s.begin(), s.end());
    do {
        int value = stoi(s);
        if (value > 99)
            values.insert(value);
    } while (next_permutation(s.begin(), s.end()));

    cout << values.size();
}