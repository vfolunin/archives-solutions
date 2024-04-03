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

    unordered_map<string, int> countA;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;
        countA[s]++;
    }

    unordered_map<string, int> countB;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;
        countB[s]++;
    }

    int res = 0;
    for (auto &[s, count] : countA)
        res += min(count, countB[s]);

    cout << res;
}