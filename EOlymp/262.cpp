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

    vector<int> a(size + 2);
    for (int i = 1; i <= size; i++)
        cin >> a[i];

    int maxJump;
    cin >> maxJump;

    vector<int> res(a.size(), -1e9);
    res[0] = 0;

    for (int i = 1; i < res.size(); i++)
        for (int jump = 1; jump <= i && jump <= maxJump; jump++)
            res[i] = max(res[i], res[i - jump] + a[i]);

    cout << res.back();
}