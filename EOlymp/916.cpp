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

    int la, ra;
    cin >> la >> ra;
    if (la > ra)
        swap(la, ra);

    int lb, rb;
    cin >> lb >> rb;
    if (lb > rb)
        swap(lb, rb);

    set<int> res;
    for (int a = la; a <= ra; a++)
        for (int b = lb; b <= rb; b++)
            res.insert(a * b);

    cout << res.size();
}