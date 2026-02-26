from typing import List

class PySolution:
    def int_to_roman(self, num: int) -> str:
        
        # 🏗️ String to store the final Roman numeral
        roman_result: str = ''

        # 🔢 Roman numeral values in descending order
        values: List[int] = [1000, 900, 500, 400, 100, 90, 50,
                             40, 10, 9, 5, 4, 1]

        # 🏛 Corresponding Roman symbols
        symbols: List[str] = ["M", "CM", "D", "CD", "C", "XC", "L",
                              "XL", "X", "IX", "V", "IV", "I"]

        current_index: int = 0  # Tracks position in values/symbols arrays

        # 🔄 Process number from largest to smallest value
        while num > 0:
            
            # ➕ Greedily subtract current value and append its symbol
            while num >= values[current_index]:
                roman_result += symbols[current_index]  # 🧱 Append symbol
                num -= values[current_index]            # ➖ Reduce number
            
            # ⬇️ Move to next smaller Roman numeral
            current_index += 1

        # 🎉 Return the final Roman numeral string
        return roman_result