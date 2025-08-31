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

    int row = 0, res = 0;
    for (int i = 0; i < size; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b)
            row++;
        else
            row = 0;

        res = max(res, row);
    }

    cout << res;
}