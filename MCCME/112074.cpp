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

    vector<int> a;
    for (int value; cin >> value; )
        a.push_back(value);

    for (int value : a)
        if (value % 2 == 0)
            cout << value << " ";
    cout << "\n";
    
    for (int value : a)
        if (value % 6 == 0)
            cout << value << " ";
    cout << "\n";

    for (int value : a)
        if (value % 2 == 0 || value % 3 == 0)
            cout << value << " ";
    cout << "\n";
}