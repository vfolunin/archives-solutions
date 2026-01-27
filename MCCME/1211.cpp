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

    int size, maxValue, modDigitCount;
    string s;
    cin >> size >> maxValue >> modDigitCount >> s;

    long long mod = 1;
    for (int i = 0; i < modDigitCount; i++)
        mod *= 10;

    vector<long long> ways(s.size() + 1);
    ways[0] = 1;

    for (int size = 1; size <= s.size(); size++) {
        for (int partSize = 1, value = 0, power = 1; partSize <= size && power <= maxValue; partSize++, power *= 10) {
            if (s[size - partSize] == '0' && partSize != 1)
                continue;

            value += (s[size - partSize] - '0') * power;
            if (value > maxValue)
                break;

            ways[size] = (ways[size] + ways[size - partSize]) % mod;
        }
    }

    cout << ways.back();
}