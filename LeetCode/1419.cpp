class Solution {
public:
    int minNumberOfFrogs(string &s) {
        string croak = "croak";
        vector<int> frogCount(5);
        
        for (char c : s) {
            int i = croak.find(c);
            if (frogCount[(i + 4) % 5]) {
                frogCount[(i + 4) % 5]--;
                frogCount[i]++;
            } else if (!i) {
                frogCount[0]++;
            } else {
                return -1;
            }
        }
        
        for (int i = 0; i + 1 < 5; i++)
            if (frogCount[i])
                return -1;
        return frogCount.back();
    }
};