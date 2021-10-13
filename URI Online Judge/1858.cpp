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
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    cout << min_element(a.begin(), a.end()) - a.begin() + 1 << "\n";
}