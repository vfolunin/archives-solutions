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

    vector<double> a(3);
    for (double &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    if (a[0] + a[1] <= a[2]) {
        cout << "NAO FORMA TRIANGULO\n";
    } else {
        if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])
            cout << "TRIANGULO RETANGULO\n";
        else if (a[0] * a[0] + a[1] * a[1] < a[2] * a[2])
            cout << "TRIANGULO OBTUSANGULO\n";
        else
            cout << "TRIANGULO ACUTANGULO\n";

        if (a[0] == a[2])
            cout << "TRIANGULO EQUILATERO\n";
        else if (a[0] == a[1] || a[1] == a[2])
            cout << "TRIANGULO ISOSCELES\n";
    }
}