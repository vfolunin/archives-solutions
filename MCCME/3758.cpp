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

    int dayCount, partyCount;
    cin >> dayCount >> partyCount;

    vector<int> days(dayCount);

    for (int i = 0; i < partyCount; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = 0; a + j * b <= dayCount; j++)
            days[a + j * b - 1] = 1;
    }

    int res = 0;
    for (int i = 0; i < dayCount; i++)
        res += days[i] && i % 7 < 5;

    cout << res;
}