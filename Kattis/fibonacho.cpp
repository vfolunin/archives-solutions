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

    int a3, a4, a5;
    cin >> a3 >> a4 >> a5;

    int a2 = a5 - a4;
    int a1 = a4 - a3;
    int a0 = a3 - a2;

    cout << a0 << " " << a1 << " " << a2;
}