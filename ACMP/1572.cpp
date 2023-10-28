#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    vector<int> mask = {
        0b110101011, 0b001100010, 0b100100101, 0b101010100, 0b010110010,
        0b110010011, 0b001011011, 0b101001000, 0b110111011, 0b110110100
    };

    int add = 0, sub = 0;
    for (int i = 0; i < a.size(); i++) {
        add += ones(mask[b[i] - '0'] & ~mask[a[i] - '0']);
        sub += ones(mask[a[i] - '0'] & ~mask[b[i] - '0']);
    }

    cout << max(add, sub);
}