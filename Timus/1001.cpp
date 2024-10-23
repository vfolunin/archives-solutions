#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<double> a;
    for (double value; cin >> value; )
        a.push_back(value);

    for (int i = a.size() - 1; i >= 0; i--)
        cout << fixed << sqrt(a[i]) << "\n";
}