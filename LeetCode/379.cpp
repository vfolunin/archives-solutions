class PhoneDirectory {
    unordered_set<int> numbers;

public:
    PhoneDirectory(int maxNumbers) {
        for (int number = 0; number < maxNumbers; number++)
            numbers.insert(number);
    }
    
    int get() {
        if (numbers.empty())
            return -1;

        int number = *numbers.begin();
        numbers.erase(numbers.begin());
        return number;
    }
    
    bool check(int number) {
        return numbers.count(number);
    }
    
    void release(int number) {
        numbers.insert(number);
    }
};