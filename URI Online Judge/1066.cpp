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

    int even = 0, odd = 0, pos = 0, neg = 0;

    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;

        even += x % 2 == 0;
        odd += x % 2 != 0;
        pos += x > 0;
        neg += x < 0;
    }

    cout << even << " valor(es) par(es)\n";
    cout << odd << " valor(es) impar(es)\n";
    cout << pos << " valor(es) positivo(s)\n";
    cout << neg << " valor(es) negativo(s)\n";
}