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

    long long t, ta, ka, tb, kb;
    cin >> t >> ta >> ka >> tb >> kb;

    long long kab = max(0LL, (t - ta) * ka) + max(0LL, (t - ta - tb) * kb);
    long long kba = max(0LL, (t - tb) * kb) + max(0LL, (t - tb - ta) * ka);

    cout << max(kab, kba);
}