#define SOLUTION_HPP
#ifdef SOLUTION_HPP

#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {

        // 🏗️ This will store the final Roman numeral result
        string romanResult = "";

        // 📚 Lookup table mapping integer place-values to Roman numerals
        // Covers units, tens, hundreds, and thousands
        map<int, string> valueToRoman = {
            {0, ""}, 
            {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"},
            {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"},
            {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"},
            {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"},
            {100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"},
            {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"},
            {1000, "M"}, {2000, "MM"}, {3000, "MMM"}
        };

        // 🔢 Tracks the current place value:
        // 1 → ones, 10 → tens, 100 → hundreds, 1000 → thousands
        int placeValue = 1;

        // 🔄 Process digits from right (least significant) to left
        while (num > 0) {

            // ✂️ Extract the current digit and scale by its place value
            // Example: If num = 374
            // First iteration: 4 * 1   = 4
            // Second:          7 * 10  = 70
            // Third:           3 * 100 = 300
            int digitValue = (num % 10) * placeValue;

            // ➕ Prepend corresponding Roman numeral
            // We prepend because we're processing from smallest place value first
            romanResult = valueToRoman[digitValue] + romanResult;

            // ➗ Remove the processed digit
            num /= 10;

            // ⬆️ Move to next place value
            placeValue *= 10;
        }

        // 🎉 Return the constructed Roman numeral
        return romanResult;
    }
};

#endif