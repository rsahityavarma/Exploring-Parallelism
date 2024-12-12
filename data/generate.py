import numpy as np
import pandas as pd

matrix_a = np.random.randint(1, 100, size=(1000, 1000))
pd.DataFrame(matrix_a).to_csv("matrix_a.csv", index=False, header=False)
matrix_b = np.random.randint(1, 100, size=(1000, 1000))
pd.DataFrame(matrix_b).to_csv("matrix_b.csv", index=False, header=False)

