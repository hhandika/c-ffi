# %%
import ctypes

from typing import List

from certifi import contents


def main():
    # Define C library
    lib = ctypes.CDLL('lib/vector.so')
    
    x: List[int] = [1, 2, 3, 4, 5]
    print(f"Print from python: {x}")

    # Convert python list to C array
    x_size = 5
    x_arr = (ctypes.c_double * x_size)(*x)
    
    

    # Printing list using C functions. We need to define the function argument datatype first
    lib.print_vectors.argtypes = [ctypes.POINTER(ctypes.c_double), ctypes.c_size_t]
    lib.cumsum.argtypes = [ctypes.POINTER(ctypes.c_double), ctypes.c_size_t]

    lib.print_hello()   
    lib.print_vectors(x_arr, ctypes.c_size_t(x_size))

    
    lib.cumsum.restype = ctypes.POINTER(ctypes.c_double)
    cumsum = lib.cumsum(x_arr, ctypes.c_size_t(x_size))
    
    # Convert C array to python list
    cumsum_list: List[float] = [cumsum[i] for i in range(x_size)]
    print(f"Cumsum result {cumsum_list}")

if __name__ == "__main__":
    main()
