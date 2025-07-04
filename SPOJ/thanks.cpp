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

    int size, type;
    cin >> size >> type;

    for (int i = 0; i < size; i++) {
        string name;
        int nameType;
        cin >> name >> nameType;

        cout << "Welcome " << name;
        if (type != nameType)
            cout << ", ;)";
        cout << "\n";
    }
}