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

    map<int, int> count;
    for (int value; cin >> value; )
        count[value]++;

    int res = 0;
    for (auto &[value, count] : count)
        res += count / 2;

    cout << res;
}