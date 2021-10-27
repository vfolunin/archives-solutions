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

    int even, an, bn, ac, bc;
    cin >> even >> an >> bn >> ac >> bc;

    if (ac || bc)
        cout << "Jogador " << (ac ^ bc ? 1 : 2) << " ganha!\n";
    else
        cout << "Jogador " << (((an + bn) % 2) ^ even ? 1 : 2) << " ganha!\n";
}