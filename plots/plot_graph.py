import pandas as pd
import matplotlib.pyplot as plt

# Load execution times
data = pd.read_csv("plots/execution_times.csv")

# Plot the data
plt.figure(figsize=(8, 6))
plt.bar(data["Model"], data["Execution Time (seconds)"], color="skyblue")
plt.xlabel("Model")
plt.ylabel("Execution Time (seconds)")
plt.title("Performance Comparison of Parallel Models")

# Save the graph to a file
plt.savefig("plots/execution_times_graph.png")
print("Graph saved as 'plots/execution_times_graph.png'")

