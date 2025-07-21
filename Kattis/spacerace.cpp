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
    double length;
    cin >> size >> length;

    string res;
    double resScore = 0;

    for (int i = 0; i < size; i++) {
        string name;
        double speed, fuel;
        cin >> name >> speed >> fuel;

        double time = length / speed;
        double rate = fuel / time;
        double score = speed / rate;

        if (resScore < score) {
            res = name;
            resScore = score;
        }
    }

    cout << res;
}