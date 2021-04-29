#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void subtractMin(int &a, int &b) {
    int m = min(a, b);
    a -= m;
    b -= m;
}

bool solve() {
    vector<int> count(7);
    for (int i = 1; i <= 6; i++)
        cin >> count[i];

    if (!*max_element(count.begin(), count.end()))
        return 0;

    int res = count[6];

    res += count[5];
    count[1] -= min(count[1], 11 * count[5]);
    
    res += count[4];
    int slots2 = 5 * count[4];
    subtractMin(count[2], slots2);
    int slots1 = 4 * slots2;
    subtractMin(count[1], slots1);

    res += (count[3] + 3) / 4;
    if (count[3] % 4) {
        int slots3 = (4 - count[3] % 4) % 4;
        int slots2 = slots3 * 2 - 1;
        subtractMin(count[2], slots2);
        int slots1 = slots3 + 4 + slots2 * 4;
        subtractMin(count[1], slots1);
    }

    res += (count[2] + 8) / 9;
    if (count[2] % 9) {
        int slots2 = (9 - count[2] % 9) % 9;
        int slots1 = slots2 * 4;
        subtractMin(count[1], slots1);
    }

    res += (count[1] + 35) / 36;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}