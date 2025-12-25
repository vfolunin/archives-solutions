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

    vector<long long> res(size);
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (i)
            res[i] = res[i - 1];
        res[i] = max(res[i], value + (i > 1 ? res[i - 2] : 0));
    }

    cout << res.back();
}