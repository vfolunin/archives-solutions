#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    sort(a.begin(), a.end());

    int diffGcd = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        diffGcd = gcd(diffGcd, a[i + 1] - a[i]);

    cout << (a.back() - a.front()) / diffGcd - (a.size() - 1);
}