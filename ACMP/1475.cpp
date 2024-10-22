#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <random>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int size;
	cin >> size;

	minstd_rand generator;
	uniform_int_distribution<int> distribution(0, 1e9);

	for (int i = 0; i < size; i++)
		cout << distribution(generator) << " ";
}