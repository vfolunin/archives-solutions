#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int canvasCount;
    cin >> canvasCount;

    multiset<long long> canvas;
    for (int i = 0; i < canvasCount; i++) {
        int size;
        cin >> size;
        canvas.insert(size);
    }

    long long res = 0;
    while (canvas.size() > 1) {
        long long a = *canvas.begin();
        canvas.erase(canvas.begin());

        long long b = *canvas.begin();
        canvas.erase(canvas.begin());

        res += a + b;
        canvas.insert(a + b);
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}