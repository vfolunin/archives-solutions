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

    for (int i = 0; i < 2; i++) {
        for (int j = 0, points = 400; j < size; j++, points--) {
            int id;
            cin >> id;

            cout << points << " ";

            if (id == 1)
                points = size - j;
        }
        cout << "\n";
    }
}