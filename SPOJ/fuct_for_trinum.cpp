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

    for (int i = 1; i <= size; i++) {
        for (int j = i; j >= 1; j--)
            cout << j << " ";
        cout << "\n";
    }
}