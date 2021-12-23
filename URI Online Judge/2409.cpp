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
    
    vector<int> a(3);
    int h, w;
    cin >> a[0] >> a[1] >> a[2] >> h >> w;

    sort(a.begin(), a.end());
    do {
        if (a[0] <= h && a[1] <= w) {
            cout << "S\n";
            return 0;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "N\n";
}