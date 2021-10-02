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
    for (int &x : a)
        cin >> x;

    cout << *max_element(a.begin(), a.end());
    cout << " eh o maior\n";
}