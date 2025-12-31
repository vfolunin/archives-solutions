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

    string a, b;
    cin >> a >> a >> b;

    int count = 0;
    for (int i = 0; i < a.size(); i++)
        count += a[i] == 'S' && b[i] == 'S';

    cout << (count <= 2 ? "YES" : "NO");
}