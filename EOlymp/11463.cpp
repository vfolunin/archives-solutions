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

    long long friendCount, sheetCount;
    cin >> friendCount >> sheetCount;

    long long res = 0;
    for (int count : { 2, 5, 8 })
        res += (friendCount * count + sheetCount - 1) / sheetCount;

    cout << res;
}