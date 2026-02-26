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

## Approaches 🧠

| **Feature / Criteria**         | [**Place-Value Dictionary** 🗂️](https://github.com/madiv9820/Integer_To_Roman/tree/Approach_01-Hashmaps)                                | [**Greedy Subtraction** 🚀](https://github.com/madiv9820/Integer_To_Roman/tree/Approach_02-Greedy)                             |
| -------------------------- | --------------------------------------------------------- | ------------------------------------------------- |
| **Strategy**               | Map each digit × place value to a predefined Roman symbol | Subtract largest possible Roman value iteratively |
| **Ease of Understanding**  | Very readable; intuitive for beginners                    | Clean and concise; widely used in interviews      |
| **Code Size**              | Larger lookup table required                              | Smaller; only 13 values & symbols                 |
| **Processing**             | Decompose number into digits; prepend mapped symbols      | Greedy subtraction from largest to smallest value |
| **Reversing Needed**       | Yes, if prepending is done manually                       | No, naturally builds in correct order             |
| **Time Complexity**        | O(1) (digits ≤ 4 for numbers ≤ 3999)                      | O(1) (at most ~15 iterations for numbers ≤ 3999)  |
| **Space Complexity**       | O(1) + lookup table size                                  | O(1) + small result string                        |
| **Interview-Friendliness** | Easy to explain; verbose                                  | Very common & elegant approach                    |


---