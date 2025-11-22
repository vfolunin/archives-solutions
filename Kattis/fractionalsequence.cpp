#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long index;
    cin >> index;
    index--;

    for (int block = 1; 1; block++) {
        if (index >= block) {
            index -= block;
        } else {
            cout << block;

            long long d = gcd(index, block);
            index /= d;
            block /= d;

            if (index)
                cout << " " << index << "/" << block;

            return 0;
        }
    }
}