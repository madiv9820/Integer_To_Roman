#define SOLUTION_HPP
#ifdef SOLUTION_HPP

#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        
        // 🏗️ This will store the final Roman numeral
        string romanResult = "";

        // 🔢 Roman numeral values in descending order
        int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        // 🏛 Corresponding Roman symbols
        string symbols[13] = {"M", "CM", "D", "CD", "C", "XC", "L",
                              "XL", "X", "IX", "V", "IV", "I"};

        int currentIndex = 0; // Tracks position in values/symbols arrays

        // 🔄 Process number from largest to smallest value
        while(num > 0) {
            
            // ➕ Greedily subtract current value and append its symbol
            while(num >= values[currentIndex]) {
                romanResult += symbols[currentIndex]; // 🧱 Append symbol
                num -= values[currentIndex];          // ➖ Reduce number
            }
            
            // ⬇️ Move to the next smaller Roman numeral
            ++currentIndex;
        }

        // 🎉 Return the constructed Roman numeral string
        return romanResult;
    }
};

#endif