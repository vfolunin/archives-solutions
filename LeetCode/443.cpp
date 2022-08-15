class Solution {
public:
    int compress(vector<char> &s) {
        int to = 0;
        
        for (int from = 0; from < s.size(); ) {
            int row = 0;
            do {
                from++;
                row++;
            } while (from < s.size() && s[from - 1] == s[from]);
            
            s[to++] = s[from - 1];
            if (row > 1) {
                string sRow = to_string(row);
                for (char c : sRow)
                    s[to++] = c;
            }
        }
        
        return to;
    }
};