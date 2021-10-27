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

    int resId = 0;
    double resScore = 0;
    
    for (int i = 0; i < studentCount; i++) {
        int id;
        double score;
        cin >> id >> score;

        if (score >= 8 && score > resScore) {
            resId = id;
            resScore = score;
        }
    }

    if (resScore)
        cout << resId << "\n";
    else
        cout << "Minimum note not reached\n";
}