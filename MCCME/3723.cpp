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

    int a;
    double b;
    cin >> a >> b;

    cout << a << " " << &a << "\n";
    cout << b << " " << &b;
}