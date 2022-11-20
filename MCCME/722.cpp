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

    int al, ar, bl, br;
    cin >> al >> ar >> bl >> br;

    if (al > ar)
        swap(al, ar);
    if (bl > br)
        swap(bl, br);

    cout << max(min(ar, br) - max(al, bl) + 1, 0);
}