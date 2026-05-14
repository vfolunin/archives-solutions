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

    int size;
    cin >> size;

    int res = 0, prevHeight = 0;
    for (int i = 0; i < size; i++) {
        int height;
        cin >> height;

        res += (i > 0) + abs(height - prevHeight) + 1;
        prevHeight = height;
    }

    cout << res;
}