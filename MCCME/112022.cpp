#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> read() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    return a;
}

bool isSubsequence(vector<int> &a, vector<int> &b) {
    int bi = 0;
    for (int ai = 0; ai < a.size() && bi < b.size(); ai++)
        bi += bi < b.size() && a[ai] == b[bi];
    return bi == b.size();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a = read();
    vector<int> b = read();
    vector<int> c = read();

    cout << (isSubsequence(a, c) && isSubsequence(b, c) ? "Yes" : "No");
}