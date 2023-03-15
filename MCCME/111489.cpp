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

    vector<string> a(size);
    int cityCount = 0;

    for (int y = 0; y < size; y++) {
        cin >> a[y];
        for (int x = 0; x < size; x++)
            cityCount += a[y][x] == 'C';
    }

    vector<string> res(size, string(size, '2'));
    cityCount /= 2;

    for (int y = 0; y < size && cityCount; y++) {
        for (int x = 0; x < size && cityCount; x++) {
            res[y][x] = '1';
            cityCount -= a[y][x] == 'C';
        }
    }

    for (string &row : res)
        cout << row << "\n";
}