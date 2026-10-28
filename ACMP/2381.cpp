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

    long long fire, miss, dist2, dist;
    cin >> fire >> miss >> dist2 >> dist;

    cout << (dist - miss * dist2) / (fire + 1);
}