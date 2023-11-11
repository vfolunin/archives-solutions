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
    
    int l, r;
    cin >> l >> r;

    for (long long i = l; i <= r; i++)
        cout << i * i << " ";
    cout << "\n";

    for (long long i = r; i >= l; i--)
        cout << i * i * i << " ";
}