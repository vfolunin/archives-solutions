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
 
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int res = 0;
    for (int i = 0; i <= 1000; i++)
        res += a * i * i * i + b * i * i + c * i + d == 0 && i != e;
    
    cout << res;
}