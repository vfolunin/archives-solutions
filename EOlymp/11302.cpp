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

    int a, b, ka, kb;
    cin >> a >> b >> ka >> kb;

    ka = a - ka;
    kb = b - kb;

    if ((ka + kb * 2) * 100 >= (a + b * 2) * 51)
        cout << "YES";
    else
        cout << "NO";
}