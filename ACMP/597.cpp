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

    int r, ra, rb;
    cin >> r >> ra >> rb;

    cout << (ra + rb <= r ? "YES" : "NO");
}