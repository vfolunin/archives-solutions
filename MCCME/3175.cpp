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
 
    int size, segmentCount;
    cin >> size >> segmentCount;

    string res(size, 'I');
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;
        fill(res.begin() + l - 1, res.begin() + r, '.');
    }

    cout << res;
}