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

    double num = 0;
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
            num += count(a.begin(), a.end(), i + j);

    cout << fixed << num / 36;
}