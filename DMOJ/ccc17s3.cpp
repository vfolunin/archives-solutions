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

    vector<int> count(2001);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    int res = 0, resCount = 0;
    for (int length = 2; length < count.size() * 2; length++) {
        int cur = 0;
        for (int i = 0; i * 2 < length; i++)
            if (length - i < count.size())
                cur += min(count[i], count[length - i]);
        if (length % 2 == 0)
            cur += count[length / 2] / 2;

        if (res < cur) {
            res = cur;
            resCount = 1;
        } else if (res == cur) {
            resCount++;
        }
    }

    cout << res << " " << resCount;
}