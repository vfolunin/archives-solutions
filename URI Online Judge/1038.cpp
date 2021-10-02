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

    int id, count;
    cin >> id >> count;

    vector<double> price = { 4, 4.5, 5, 2, 1.5 };

    cout.precision(2);
    cout << "Total: R$ " << fixed << price[id - 1] * count << "\n";
}