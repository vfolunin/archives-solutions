#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <random>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end(), minstd_rand());

    for (int value : a)
        cout << value << " ";
}