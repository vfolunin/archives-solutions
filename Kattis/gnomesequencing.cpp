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

    int size;
    cin >> size;

    cout << "Gnomes:\n";
    for (int i = 0; i < size; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a < b && b < c || a > b && b > c)
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
}