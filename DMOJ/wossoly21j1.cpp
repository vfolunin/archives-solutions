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

    int t;
    cin >> t;

    if (t <= 0)
        cout << "S";
    else if (t < 100)
        cout << "L";
    else
        cout << "G";
}