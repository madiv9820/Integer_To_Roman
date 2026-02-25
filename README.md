# [🏛️ Roman Numeral Converter Challenge 🔢](https://leetcode.com/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150)

Imagine you're given an integer…

And your task is to convert it into a **Roman numeral!** 😎

Roman numerals are built using **7 special symbols**:

| **Symbol** | **Value** |
| ------ | ----- |
| I      | 1️⃣   |
| V      | 5️⃣   |
| X      | 🔟    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

### 📜 Rules to Form Roman Numerals

Roman numerals are formed by converting **decimal place values from highest to lowest** (thousands → hundreds → tens → ones).

Let’s break it down:

**1️⃣ If the Number Does NOT Start with 4 or 9 ❌**
- Choose the largest Roman symbol less than or equal to the number.
- Append it to the result.
- Subtract its value.
- Repeat the process 🔁

**2️⃣ If the Number Starts with 4 or 9 ⚠️**

Use the **subtractive form**:
| **Number** | **Roman Form** |
| ------ | ---------- |
| 4      | IV         |
| 9      | IX         |
| 40     | XL         |
| 90     | XC         |
| 400    | CD         |
| 900    | CM         |

👉 Example: <br>
4 = 1 less than 5 → **IV** <br>
9 = 1 less than 10 → **IX**

⚠️ Note: 49 is NOT written as IL. Roman numerals follow place value logic.

**3️⃣ Repetition Rules 🔁**
- I, X, C, and M can be repeated at most **3 times**.
- V, L, and D cannot be repeated.
- If a symbol would repeat 4 times, use subtractive form instead.

### 🎯 Examples
- **✅ Example 1** <br>
    **Input:** 3749 <br>
    **Output:** `"MMMDCCXLIX"` <br>
    Breakdown:
    - 3000 = MMM
    - 700 = DCC
    - 40 = XL
    - 9 = IX

- **✅ Example 2** <br>
    **Input:** 58 <br>
    **Output:** `"LVIII"`
    - 50 = L
    - 8 = VIII

- **✅ Example 3** <br>
    **Input:** 1994 <br>
    **Output:** `"MCMXCIV"`
    - 1000 = M
    - 900 = CM
    - 90 = XC
    - 4 = IV

### 🔒 Constraints
- `1 ≤ num ≤ 3999`
---