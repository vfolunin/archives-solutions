#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;
    
    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    a.erase(unique(a.begin(), a.end()), a.end());

    for (int value : a)
        cout << value << " ";
    cout << "$\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}