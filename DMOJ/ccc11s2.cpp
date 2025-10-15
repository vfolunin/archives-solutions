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

    string a(size, ' '), b(size, ' ');
    for (int i = 0; i < size; i++)
        cin >> a[i];
    for (int i = 0; i < size; i++)
        cin >> b[i];

    int res = 0;
    for (int i = 0; i < size; i++)
        res += a[i] == b[i];

    cout << res;
}