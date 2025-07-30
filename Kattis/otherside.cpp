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

    int wolfCount, sheepCount, cabbageCount, limit;
    cin >> wolfCount >> sheepCount >> cabbageCount >> limit;

    int a = wolfCount + cabbageCount, b = sheepCount;

    if (a < limit || b < limit || a == limit && b <= limit * 2 || b == limit && a <= limit * 2)
        cout << "YES";
    else
        cout << "NO";
}