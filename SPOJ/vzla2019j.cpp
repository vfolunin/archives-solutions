#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    cout << "Case #" << test << ": ";

    for (int i = 0; i + 1 < a.size(); i++) {
        if (a[i] + 1 == a[i + 1]) {
            cout << "Oh no!\n";
            return;
        }
    }
    
    cout << "Survival!\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}