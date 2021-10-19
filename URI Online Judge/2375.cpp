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

    int r, a, b, c;
    cin >> r >> a >> b >> c;
    
    cout << (r <= a && r <= b && r <= c ? "S\n" : "N\n");
}