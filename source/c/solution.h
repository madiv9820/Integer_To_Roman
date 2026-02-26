#define SOLUTION_H
#ifdef SOLUTION_H

#include <stdlib.h>
#include <string.h>

// Converts a specific place-value integer (1, 4, 40, 900, etc.)
// into its corresponding Roman numeral symbol.
// ⚠️ Works only for predefined valid Roman values.
char* intToRomanSymbol(int value) {

    // 🟢 Units (1–10)
    if      (value == 1)      return "I";
    else if (value == 2)      return "II";
    else if (value == 3)      return "III";
    else if (value == 4)      return "IV";   // 5 - 1
    else if (value == 5)      return "V";
    else if (value == 6)      return "VI";
    else if (value == 7)      return "VII";
    else if (value == 8)      return "VIII";
    else if (value == 9)      return "IX";   // 10 - 1
    else if (value == 10)     return "X";

    // 🔵 Tens (20–90)
    else if (value == 20)     return "XX";
    else if (value == 30)     return "XXX";
    else if (value == 40)     return "XL";   // 50 - 10
    else if (value == 50)     return "L";
    else if (value == 60)     return "LX";
    else if (value == 70)     return "LXX";
    else if (value == 80)     return "LXXX";
    else if (value == 90)     return "XC";   // 100 - 10

    // 🟣 Hundreds (100–900)
    else if (value == 100)    return "C";
    else if (value == 200)    return "CC";
    else if (value == 300)    return "CCC";
    else if (value == 400)    return "CD";   // 500 - 100
    else if (value == 500)    return "D";
    else if (value == 600)    return "DC";
    else if (value == 700)    return "DCC";
    else if (value == 800)    return "DCCC";
    else if (value == 900)    return "CM";   // 1000 - 100

    // 🟡 Thousands (1000–3000)
    else if (value == 1000)   return "M";
    else if (value == 2000)   return "MM";
    else if (value == 3000)   return "MMM";

    // ❌ Unsupported value
    else                      return "";
}


// Converts a full integer into a Roman numeral string.
// 🧠 Strategy:
// 1️⃣ Extract each digit (units → thousands)
// 2️⃣ Convert that place-value chunk to Roman
// 3️⃣ Build the string in reverse
// 4️⃣ Reverse the final result
char* intToRoman(int num) {

    // 🏗️ Allocate buffer for the Roman result
    char *romanResult = (char*) calloc(10000, sizeof(char));

    int resultIndex = 0;      // Current position in romanResult
    int placeValue = 1;       // 1 → 10 → 100 → 1000 ...
    int digitChunk;           // Current scaled digit (e.g., 300, 40, 5)
    char *romanChunk;         // Roman symbol for current chunk
    int chunkLength;
    int reverseIndex;
    int resultLength;
    int left;
    int right;

    // 🔄 Process digits from right to left
    while(num > 0) {

        // ✂️ Extract last digit and scale it
        digitChunk = (num % 10) * placeValue;

        // 🔎 Convert this chunk to Roman
        romanChunk = intToRomanSymbol(digitChunk);
        chunkLength = strlen(romanChunk);

        // 🧱 Append characters in reverse order
        // (because we're processing least significant digit first)
        for(reverseIndex = chunkLength - 1;
            reverseIndex >= 0;
            --reverseIndex, ++resultIndex) {

            romanResult[resultIndex] = romanChunk[reverseIndex];
        }

        // ➗ Remove processed digit
        num /= 10;

        // ⬆️ Move to next place value
        placeValue *= 10;
    }

    // 🔁 Reverse the full result string
    resultLength = strlen(romanResult);

    for(left = 0, right = resultLength - 1; left < right; left++, right--) {
        char temp = romanResult[left];
        romanResult[left] = romanResult[right];
        romanResult[right] = temp;
    }

    // 🎉 Final Roman numeral
    return romanResult;
}

#endif