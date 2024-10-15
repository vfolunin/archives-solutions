#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetSum;
    cin >> size >> targetSum;

    unordered_map<long long, int> count;
    long long sum = 0;
    count[sum] = 1;

    long long res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        res += count[sum - targetSum];
        count[sum]++;
    }

    cout << res;
}