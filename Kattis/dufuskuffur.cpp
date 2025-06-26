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

    int a, b;
    cin >> a >> b;

    if (a < b)
        cout << "Dufur passa";
    else if (a > b)
        cout << "Dufur passa ekki";
    else
        cout << "Dufur passa fullkomlega";
}