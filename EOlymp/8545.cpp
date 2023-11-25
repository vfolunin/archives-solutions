#include <iostream>
#include <iomanip>
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

    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
            cout << setw(2) << i * j << (j < size ? " " : "\n");
}