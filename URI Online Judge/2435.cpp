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

    int n1, d1, v1, n2, d2, v2;
    cin >> n1 >> d1 >> v1 >> n2 >> d2 >> v2;

    cout << (d1 * v2 < d2 * v1 ? n1 : n2) << "\n";       
}