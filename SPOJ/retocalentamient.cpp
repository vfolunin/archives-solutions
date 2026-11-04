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

    if (size <= 1) {
        cout << -1;
        return 0;
    }

    vector<int> a(size);
    for (int i = 0; i < a.size(); i++)
        cin >> a[i];

    if (a[a.size() - 2] < a[a.size() - 1])
        cout << (a.back() == 15 ? "MENGUANTE" : "CRECIENTE");
    else
        cout << (a.back() == 0 ? "CRECIENTE" : "MENGUANTE");
}