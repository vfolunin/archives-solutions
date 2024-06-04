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
    
    double a, b;
    cin >> a >> b;

    cout << fixed << (a * b + 10) / 3 + (a + 2 / b - 7) * 5 - a - b / a;
}