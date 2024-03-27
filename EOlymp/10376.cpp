#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    minstd_rand generator;

    for (int i = 0; i < n; i++)
        cout << generator() % 6 + 1 << " ";
}