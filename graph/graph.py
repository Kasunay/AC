import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# used seaborn because of its simplicity and ease of use

data = pd.read_csv("results_concise.csv", delimiter=",")

data['Input Size'] = pd.to_numeric(data['Input Size'])

sns.set(style="whitegrid")

fig, ax1 = plt.subplots(figsize=(16, 10))

sns.lineplot(x='Input Size', y='Insertion Sort Time', data=data, label='Insertion Sort', ax=ax1)
sns.lineplot(x='Input Size', y='Quick Sort Time', data=data, label='Quick Sort', ax=ax1)
sns.lineplot(x='Input Size', y='Radix Sort Time', data=data, label='Radix Sort', ax=ax1)
sns.lineplot(x='Input Size', y='Heap Sort Time', data=data, label='Heap Sort', ax=ax1)

ax1.set_xlabel("Input Size")
ax1.set_ylabel("Execution Time (seconds)")
ax1.legend()

ax2 = ax1.twinx()
sns.lineplot(x='Input Size', y='Hybrid Sort Time', data=data, color='red', label='Hybrid Sort', ax=ax2)
ax2.set_ylabel("Hybrid Sort Time (seconds)")
ax2.legend(loc='upper right')

plt.title("Comparison of Sorting Algorithms")
plt.savefig("all_algorithms.png")
plt.show()

algorithms = ['Insertion Sort', 'Quick Sort', 'Radix Sort', 'Heap Sort', 'Hybrid Sort']

for algorithm in algorithms:
    plt.figure(figsize=(8, 6))
    sns.lineplot(x='Input Size', y=f'{algorithm} Time', data=data, label=algorithm)
    plt.title(f"{algorithm} Performance")
    plt.xlabel("Input Size")
    plt.ylabel("Execution Time (seconds)")
    plt.legend()
    plt.ylim(bottom=0)
    plt.savefig(f"{algorithm.lower().replace(' ', '_')}.png")
    plt.show()
