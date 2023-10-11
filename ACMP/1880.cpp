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

    long long sum, targetIndex;
    cin >> sum >> targetIndex;

    bool cycleFound = 0;
    vector<pair<int, long long>> seen(10, { -1, -1 });

    for (int i = 0; i < targetIndex; ) {
        if (!cycleFound && seen[sum % 10].first != -1) {
            cycleFound = 1;

            int cycleSize = i - seen[sum % 10].first;
            long long cycleDelta = sum - seen[sum % 10].second;
            int cycleCount = (targetIndex - i) / cycleSize;

            sum += cycleCount * cycleDelta;
            i += cycleCount * cycleSize;
        } else {
            seen[sum % 10] = { i, sum };

            sum += sum % 10;
            i++;
        }
    }

    cout << sum;
}