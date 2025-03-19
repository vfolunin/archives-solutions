#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("butyavki.in", "r", stdin);
    freopen("butyavki.out", "w", stdout);

    long long num, size;
    cin >> num >> size;

    vector<long long> den(size);
    long long bestI, bestRemainder = 2e18;

    for (int i = 0; i < size; i++) {
        cin >> den[i];

        long long remainder = num % den[i];
        if (bestRemainder > remainder) {
            bestRemainder = remainder;
            bestI = i;
        }
    }

    cout << bestI + 1 << " " << num / den[bestI];
}