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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int res = 0;
    for (int divisor = 2; divisor <= 1000; divisor++) {
        int cur = 0;
        for (int value : a) {
            if (value % divisor == 0)
                cur++;
            else
                cur = 0;
            res = max(res, cur);
        }
    }

    cout << res;
}