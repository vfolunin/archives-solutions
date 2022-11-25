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

    int ya, xa, yb, xb;
    cin >> ya >> xa >> yb >> xb;

    if ((ya + xa) % 2 == (yb + xb) % 2)
        cout << "YES";
    else
        cout << "NO";
}