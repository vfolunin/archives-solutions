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

    int cd, ad, bc, ab;
    cin >> cd >> ad >> bc >> ab;

    if (ab + bc + cd == ad) // abcd
        cout << bc + cd;
    else if (ab + cd == ad + bc) // acbd cabd
        cout << ad - ab;
    else if (ab + ad == bc + cd) // bacd bcad
        cout << ab + ad;
    else if (bc + ab + ad == cd) // cbad
        cout << cd - bc;
    else
        cout << "No solution";
}