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

    double oldSalary;
    cin >> oldSalary;

    vector<int> limit = { 400, 800, 1200, 2000, (int)1e9 };
    int index = 0;
    while (oldSalary > limit[index])
        index++;

    vector<int> percent = { 15, 12, 10, 7, 4 };
    double newSalary = oldSalary * (1 + percent[index] / 100.0);

    cout.precision(2);
    cout << "Novo salario: " << fixed << newSalary << "\n";
    cout << "Reajuste ganho: " << fixed << newSalary - oldSalary << "\n";
    cout << "Em percentual: " << percent[index] << " %\n";
}