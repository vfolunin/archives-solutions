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

    vector<int> a(4);
    for (int &value : a)
        cin >> value;

    int den;
    cin >> den;

    cout << (*max_element(a.begin(), a.end()) + den - 1) / den;
}