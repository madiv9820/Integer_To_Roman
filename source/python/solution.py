from typing import Dict

class pySolution:
    def py_intToRoman(self, num: int) -> str:
        # 🏗️ This will store the final Roman numeral result
        romanResult: str = ""

        # 📚 Mapping of place-value integers to Roman numerals
        # Covers units, tens, hundreds, and thousands
        valueToRoman: Dict[int, str] = {
            1: 'I', 2: 'II', 3: 'III', 4: 'IV', 5: 'V',
            6: 'VI', 7: 'VII', 8: 'VIII', 9: 'IX',
            10: 'X', 20: 'XX', 30: 'XXX', 40: 'XL', 50: 'L',
            60: 'LX', 70: 'LXX', 80: 'LXXX', 90: 'XC',
            100: 'C', 200: 'CC', 300: 'CCC', 400: 'CD',
            500: 'D', 600: 'DC', 700: 'DCC', 800: 'DCCC', 900: 'CM',
            1000: 'M', 2000: 'MM', 3000: 'MMM'
        }

        # 🔢 Tracks current place value:
        # 1 → ones, 10 → tens, 100 → hundreds, 1000 → thousands
        placeValue: int = 1

        # 🔄 Process digits from right (least significant) to left
        while num > 0:
            # ✂️ Extract the current digit and scale it by place value
            # Example: if number = 374
            # First: 4 * 1   = 4
            # Second: 7 * 10  = 70
            # Third: 3 * 100 = 300
            digitValue: int = (num % 10) * placeValue

            # 🔎 Get corresponding Roman numeral (empty string if not found)
            romanChunk: str = valueToRoman.get(digitValue, "")

            # ➕ Prepend because we process from smallest place value first
            romanResult = romanChunk + romanResult

            # ➗ Remove processed digit
            num //= 10

            # ⬆️ Move to next place value
            placeValue *= 10

        # 🎉 Return the constructed Roman numeral
        return romanResult