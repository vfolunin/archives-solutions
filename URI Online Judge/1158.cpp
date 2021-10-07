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

    for (int i = 0; i < n; i++) {
        int from, count;
        cin >> from >> count;

        int res = 0;
        for (int j = 0; j < count; from++) {
            if (from % 2) {
                res += from;
                j++;
            }
        }

        cout << res << "\n";
    }
}