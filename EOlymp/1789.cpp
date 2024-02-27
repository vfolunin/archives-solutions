#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a) {
        cin >> value;
        value--;
    }

    long long res = 1;
    for (int i = 0; i < size; i++) {
        int j = a[i], cur = 1;
        while (j != i) {
            j = a[j];
            cur++;
        }
        res = lcm(res, cur);
    }

    cout << res;
}