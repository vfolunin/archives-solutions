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

    string a, b;
    cin >> a >> a >> b;

    int res = 0;
    for (int ai = 0, bi = 0; ai < a.size(); ai++) {
        if (a[ai] == b[bi])
            bi++;
        else
            res++;
    }

    cout << res;
}