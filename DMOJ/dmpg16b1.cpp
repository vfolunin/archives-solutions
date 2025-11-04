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

    vector<int> nominal = { 5, 10, 25, 100, 200 };
    int res = 0;

    for (int value : nominal) {
        int count;
        cin >> count;

        res += count * value;
    }

    cout << res;
}