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

    int studentCount;
    cin >> studentCount;

    map<string, int> formOf;
    for (int i = 0; i < studentCount; i++) {
        string surname, name;
        int form;
        cin >> surname >> name >> form;

        formOf[surname + " " + name] = form;
    }

    map<int, int> sum, count;
    for (int i = 0; i < studentCount; i++) {
        string surname, name;
        int score;
        cin >> surname >> name >> score;

        sum[formOf[surname + " " + name]] += score;
        count[formOf[surname + " " + name]]++;
    }

    for (auto &[form, sum] : sum)
        cout << form << " " << (sum + count[form] - 1) / count[form] << "\n";
}