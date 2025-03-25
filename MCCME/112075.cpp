#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    vector<int> a;
    do {
        int value;
        cin >> value;
        a.push_back(value);
    } while (cin.peek() != '\n');
    return a;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a = readInts();
    vector<int> b = readInts();

    int res = 0;
    for (int i = 0; i < a.size(); i++)
        res += a[i] * b[i];

    cout << res;
}