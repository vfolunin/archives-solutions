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

    vector<int> used(26);
    for (int i = 0; i < 25; i++) {
        char c;
        cin >> c;
        used[c - 'A'] = 1;
    }

    cout << (char)(find(used.begin(), used.end(), 0) - used.begin() + 'A');
}