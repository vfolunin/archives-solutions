#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

int digitSum(int value) {
    int sum = 0;
    for (; value; value /= 10)
        sum += value % 10;
    return sum;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r, size, sum;
    cin >> l >> r >> size >> sum;

    vector<int> a(size);
    int count = 0;

    minstd_rand generator;
    uniform_int_distribution<int> distr(l, r);
    for (int &value : a) {
        value = distr(generator);
        count += digitSum(value) == sum;
    }

    for (int value : a)
        cout << value << " ";
    cout << "\n";

    cout << count << "\n";
}