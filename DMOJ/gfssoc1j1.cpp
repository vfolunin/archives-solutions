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

    int threshold, size;
    cin >> threshold >> size;

    int res = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        res += value >= threshold;
    }

    cout << res;
}