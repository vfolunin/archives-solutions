#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

unsigned int getRandom(unsigned int a, unsigned int b) {
    static unsigned int cur = 0;
    cur = cur * a + b;
    return cur >> 8;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    unsigned int a, b;
    cin >> size >> a >> b;

    vector<unsigned int> values(size);
    for (unsigned int &value : values) {
        unsigned int x = getRandom(a, b);
        unsigned int y = getRandom(a, b);
        value = (x << 8) ^ y;
    }

    nth_element(values.begin(), values.begin() + size / 2, values.end());
    unsigned int targetValue = values[size / 2];

    long long res = 0;
    for (unsigned int &value : values)
        res += abs((long long)value - targetValue);

    cout << res;
}