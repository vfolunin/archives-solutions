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

    int size;
    cin >> size;

    string res;
    double resRating = 0;

    for (int i = 0; i < size; i++) {
        string name;
        double rating;
        cin >> name >> rating;

        if (resRating < rating) {
            resRating = rating;
            res = name;
        }
    }

    cout << res;
}