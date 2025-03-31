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

    int needDist, t, v;
    cin >> needDist >> t >> v;

    int dist = t * v;
    int need = (needDist + dist - 1) / dist;

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int den, num;
        cin >> den >> num;

        if (num / den < need) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}