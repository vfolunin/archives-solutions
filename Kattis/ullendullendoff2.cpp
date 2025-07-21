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

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    swap(a[0], a[12 % size]);

    for (string &s : a)
        cout << s << "\n";
}