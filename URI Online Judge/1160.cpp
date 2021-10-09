#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double pa, pb, ra, rb;
    cin >> pa >> pb >> ra >> rb;
    ra /= 100;
    rb /= 100;

    int res = 0;
    while (pa <= pb && res <= 100) {
        pa = (int)(pa + pa * ra);
        pb = (int)(pb + pb * rb);
        res++;
    }

    if (res > 100)
        cout << "Mais de 1 seculo.\n";
    else
        cout << res << " anos.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}