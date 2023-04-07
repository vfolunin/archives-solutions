#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int a, b;
    cin >> a >> b;

    if (a > b)
        swap(a, b);

    int n = a * 2 + (a < b);
    if (n)
        cout << (int)sqrt(n);
    else
        cout << "Impossible";
}