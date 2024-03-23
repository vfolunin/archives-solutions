#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int salaryCount;
    cin >> salaryCount;

    unordered_map<string, int> salary;
    for (int i = 0; i < salaryCount; i++) {
        string surname;
        cin >> surname >> salary[surname];
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        string surname;
        cin >> surname;

        cout << (salary.count(surname) ? salary[surname] : -1) << "\n";
    }
}