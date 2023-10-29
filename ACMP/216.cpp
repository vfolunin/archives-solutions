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

    int size;
    cin >> size;

    multiset<int> counts;
    for (int i = 0; i < size; i++) {
        int count;
        cin >> count;
        counts.insert(count);
    }

    int res = 0;
    while (counts.size() > 1) {
        int countA = *prev(counts.end());
        counts.erase(prev(counts.end()));
        int countB = *prev(counts.end());
        counts.erase(prev(counts.end()));

        if (countA > 1)
            counts.insert(countA - 1);
        if (countB > 1)
            counts.insert(countB - 1);

        res++;
    }

    cout << res;
}