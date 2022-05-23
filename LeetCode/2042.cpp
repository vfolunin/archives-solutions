class Solution {
    vector<int> splitNumbers(string &line) {
        vector<int> numbers;
        int number = 0;
        for (char c : line) {
            if (isdigit(c)) {
                number = number * 10 + c - '0';
            } else if (number) {
                numbers.push_back(number);
                number = 0;
            }
        }
        if (number)
            numbers.push_back(number);
        return numbers;
    }
    
public:
    bool areNumbersAscending(string s) {
        vector<int> numbers = splitNumbers(s);
        for (int i = 1; i < numbers.size(); i++)
            if (numbers[i - 1] >= numbers[i])
                return 0;
        return 1;
    }
};