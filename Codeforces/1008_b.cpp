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

    int last = 2e9;
    for (int i = 0; i < size; i++) {
        int h, w;
        cin >> h >> w;

        if (h > w)
            swap(h, w);

        if (last >= w) {
            last = w;
        } else if (last >= h) {
            last = h;
        } else {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}