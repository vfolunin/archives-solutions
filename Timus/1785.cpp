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

    vector<int> from = { 1, 5, 10, 20, 50, 100, 250, 500, 1000 };
    vector<string> name = { "few", "several", "pack", "lots", "horde", "throng", "swarm", "zounds", "legion" };

    cout << name[upper_bound(from.begin(), from.end(), n) - from.begin() - 1];
}