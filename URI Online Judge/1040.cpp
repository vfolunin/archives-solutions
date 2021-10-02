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

    vector<double> marks(4);
    for (double &m : marks)
        cin >> m;

    vector<int> weights = { 2, 3, 4, 1 };

    double avg = 0;
    for (int i = 0; i < 4; i++)
        avg += marks[i] * weights[i];
    avg /= 10;

    cout.precision(1);
    cout << "Media: " << fixed << avg << "\n";
    if (avg >= 7) {
        cout << "Aluno aprovado.\n";
    } else if (avg < 5) {
        cout << "Aluno reprovado.\n";
    } else {
        double exam;
        cin >> exam;

        cout << "Aluno em exame.\n";
        cout << "Nota do exame: " << exam << "\n";
        if (exam >= 5)
            cout << "Aluno aprovado.\n";
        else
            cout << "Aluno reprovado.\n";
        cout << "Media final: " << (avg + exam) / 2 << "\n";
    }
}