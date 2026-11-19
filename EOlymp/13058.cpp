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

    string a, b;
    cin >> a >> a >> b;

    for (int i = 0; i < a.size(); i++)
        if (a[i] > b[i])
            swap(a[i], b[i]);
    
    cout << (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end()) ? "YES" : "NO");
}