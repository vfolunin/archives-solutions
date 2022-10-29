#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int size, int from, int via, int to) {
    if (!size)
        return;
    rec(size - 1, from, to, via);
    cout << size << " " << from << " " << to << "\n";
    rec(size - 1, via, from, to);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int size;
    cin >> size;

    rec(size, 1, 2, 3);
}