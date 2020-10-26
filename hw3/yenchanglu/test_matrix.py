import pytest
import unittest
import numpy as np
import math
from _matrix import Matrix, multiply_naive, multiply_tile, multiply_mkl

class test_matrix(unittest.TestCase):
    def exec_time(self):
        mat1 = Matrix(np.random.random((1151, 1151)))
        mat2 = Matrix(np.random.random((1151, 1151)))

        timer_naive = []
        timer_tile = []
        timer_mkl = []

        mat_ans = np.matmul(mat1, mat2)

        for i in range(5):
            timer = time.time()
            mat_naive = multiply_naive(mat1, mat2)
            timer_naive.append(time.time() - timer)

            timer = time.time()
            mat_tile = multiply_tile(mat1, mat2, 64)
            timer_tile.append(time.time() - timer)

            timer = time.time()
            mat_mkl = multiply_mkl(mat1, mat2)
            timer_mkl.append(time.time() - timer)

            self.assertTrue(abs(mat_ans - mat_naive) < 0.001)
            self.assertTrue(abs(mat_ans - mat_tile) < 0.001)
            self.assertTrue(abs(mat_ans - mat_mkl) < 0.001)


        with open("performance.txt", "w") as f:
            f.write("Average execution time\n")
            f.write("mutiply_naive: {} secs\n".format("%.4f"%np.average(timer_naive)))
            f.write("multiply_tile: {} secs\n".format("%.4f"%np.average(timer_tile)))
            f.write("multiply_mkl: {} secs\n".formate("%.4f"%np.average(timer_mkl)))
            f.write("The tiling version is {:.1%} faster than naive version\n".format(timer_naive / timer_tile))
            f.write("The mkl version is {:.1%} faster than naive version\n".format(timer_naive / timer_mkl))
            f.close()

if __name__ == "__main__":
    unittest.main()
