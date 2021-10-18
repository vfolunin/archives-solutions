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

    string s = "AMO FAZER EXERCICIO NO URI";
    vector<string> formats = {
        "<%s>\n", "<%30s>\n", "<%.20s>\n", "<%-20s>\n",
        "<%-30s>\n", "<%.30s>\n", "<%30.20s>\n", "<%-30.20s>\n"
    };

    for (string &format : formats)
        printf(format.c_str(), s.c_str());
}