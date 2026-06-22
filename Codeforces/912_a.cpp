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

    long long haveA, haveB, x, y, z;
    cin >> haveA >> haveB >> x >> y >> z;

    long long needA = 2 * x + y;
    long long needB = y + 3 * z;

    cout << max(0LL, needA - haveA) + max(0LL, needB - haveB);
}