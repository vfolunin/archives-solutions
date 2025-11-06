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

    if (a + d > b + c || a + d == b + c && d > b)
        cout << "Persepolis";
    else if (a + d < b + c || a + d == b + c && b > d)
        cout << "Esteghlal";
    else
        cout << "Penalty";
}