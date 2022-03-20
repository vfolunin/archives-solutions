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

    map<string, double> th;
    th["thou"] = th["th"] = 1;
    th["inch"] = th["in"] = 1000 * th["thou"];
    th["foot"] = th["ft"] = 12 * th["inch"];
    th["yard"] = th["yd"] = 3 * th["foot"];
    th["chain"] = th["ch"] = 22 * th["yard"];
    th["furlong"] = th["fur"] = 10 * th["chain"];
    th["mile"] = th["mi"] = 8 * th["furlong"];
    th["league"] = th["lea"] = 3 * th["mile"];

    double amount;
    string a, in, b;
    cin >> amount >> a >> in >> b;

    cout.precision(9);
    cout << fixed << amount * th[a] / th[b];
}