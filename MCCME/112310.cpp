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

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    int d1, d2;
    cin >> d1 >> d2;

    bool found = 0;
    for (int value : a) {
        if (100 <= value && value <= 999 && value % d1 == 0 && value % d2) {
            cout << value << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}