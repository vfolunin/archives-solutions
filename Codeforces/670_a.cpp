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

    int minCount = (n / 7) * 2 + (n % 7 == 6);
    int maxCount = (n / 7) * 2 + min(n % 7, 2);

    cout << minCount << " " << maxCount;
}