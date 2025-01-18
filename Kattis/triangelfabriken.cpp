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

    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());

    if (a[2] > 90)
        cout << "Trubbig Triangel";
    else if (a[2] == 90)
        cout << "Ratvinklig Triangel";
    else
        cout << "Spetsig Triangel";
}