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

    for (int y = 0; y < size; y++) {
        int sum = 0;

        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            sum += value;
        }

        cout << sum << "\n";
    }
}