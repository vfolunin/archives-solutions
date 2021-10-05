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

    vector<int> count(3);

    while (1) {
        int type;
        cin >> type;

        if (1 <= type && type <= 3)
            count[type - 1]++;
        else if (type == 4)
            break;
    }

    cout << "MUITO OBRIGADO\n";
    cout << "Alcool: " << count[0] << "\n";
    cout << "Gasolina: " << count[1] << "\n";
    cout << "Diesel: " << count[2] << "\n";
}