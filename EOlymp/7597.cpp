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

    int index;
    cin >> index;

    vector<int> a = {
        1 + 8 + 27 + 64 + 125 + 216 + 343 + 512 + 729 + 1000,
        1 + 2 + 6 + 24 + 120 + 720 + 5040 + 40320 + 362880 + 3628800,
        2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024,
        1 + 4 + 9 + 16 + 25 + 36 + 49 + 64 + 81 + 100,
        2 + 5 + 10 + 17 + 26 + 37 + 50 + 65 + 82 + 101,
        2 + 6 + 12 + 20 + 30 + 42 + 56 + 72 + 90 + 110
    };

    cout << a[index - 1];
}