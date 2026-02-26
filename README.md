# 🏛️ Integer to Roman – Greedy Subtractive Approach

### 📌 Overview

This solution converts an integer into its Roman numeral representation using a **greedy subtraction strategy**.

Instead of mapping every possible place value, we:
- 🔢 Start from the largest Roman numeral value
- ➕ Repeatedly subtract it from the number
- 🏗️ Append the corresponding Roman symbol directly to the result

This method builds the Roman numeral in the correct order **without reversing** or needing large lookup tables.

### 🧠 Approach

1. **Prepare values and symbols**
    ```
    values  = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbols = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
    ```

2. **Greedy subtraction**
    - Iterate through the arrays from largest to smallest value
    - While the current number ≥ current value:
        - Subtract the value
        - Append its Roman symbol to the result

3. **Repeat** until the number becomes 0

### Complexity Analysis 📊
- **⏱️ Time Complexity**
    - **`O(1)`** — Maximum number is 3999, so the algorithm performs at most ~15 iterations.
    - Efficient for all practical use cases.

- **💾 Space Complexity**
    - **`O(1)`** — Fixed-size arrays for values and symbols.
    - The result string grows only proportional to the number of Roman characters.

### ✅ Why This Approach?
- 🧩 Very simple and readable
- 🚀 Efficient and fast for all valid integers
- 🎯 No need for reversing or large lookup tables
- 🏆 Interview-friendly and widely used in practice
---