#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Ticket {
	string id, type;
	int time;

	bool operator < (const Ticket &that) const {
		return time < that.time;
	}

	friend istream &operator >> (istream &in, Ticket &t) {
		in >> t.id;

		int h, m, s;
		char colon;
		in >> h >> colon >> m >> colon >> s;
		t.time = h * 3600 + m * 60 + s;

		in >> t.type;

		return in;
	}
	
	friend ostream &operator << (ostream &out, Ticket &t) {
		out << "Ticket " << t.id << ": counter ";

		if (t.type == "deposit" || t.type == "transfer")
			out << 1;
		else if (t.type == "loan" || t.type == "withdrawal")
			out << 2;
		else
			out << 3;

		return out;
	}
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int ticketCount;
	cin >> ticketCount;

	vector<Ticket> tickets(ticketCount);
	for (Ticket &ticket : tickets)
		cin >> ticket;

	sort(tickets.begin(), tickets.end());

	for (Ticket &ticket : tickets)
		cout << ticket << "\n";
}