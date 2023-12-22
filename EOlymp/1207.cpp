#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a(1e6 + 1);
    a[0] = 1;

    for (int i = 1; i < a.size(); i++) {
        int i1 = i - sqrt(i);
        int i2 = log(i);
        int i3 = i * sin(i) * sin(i);
        a[i] = (a[i1] + a[i2] + a[i3]) % (int)1e6;
    }

    for (int i; cin >> i; )
        if (i != -1)
            cout << a[i] << "\n";
}