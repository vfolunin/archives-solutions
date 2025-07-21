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
    
    int limit;
    cin >> limit;

    int res = 0;
    for (int h = 5; h <= 23; h++)
        for (int w = 4; w <= 23; w++)
            res += 2 * (w + h - 2) <= limit;

    cout << res;
}