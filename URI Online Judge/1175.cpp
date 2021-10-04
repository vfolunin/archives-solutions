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

    vector<int> a(20);
    for (int &x : a)
        cin >> x;

    reverse(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
        cout << "N[" << i << "] = " << a[i] << "\n";
}