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

    int count, start;
    cin >> count >> start;

    int res = (start + start + count - 1) * count / 2;
    for (int i = 0; i < count - 1; i++) {
        int value;
        cin >> value;

        res -= value;
    }

    cout << res;
}