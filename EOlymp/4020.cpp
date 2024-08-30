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

    int size, maxJump;
    cin >> size >> maxJump;
    maxJump++;

    vector<int> res(size + 1, 1e9);
    res[0] = 0;

    for (int i = 1; i <= size; i++) {
        int price;
        cin >> price;

        for (int jump = 1; jump <= maxJump && jump <= i; jump++)
            res[i] = min(res[i], res[i - jump] + price);
    }

    cout << res.back();
}