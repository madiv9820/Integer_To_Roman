# 🏛️ Integer to Roman – Place Value Mapping Approach

### 📌 Overview

This solution converts an integer into its Roman numeral representation using a **place-value decomposition strategy**.

Instead of dynamically applying Roman numeral rules, we:
- 📚 Predefine all valid Roman numeral chunks (1–3000)
- 🔢 Break the number into place values (ones, tens, hundreds, thousands)
- ➕ Prepend each mapped Roman chunk to build the final result

This keeps the logic simple, readable, and easy to maintain.

### 🧠 Approach
1. **Create a lookup dictionary**

    Map all valid place-value numbers to their Roman symbols:
    - Units: `1–9`
    - Tens: `10–90`
    - Hundreds: `100–900`
    - Thousands: `1000–3000`

2. **Process the number digit by digit**
    - Extract the last digit using modulo (`% 10`)
    - Multiply it by its current place value
    - Retrieve the corresponding Roman symbol
    - Prepend it to the result string

3. **Repeat until the number becomes 0**

### Complexity Analysis 📊
- **⏱️ Time Complexity: `O(d)`**
    - Where `d` is the number of digits in the integer.
    - Since Roman numerals are typically limited to `1 ≤ num ≤ 3999`,
    - `d ≤ 4`, making this effectively:
        - **✅ O(1) (Constant Time)**

- **💾 Space Complexity: `O(1)`**
    - The lookup dictionary size is fixed.
    - The result string length is bounded (maximum Roman numeral length is small and constant).

### ✅ Why This Approach?
- 📖 Easy to understand
- 🧩 No complex Roman subtraction logic
- 🚀 Efficient for bounded inputs
- 🎯 Interview-friendly
---