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

    vector<int> values(size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int conjunction;
            cin >> conjunction;

            for (int bit = 0; bit < 30; bit++) {
                if (conjunction & (1 << bit)) {
                    values[i] |= 1 << bit;
                    values[j] |= 1 << bit;
                }
            }
        }
    }

    for (int value : values)
        cout << value << " ";
}