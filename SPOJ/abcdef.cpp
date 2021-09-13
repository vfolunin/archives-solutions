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

    int n;
    cin >> n;

    vector<int> vals(n);
    for (int &val : vals)
        cin >> val;

    map<int, int> count;

    for (int a : vals)
        for (int b : vals)
            for (int c : vals)
                count[a * b + c]++;

    long long res = 0;

    for (int d : vals)
        if (d)
            for (int e : vals)
                for (int f : vals)
                    res += count[d * (e + f)];

    cout << res;
}