#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iterator>
using namespace std;

vector<int> readSeq() {
    int size;
    cin >> size;

    vector<int> seq(size);
    for (int &x : seq)
        cin >> x;

    return seq;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> a = readSeq();
    vector<int> b = readSeq();
    vector<int> c;

    for (int i = 0; i < a.size() && i < b.size(); i++)
        if (a[i] == b[i])
            cout << i + 1 << " ";
}