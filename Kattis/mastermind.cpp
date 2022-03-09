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

    string a, b;
    cin >> a >> a >> b;

    map<char, int> aCount, bCount;

    int bulls = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) {
            bulls++;
        } else {
            aCount[a[i]]++;
            bCount[b[i]]++;
        }
    }

    int cows = 0;
    for (auto &[c, count] : aCount)
        cows += min(count, bCount[c]);

    cout << bulls << " " << cows;
}