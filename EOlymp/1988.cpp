#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getLisSize(vector<int> &a) {
    vector<int> lisLast(a.size() + 1, 1e9);
    lisLast[0] = -1e9;

    for (int value : a)
        *lower_bound(lisLast.begin(), lisLast.end(), value) = value;

    int lisSize = a.size();
    while (lisLast[lisSize] == 1e9)
        lisSize--;
    return lisSize;
}

bool solve() {
    long long a, b, mod, size;
    if (!(cin >> a >> b >> mod >> size))
        return 0;

    vector<int> values(size + 1);
    values[0] = a + b;
    values[1] = a - b;
    for (int i = 2; i < values.size(); i++)
        values[i] = (a * values[i - 2] + b * values[i - 1]) % mod;
    
    cout << getLisSize(values) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}