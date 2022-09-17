class Solution {
    int getDay(string &s) {
        stringstream ss(s);
        int month, day;
        char dash;
        ss >> month >> dash >> day;
        
        static vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        for (int i = 0; i + 1 < month; i++)
            day += daysInMonth[i];
        
        return day;
    }
    
public:
    int countDaysTogether(string &al, string &ar, string &bl, string &br) {
        return max(0, min(getDay(ar), getDay(br)) - max(getDay(al), getDay(bl)) + 1);
    }
};