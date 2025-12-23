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

    string a, b;
    cin >> a >> b;

    cout << a << "-tu ";

    if (b.back() == 'e')
        cout << "la";
    else if (b.back() == 's')
        cout << "les";
    else
        cout << "le";

    cout << " " << b << " ?";
}