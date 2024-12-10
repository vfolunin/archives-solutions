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

    int k3 = 0, k4 = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        k3 += value == 3;
        k4 += value == 4;
    }

    if (k3 <= 1 && (k3 + k4) * 4 <= size)
        cout << "Degree with honors";
    else
        cout << "Ordinary degree";
}