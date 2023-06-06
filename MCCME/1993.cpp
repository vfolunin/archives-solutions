#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <random>
using namespace std;

struct Random {
    inline static minstd_rand generator;

    static double get01() {
        static uniform_real_distribution<double> distribution(0, 1);
        return distribution(generator);
    }

    static int get(int size) {
        return uniform_int_distribution<int>(0, size - 1)(generator);
    }
};

int getScore(vector<int> &p) {
    int score = 0;
    for (int i = 0; i < p.size(); i++) {
        int ok = 1;
        for (int j = i + 1; j < p.size(); j++)
            ok &= abs(i - j) != abs(p[i] - p[j]);
        score += ok;
    }
    return score;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<int> bestP(size);
    iota(bestP.begin(), bestP.end(), 0);
    shuffle(bestP.begin(), bestP.end(), Random::generator);
    int bestScore = getScore(bestP);

    double temperature = 1;
    for (int i = 0; bestScore < size; i++) {
        temperature *= 0.99;

        vector<int> curP = bestP;
        swap(curP[Random::get(size)], curP[Random::get(size)]);
        int curScore = getScore(curP);

        if (curScore > bestScore || Random::get01() < exp((curScore - bestScore) / temperature)) {
            bestP = curP;
            bestScore = curScore;
        }
    }

    for (int value : bestP)
        cout << value + 1 << " ";
}