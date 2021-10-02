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

    int phone;
    cin >> phone;

    map<int, string> phones = {
        { 11, "Sao Paulo" },
        { 19, "Campinas" },
        { 21, "Rio de Janeiro" },
        { 27, "Vitoria" },
        { 31, "Bela Horizonte" },
        { 32, "Juiz de Fora" },
        { 61, "Brasilia" },
        { 71, "Salvador" }
    };

    if (phones.count(phone))
        cout << phones[phone] << "\n";
    else
        cout << "DDD nao cadastrado\n";
}