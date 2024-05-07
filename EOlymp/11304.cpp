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

    int a, b, c, d, size;
    cin >> a >> b >> c >> d >> size;

    vector<int> work(size);

    for (int i = 0; i < work.size(); i++)
        work[i] = i % (a + b) < a;

    for (int i = c - 1; i < work.size(); i += c)
        work[i] = 0;

    for (int i = d - 1; i < work.size(); i += d)
        if (work[i])
            work[i]++;

    int res = 0;
    for (int value : work)
        res += value;

    cout << res;
}