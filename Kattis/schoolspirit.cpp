#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double score(vector<int> &a) {
    double sum = 0;
    for (int i = 0; i < a.size(); i++)
        sum += a[i] * pow(0.8, i);
    return sum / 5;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    double average = 0;
    for (int i = 0; i < size; i++) {
        vector<int> b = a;
        b.erase(b.begin() + i);
        average += score(b);
    }
    average /= size;

    cout << fixed << score(a) << "\n";
    cout << fixed << average << "\n";
}