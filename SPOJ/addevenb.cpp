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

    int size, maxDiff;
    cin >> size >> maxDiff;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    vector<int> count(2);
    long long res = 0;

    for (int i = 0; i < size; i++) {
        if (i > maxDiff)
            count[a[i - maxDiff - 1] % 2]--;

        res += count[a[i] % 2];

        count[a[i] % 2]++;
    }

    cout << res;
}