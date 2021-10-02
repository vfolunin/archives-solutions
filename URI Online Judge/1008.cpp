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

    int id, hourCount;
    double hourSalary;
    cin >> id >> hourCount >> hourSalary;

    cout.precision(2);
    cout << "NUMBER = " << id << "\n";
    cout << "SALARY = U$ " << fixed << hourCount * hourSalary << "\n";
}