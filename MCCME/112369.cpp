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

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            if (x <= y)
                cout << value << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}