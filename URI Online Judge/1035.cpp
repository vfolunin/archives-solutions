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

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b > c && d > a && c + d > a + b && c > 0 && d > 0 && a % 2 == 0)
        cout << "Valores aceitos\n";
    else
        cout << "Valores nao aceitos\n";
}