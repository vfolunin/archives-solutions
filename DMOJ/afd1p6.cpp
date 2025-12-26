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

    random_device randomDevice;
    minstd_rand generator(randomDevice());

    cout << uniform_int_distribution<int>(1, 32)(generator) << "\n";
}