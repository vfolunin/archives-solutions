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

    int n, k;
    cin >> n >> k;

    vector<int> crossed(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!crossed[i]) {
            for (int j = i; j <= n; j += i) {
                if (!crossed[j]) {
                    crossed[j] = 1;
                    k--;
                    if (!k) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
}