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

    double n1, t1, v1, n2, v2;
    cin >> n1 >> t1 >> v1 >> n2 >> v2;

    cout << fixed << t1 / v1 * v2 * n1 / n2;
}