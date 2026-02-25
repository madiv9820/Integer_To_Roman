from libc.stdlib cimport free

cdef extern from 'solution.h':
    char* intToRoman(int num)

cdef class cSolution:
    def c_intToRoman(self, num):
        cdef char* result = intToRoman(num)
        if result is NULL:
            raise MemoryError('intToRoman returned NULL')
        
        py_result = result.decode('utf-8')
        if result is not NULL:
            free(result)

        return py_result
