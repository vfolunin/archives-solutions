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

	long long humans, planes, planesPerSheet, sheetsPerPackage;
	cin >> humans >> planes >> planesPerSheet >> sheetsPerPackage;

	long long sheetsPerHuman = (planes + planesPerSheet - 1) / planesPerSheet;
	long long sheets = humans * sheetsPerHuman;
	long long packages = (sheets + sheetsPerPackage - 1) / sheetsPerPackage;

	cout << packages;
}