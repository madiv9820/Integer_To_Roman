import unittest, json, os
from timeout_decorator import timeout  # ⏱️ Enforce time limit per test
from source.python.solution import pySolution

# 🏛️ Unit tests for the Python implementation of Integer → Roman conversion
class test_py_Solution(unittest.TestCase):

    def setUp(self):
        """
        📂 Load Roman numeral test cases from JSON file
        and initialize the Python solution instance.
        """
        currentDirectory = os.path.dirname(os.path.abspath(__file__))       # 📍 Directory of this test file
        filePath = os.path.join(currentDirectory, 'cases/test_cases.json')  # 📄 Path to JSON test cases
        
        # 🔓 Open and parse JSON test cases
        with open(filePath, mode="r", encoding="utf-8") as read_file: 
            self.__testcases = json.load(read_file)  # 🗂️ List of Roman numeral test cases
            self.__solution = pySolution()           # ⚡ Initialize Python solution class

        return super().setUp()
    
    @timeout(1)  # ⏱️ Each test must complete within 1 second
    def test(self):
        """
        🔄 Iterate through each test case and validate
        integer → Roman numeral conversion.
        """
        for testcase in self.__testcases:
            testName: str = testcase['name']                    # 📝 Name/description of the test case
            num: int = testcase['num']                          # 🔢 Input integer
            expectedOutput: str = testcase['expectedOutput']    # 🏛️ Expected Roman numeral

            # 🔍 Use subTest for clearer per-case reporting
            with self.subTest(testName):
                actualOutput: str = self.__solution.py_intToRoman(num=num)
                self.assertEqual(actualOutput, expectedOutput)  # ✅ Verify correctness

# 🏁 Run tests when executed directly
if __name__ == '__main__':
    unittest.main()