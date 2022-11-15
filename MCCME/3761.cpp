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

    map<string, int> count;

    string name;
    int votes;
    while (cin >> name >> votes)
        count[name] += votes;

    for (auto &[name, votes] : count)
        cout << name << " " << votes << "\n";
}