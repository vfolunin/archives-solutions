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

    int numCount, den;
    cin >> numCount >> den;

    map<int, int> ratios;
    for (int i = 0; i < numCount; i++) {
        int num;
        cin >> num;
        ratios[num / den]++;
    }

    long long res = 0;
    for (auto &[ratio, count] : ratios)
        res += count * (count - 1LL) / 2;

    cout << res;
}