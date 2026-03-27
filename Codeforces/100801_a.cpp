#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);

    double h, w;
    cin >> h >> w;

    if (h > w)
        swap(h, w);

    cout << fixed << max(min(h / 2, w / 2), min(h, w / 3));
}