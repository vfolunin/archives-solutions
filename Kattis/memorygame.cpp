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

    int pairCount, seenCount;
    cin >> pairCount >> seenCount; 

    vector<int> seen(pairCount);
    for (int i = 0; i < seenCount; i++) {
        int value;
        cin >> value;

        seen[value - 1]++;
    }

    int res = count(seen.begin(), seen.end(), 2);
    res += res + 1 == pairCount;

    cout << res;
}