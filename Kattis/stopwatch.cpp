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

    if (n % 2) {
        cout << "still running";
        return 0;
    }

    int elapsed = 0;
    for (int i = 0; i < n; i += 2) {
        int t1, t2;
        cin >> t1 >> t2;
        elapsed += t2 - t1;
    }

    cout << elapsed;
}