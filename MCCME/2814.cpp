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
 
    int a, b, c;
    cin >> a >> b >> c;

    int maxK = 0, maxPrice = 0;
    for (int ka = 0; ka * a <= c; ka++) {
        int kb = (c - ka * a) / b;
        if (maxK < ka + kb || maxK == ka + kb && maxPrice < ka * a + kb * b) {
            maxK = ka + kb;
            maxPrice = ka * a + kb * b;
        }
    }

    cout << maxPrice;
}