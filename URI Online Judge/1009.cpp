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

    string name;
    double salary, sold;
    cin >> name >> salary >> sold;

    cout.precision(2);
    cout << "TOTAL = R$ " << fixed << salary + sold * 0.15 << "\n";
}