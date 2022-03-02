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

    long long aUnique, bUnique, aReuse, bReuse;
    cin >> aUnique >> bUnique >> aReuse >> bReuse;

    long long res = aReuse * bReuse;
    if (aReuse)
        res += bUnique;
    if (bReuse)
        res += aUnique;
    if (!aReuse && !bReuse)
        res += min(aUnique, bUnique);

    cout << res;
}