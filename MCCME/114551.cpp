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
 
    int n, a, b;
    cin >> n >> a >> b;

    cout << clamp(a + b - n + 1, 1, n) << " " << min(a + b - 1, n);
}