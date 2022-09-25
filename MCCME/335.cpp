#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isSquare(int n) {
    int root = sqrt(n);
    return root * root == n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
        if (isSquare(i))
            cout << i << " ";
}