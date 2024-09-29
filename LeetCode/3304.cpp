class Solution {
public:
    char kthCharacter(int index) {
        index--;
        string a = "a";

        while (a.size() <= index) {
            string b = a;
            for (char &c : b)
                c = (c - 'a' + 1) % 26 + 'a';
            a += b;
        }
        
        return a[index];
    }
};