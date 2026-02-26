#define SOLUTION_H
#ifdef SOLUTION_H

#include <stdlib.h>
#include <string.h>

char* intToRoman(int num) {
    
    // 🏗️ Allocate buffer for the resulting Roman numeral
    // 1000 chars is plenty for numbers <= 3999
    char *romanResult = (char*) calloc(1000, sizeof(char));

    // 🔢 Roman numeral values in descending order
    int values[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // 🏛 Corresponding Roman symbols
    char symbols[13][3] = {"M", "CM", "D", "CD", "C", "XC", "L",
                            "XL", "X", "IX", "V", "IV", "I"};

    int currentIndex = 0;  // Tracks position in values/symbols arrays
    int resultIndex = 0;   // Tracks current position in romanResult
    char* currentSymbol;

    // 🔄 Process each value from largest to smallest
    while(num > 0) {
        // ➕ Greedily subtract value and append symbol until it no longer fits
        while(num >= values[currentIndex]) {
            currentSymbol = symbols[currentIndex];

            // 🧱 Append each character of the current Roman symbol
            for(int i = 0; i < strlen(currentSymbol); ++i, ++resultIndex)
                romanResult[resultIndex] = currentSymbol[i];
            
            // ➖ Reduce the number by the value we've just used
            num -= values[currentIndex];
        }
        
        // ⬇️ Move to the next smaller Roman value
        ++currentIndex;
    }

    // 🎉 Return the final Roman numeral string
    return romanResult;
}

#endif