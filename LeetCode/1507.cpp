class Solution {
public:
    string reformatDate(string date) {
        stringstream in(date);
        int day, year;
        string buf, monthName;
        in >> day >> buf >> monthName >> year;
        
        static const vector<string> MONTHS = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };
        int month = find(MONTHS.begin(), MONTHS.end(), monthName) - MONTHS.begin() + 1;
        
        stringstream out;
        out << year << "-";
        out << setw(2) << setfill('0') << month << "-";
        out << setw(2) << setfill('0') << day;
        return out.str();
    }
};