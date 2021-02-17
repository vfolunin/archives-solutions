#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    char c;
    int size;
    cin >> c >> c >> size;

    vector<vector<long long>> matrix(size, vector<long long>(size));
    for (vector<long long> &row : matrix)
        for (long long &x : row)
            cin >> x;

    bool isSymmetric = 1;
    for (int i = 0; isSymmetric && i < size; i++)
        for (int j = 0; isSymmetric && j < size; j++)
            isSymmetric &= matrix[i][j] >= 0 && matrix[i][j] == matrix[size - 1 - i][size - 1 - j];

    cout << "Test #" << test << ": ";
    cout << (isSymmetric ? "Symmetric.\n" : "Non-symmetric.\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}