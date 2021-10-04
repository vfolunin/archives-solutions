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

    double salary;
    cin >> salary;

    vector<double> limit = { 2000, 1000, 1500, 1e9 };
    vector<double> percent = { 0, 0.08, 0.18, 0.28 };

    double tax = 0;
    for (int i = 0; i < limit.size(); i++) {
        double part = min(salary, limit[i]);
        tax += part * percent[i];
        salary -= part;
    }

    if (!tax) {
        cout << "Isento\n";
    } else {
        cout.precision(2);
        cout << "R$ " << fixed << tax << "\n";
    }
}