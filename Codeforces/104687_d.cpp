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

    int al, ar, bl, br, sum;
    cin >> al >> ar >> bl >> br >> sum;

    bl = max(bl, sum - ar);
    br = min(br, sum - al);

    cout << max(0, br - bl + 1);
}