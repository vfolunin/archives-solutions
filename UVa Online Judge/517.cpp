#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read(int size) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        char c;
        cin >> c;
        res = res * 2 + c - 'a';
    }
    return res;
}

void write(int n, int size) {
    for (int i = size - 1; i >= 0; i--)
        cout << (char)('a' + ((n >> i) & 1));
}

int minShift(int n, int size) {
    int res = n;
    for (int i = 0; i < size; i++) {
        n = ((n & 1) << (size - 1)) | (n >> 1);
        res = min(res, n);
    }
    return res;
}

int next(int n, int size, int transition) {
    int res = 0;
    for (int i = 0; i < size; i++) {
        int pos = 0;
        pos |= ((n >> ((i + 2) % size)) & 1) << 2;
        pos |= ((n >> i) & 1) << 1;
        pos |= ((n >> ((i + size - 1) % size)) & 1);
        res |= ((transition >> pos) & 1) << i;
    }
    return res;
}

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    int code = minShift(read(size), size);

    int transition = 0;
    for (int i = 0; i < 8; i++) {
        int pos = read(3), val = read(1);
        transition |= val << pos;
    }

    vector<vector<int>> to(1 << size, vector<int>(32));
    for (int i = 0; i < (1 << size); i++)
        to[i][0] = minShift(next(i, size, transition), size);
    for (int p = 1; p < 32; p++)
        for (int i = 0; i < (1 << size); i++)
            to[i][p] = to[to[i][p - 1]][p - 1];

    int index;
    cin >> index;

    for (int i = 31; i >= 0; i--) {
        if (index >= (1LL << i)) {
            index -= (1LL << i);
            code = to[code][i];
        }
    }

    write(code, size);
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}