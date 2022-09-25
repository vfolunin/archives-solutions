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
 
    int l, r, rem, den;
    cin >> l >> r >> rem >> den;

    for (int i = l; i <= r; i++)
        if (i % den == rem)
            cout << i << " ";
}