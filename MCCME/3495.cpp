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

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    cout << *max_element(a.begin(), a.begin() + a.size() / 2) << " ";
    cout << *max_element(a.begin() + a.size() / 2, a.end()) << " ";
    cout << *max_element(a.begin(), a.end());
}