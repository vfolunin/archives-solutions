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

    int day, deadline;
    cin >> day >> deadline;

    if (day + 3 <= deadline) {
        cout << "Muito bem! Apresenta antes do Natal!\n";
    } else if (day <= deadline) {
        cout << "Parece o trabalho do meu filho!\n";
        if (day + 2 < 24)
            cout << "TCC Apresentado!\n";
        else
            cout << "Fail! Entao eh nataaaaal!\n";
    } else {
        cout << "Eu odeio a professora!\n";
    }
}