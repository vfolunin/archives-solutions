#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i && v[i - 1] > 0)
            v[i] += v[i - 1];
    }

    int m = *max_element(v.begin(), v.end());
    if (m > 0)
        cout << "The maximum winning streak is " << m << ".\n";
    else
        cout << "Losing streak.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}