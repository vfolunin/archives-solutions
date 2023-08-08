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
    string value;
    cin >> size >> value;

    vector<string> a;
    for (int i = 1; i <= size; i++)
        a.push_back(to_string(i));

    sort(a.begin(), a.end());

    cout << find(a.begin(), a.end(), value) - a.begin() + 1;
}