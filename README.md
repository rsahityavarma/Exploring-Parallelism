# Exploring-Parallelism
This project demonstrates the performance comparison of various parallelization techniques (Serial, P-thread, OpenMP, MPI). The execution times of each model are compared and visualized in a bar chart.

## Features
- Serial matrix multiplication
- P-thread parallelization
- OpenMP parallelization
- MPI-based distributed parallelization
- Graphical comparison of execution times

  ## Dataset
- The project uses two matrices:
- matrix_a: A 999 x 1000 matrix.
- matrix_b: A 1000 x 999 matrix.
- The datasets are generated using random integers between 1 and 99 and saved as CSV files. 
- You can also generate the datasets using the provided Python script.

  ## Execution Times Graph
![execution_times_graph](https://github.com/user-attachments/assets/04387930-0e7a-4f8b-972b-b03ea378bd7a)


## Requirements
### Tools
- JupyterLab
- OpenMPI (for MPI model)
- Python 3 with `pandas` and `matplotlib` libraries

### Python Libraries
Install the required Python libraries:
```bash
pip3 install pandas matplotlib

## Usage
1. Compile:
   ```bash
   make
