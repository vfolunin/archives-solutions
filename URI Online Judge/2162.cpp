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

    vector<int> h(size);
    for (int &h : h)
        cin >> h;

    if (size == 2 && h[0] == h[1]) {
        cout << "0\n";
        return 0;
    }

    for (int i = 1; i + 1 < size; i++) {
        if (h[i - 1] < h[i] && h[i] > h[i + 1] ||
            h[i - 1] > h[i] && h[i] < h[i + 1])
            continue;
        cout << "0\n";
        return 0;
    }

    cout << "1\n";
}