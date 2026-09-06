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

    int employeeCount, threshold, limit;
    cin >> employeeCount >> threshold >> limit;

    vector<pair<string, int>> employees(employeeCount);
    for (auto &[name, salary] : employees)
        cin >> name >> salary;

    sort(employees.begin(), employees.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    int salarySum = 0;
    for (int i = 0; i < limit; i++) {
        salarySum += employees[i].second;
        if (salarySum >= threshold) {
            limit = i + 1;
            break;
        }
    }

    if (salarySum >= threshold) {
        cout << limit << "\n";
        for (int i = 0; i < limit; i++)
            cout << employees[i].first << ", YOU ARE FIRED!\n";
    } else {
        cout << "impossible";
    }
}