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

    int size, l = 2, r;
    cin >> size >> r;
    r--;

    for (int i = 0; i < size; i++) {
        int value;
        string type;
        cin >> value >> type;

        if (type == "SAFE")
            l = max(l, value + 1);
        else
            r = min(r, value - 1);
    }

    cout << l << " " << r;
}