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

    int size;
    cin >> size;

    long long res = 0;
    unordered_map<long long, int> count;

    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        for (long long sum = 3; sum < 1e15; sum *= 3)
            if (count.count(sum - value))
                res += count[sum - value];

        count[value]++;
    }

    cout << res;
}