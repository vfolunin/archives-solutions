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

    int maxValue;
    cin >> maxValue;

    set<int> a;
    do {
        int value;
        cin >> value;
        a.insert(value);
    } while (cin.peek() != '\n');

    set<int> b;
    do {
        int value;
        cin >> value;
        b.insert(value);
    } while (cin.peek() != '\n' && cin.peek() != EOF);

    for (int value = 1; value <= maxValue; value++)
        if (a.count(value) && b.count(value))
            cout << value << " ";
    cout << "\n";
    for (int value = 1; value <= maxValue; value++)
        if (!a.count(value) && !b.count(value))
            cout << value << " ";
}