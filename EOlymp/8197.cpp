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

    int size;
    cin >> size;

    vector<pair<string, string>> a(size);
    for (auto &[surname, name] : a)
        cin >> name >> surname;

    sort(a.begin(), a.end());

    for (auto &[surname, name] : a)
        cout << name << " " << surname << "\n";
}