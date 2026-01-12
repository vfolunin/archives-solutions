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

    long long h, w;
    cin >> h >> w;

    vector<string> frac = { ".00", ".25", ".50", ".75" };

    cout << h * w / 4 << frac[h * w % 4] << "\n";
}