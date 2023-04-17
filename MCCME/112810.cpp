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
    
    long long size, mod, row, col;
    cin >> size >> mod >> row >> col;
    row--;
    col--;

    long long index = row * 2 + col;
    long long indexA = index + mod, rowA = indexA / 2, colA = indexA % 2;
    long long indexB = index - mod, rowB = indexB / 2, colB = indexB % 2;

    if (indexA < size && (indexB < 0 || abs(row - rowA) <= abs(row - rowB)))
        cout << rowA + 1 << " " << colA + 1;
    else if (0 <= indexB)
        cout << rowB + 1 << " " << colB + 1;
    else
        cout << -1;
}