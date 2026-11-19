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
    cin >> s >> s;

    for (int firstValue : { 0, 1 }) {
        vector<int> used(2);
        int j = 0;

        for (int i = 0; i < s.size() + 2; i++) {
            int value = firstValue ^ (i % 2);
            if (j < s.size() && s[j] == value + '0')
                j++;
            else
                used[value]++;
        }

        if (j == s.size() && used[0] && used[1]) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}