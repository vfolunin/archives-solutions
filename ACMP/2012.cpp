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

    int index;
    cin >> index;

    string s = "¡¿–¿¡¿Õ";
    vector<string> a;
    sort(s.begin(), s.end());
    do {
        a.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << a[index - 1];
}