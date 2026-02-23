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

    vector<string> lattice(4);
    for (string &row : lattice)
        cin >> row;

    vector<string> cypher(lattice.size());
    for (string &row : cypher)
        cin >> row;

    for (int i = 0; i < 4; i++) {
        for (int y = 0; y < lattice.size(); y++)
            for (int x = 0; x < lattice.size(); x++)
                if (lattice[y][x] == 'X')
                    cout << cypher[y][x];

        vector<string> nextLattice = lattice;
        for (int y = 0; y < lattice.size(); y++)
            for (int x = 0; x < lattice.size(); x++)
                nextLattice[y][x] = lattice[lattice.size() - 1 - x][y];

        lattice.swap(nextLattice);
    }
}