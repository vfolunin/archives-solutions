#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int dayCount;
    cin >> dayCount;

    if (!dayCount)
        return 0;

    multiset<int> s;
    long long cost = 0;
    for (int i = 0; i < dayCount; i++) {
        int billCount;
        cin >> billCount;
        
        for (int j = 0; j < billCount; j++) {
            int billPrice;
            cin >> billPrice;
            s.insert(billPrice);
        }

        int minPrice = *s.begin();
        s.erase(s.begin());
        int maxPrice = *--s.end();
        s.erase(--s.end());
        cost += maxPrice - minPrice;
    }

    cout << cost << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}