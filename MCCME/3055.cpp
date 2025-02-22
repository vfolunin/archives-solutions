#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int count, int from, int aux, int to) {
    if (!count)
        return;
    if (count == 1) {
        cout << "1 " << from << " " << to << "\n";
        return;
    }
    rec(count - 1, from, aux, to);
    rec(count - 2, to, from, aux);
    cout << "0 " << from << " " << to << "\n";
    rec(count - 2, aux, to, from);
    rec(count - 1, from, aux, to);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count;
    cin >> count;

    rec(count, 1, 2, 3);
}