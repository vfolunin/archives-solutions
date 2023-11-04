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

    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        if (value <= 2.5) {
            cout.precision(2);
            cout << i + 1 << " " << fixed << value;
            return 0;
        }
    }

    cout << "Not Found";
}