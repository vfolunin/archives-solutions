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

    int size, targetSum;
    cin >> size >> targetSum;

    map<long long, int> seen = { {0, 1} };
    long long sum = 0, res = 0;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;

        sum += x;
        res += seen[sum - targetSum];
        seen[sum]++;
    }

    cout << res;
}