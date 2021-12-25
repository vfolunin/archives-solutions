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

    int h, w, y, x;
    cin >> h >> w >> y >> x;

    cout << ((y * w + x) % 2 ? "Esquerda\n" : "Direita\n");
}