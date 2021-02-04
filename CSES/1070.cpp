#include <iostream>
#include <iomanip>
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

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION";
        return 0;
    }

    vector<int> p;
    for (int i = 2; i <= n; i += 2)
        p.push_back(i);
    for (int i = 1; i <= n; i += 2)
        p.push_back(i);
    
    for (int x : p)
        cout << x << " ";
}