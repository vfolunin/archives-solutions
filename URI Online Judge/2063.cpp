#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> p(size);
    for (int &x : p) {
        cin >> x;
        x--;
    }

    int cycleLcm = 0;

    for (int i = 0; i < size; i++) {
        if (p[i] == -1)
            continue;

        int cycle = 0, v = i;
        while (p[v] != -1) {
            int nextV = p[v];
            p[v] = -1;
            v = nextV;
            cycle++;
        }

        if (cycleLcm)
            cycleLcm = lcm(cycleLcm, cycle);
        else
            cycleLcm = cycle;
    }

    cout << cycleLcm << "\n";
}