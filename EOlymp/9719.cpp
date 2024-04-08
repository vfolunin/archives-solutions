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

    map<string, int> salary;

    string name;
    int value;
    while (cin >> name >> value)
        salary[name] = value;

    for (auto &[name, value] : salary)
        cout << name << " " << value << "\n";
}