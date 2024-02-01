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

    int targetSum;
    cin >> targetSum;

    int res = 0;
    for (int i = 0; i < 1e4; i++)
        res += i / 100 + i % 100 == targetSum;

    cout << res;
}