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

    vector<long long> a;
    for (long long value; cin >> value; )
        a.push_back(value);
    
    long long l = -1e18, r = 1e18;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < l || a[i] > r) {
            cout << "NO";
            return 0;
        }
        if (i + 1 < a.size()) {
            if (a[i] < a[i + 1])
                l = a[i] + 1;
            else
                r = a[i] - 1;
        }
    }
    
    cout << "YES";
}