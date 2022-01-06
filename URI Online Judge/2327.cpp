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
    for (vector<int> &row : a)
        for (int &x : row)
            cin >> x;

    int rowSum = 0;
    for (int x : a[0])
        rowSum += x;

    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = 0; j < size; j++)
            sum += a[i][j];

        if (sum != rowSum) {
            cout << "-1\n";
            return 0;
        }

        sum = 0;
        for (int j = 0; j < size; j++)
            sum += a[j][i];
        
        if (sum != rowSum) {
            cout << "-1\n";
            return 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i][i];

    if (sum != rowSum) {
        cout << "-1\n";
        return 0;
    }

    sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i][size - 1 - i];

    if (sum != rowSum) {
        cout << "-1\n";
        return 0;
    }

    cout << rowSum << "\n";
}