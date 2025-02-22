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

    int size, col;
    cin >> size >> col;
    col--;

    vector<vector<int>> a(size, vector<int>(size));
    int value = 1, sum = 0;;

    for (int x = 0; x < col; x++)
        for (int y = 0; y < size; y++)
            a[y][x] = value++;

    for (int y = 0; y < size; y++) {
        for (int x = col; x < size; x++) {
            if (x == col)
                sum += value;
            a[y][x] = value++;
        }
    }
     
    cout << sum << "\n";
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << a[y][x] << " ";
        cout << "\n";
    }
}