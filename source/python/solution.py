from typing import List

class pySolution:
    def py_intToRoman(self, num: int) -> str:
        
        # 🏗️ String to store the final Roman numeral
        romanResult: str = ''

        # 🔢 Roman numeral values in descending order
        values: List[int] = [1000, 900, 500, 400, 100, 90, 50,
                             40, 10, 9, 5, 4, 1]

        # 🏛 Corresponding Roman symbols
        symbols: List[str] = ["M", "CM", "D", "CD", "C", "XC", "L",
                              "XL", "X", "IX", "V", "IV", "I"]

        currentIndex: int = 0  # Tracks position in values/symbols arrays

        # 🔄 Process number from largest to smallest value
        while num > 0:
            
            # ➕ Greedily subtract current value and append its symbol
            while num >= values[currentIndex]:
                romanResult += symbols[currentIndex]  # 🧱 Append symbol
                num -= values[currentIndex]            # ➖ Reduce number
            
            # ⬇️ Move to next smaller Roman numeral
            currentIndex += 1

        # 🎉 Return the final Roman numeral string
        return romanResult