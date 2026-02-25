from libcpp.string cimport string

cdef extern from 'solution.hpp':
    cdef cppclass Solution:
        Solution() except + 
        string intToRoman(int num)

cdef class cppSolution:
    cdef Solution *ptr

    def __init__(self) -> None:
        self.ptr = new Solution()
    
    def __dealloc__(self):
        if self.ptr is not NULL:
            del self.ptr

    def cpp_intToRoman(self, num):
        cdef string result = self.ptr.intToRoman(num)
        return result.decode("utf-8")