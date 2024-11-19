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

    vector<int> res(size + 1, 0);
    for (int i = 2; i <= size; i++)
        for (int l = 1, r = i - 1; l <= r; l++, r--)
            res[i] = max(res[i], res[l] + res[r] + l);
    
    cout << res[size];
}