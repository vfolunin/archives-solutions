class Solution {
    string toWords3(int n) {
        static map<int, string> s = {
            { 0, "Zero" }, { 1, "One" }, { 2, "Two" }, { 3, "Three" }, { 4, "Four" },
            { 5, "Five" }, { 6, "Six" }, { 7, "Seven" }, { 8, "Eight" }, { 9, "Nine" },
            { 10, "Ten" }, { 11, "Eleven" }, { 12, "Twelve" }, { 13, "Thirteen" }, { 14, "Fourteen" },
            { 15, "Fifteen" }, { 16, "Sixteen" }, { 17, "Seventeen" }, { 18, "Eighteen" }, { 19, "Nineteen" },
            { 20, "Twenty" }, { 30, "Thirty" }, { 40, "Forty" }, { 50, "Fifty" }, { 60, "Sixty" },
            { 70, "Seventy" }, { 80, "Eighty" }, { 90, "Ninety" }
        };
        
        string res;
        
        if (n / 100)
            res += s[n / 100] + " Hundred";
        
        if (n % 100 / 10 == 1)
            res += (res.empty() ? "" : " ") + s[n % 100];
        else if (n % 100 / 10)
            res += (res.empty() ? "" : " ") + s[n % 100 / 10 * 10];
        
        if (n % 100 / 10 != 1 && n % 10)
            res += (res.empty() ? "" : " ") + s[n % 10];
        
        return res;
    }
    
    string toWords(int n) {
        if (!n)
            return "Zero";
        
        static map<int, string> s = { { 1000000000, "Billion" }, { 1000000, "Million" }, { 1000, "Thousand" } };
        
        string res;
        
        for (int p = 1000000000; p; p /= 1000)
            if (int n3 = n % (p * 1000LL) / p; n3)
                res += (res.empty() ? "" : " ") + toWords3(n3) + (p > 1 ? " " + s[p] : "");
        
        return res;
    }
    
public:
    string numberToWords(int n) {
        return toWords(n);
    }
};