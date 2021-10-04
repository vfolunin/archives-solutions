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

    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    if (t2 <= t1)
        t2 += 24 * 60;
    int t = t2 - t1;

    cout << "O JOGO DUROU " << t / 60 << " HORA(S) E " << t % 60 << " MINUTO(S)\n";
}