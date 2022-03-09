#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> count(4e5);
    for (int a = 1; a < 100; a++)
        for (int b = a + 1; b < 100; b++)
            if (a * a * a + b * b * b < count.size())
                count[a * a * a + b * b * b]++;

    vector<int> busNumbers;
    for (int i = 0; i < count.size(); i++)
        if (count[i] >= 2)
            busNumbers.push_back(i);
    return busNumbers;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> busNumbers = prepare();

    if (n < busNumbers.front())
        cout << "none";
    else
        cout << *--upper_bound(busNumbers.begin(), busNumbers.end(), n);
}