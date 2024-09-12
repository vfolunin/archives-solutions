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

    vector<int> a(3);
    for (int &value : a)
        cin >> value;

    vector<string> name = { "Monnei", "Fjee", "Dolladollabilljoll" };

    cout << name[min_element(a.begin(), a.end()) - a.begin()];
}