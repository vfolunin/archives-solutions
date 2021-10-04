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

    vector<string> a(3);
    for (string &s : a)
        cin >> s;

    map<vector<string>, string> m = {
        { {"vertebrado", "ave", "carnivoro"}, "aguia" },
        { {"vertebrado", "ave", "onivoro"}, "pomba" },
        { {"vertebrado", "mamifero", "onivoro"}, "homem" },
        { {"vertebrado", "mamifero", "herbivoro"}, "vaca" },
        { {"invertebrado", "inseto", "hematofago"}, "pulga" },
        { {"invertebrado", "inseto", "herbivoro"}, "lagarta" },
        { {"invertebrado", "anelideo", "hematofago"}, "sanguessuga" },
        { {"invertebrado", "anelideo", "onivoro"}, "minhoca" }
    };

    cout << m[a] << "\n";
}