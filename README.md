# Sorting Algorithms Time Complexity Analysis
This repository contains an empirical analysis of four classic sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, and Merge Sort. The analysis focuses on measuring execution time across different input sizes to demonstrate and visualize their time complexity characteristics.
## Project Overview
This project implements and analyzes the time complexity of four sorting algorithms:
- Bubble Sort (O(n²))
- Selection Sort (O(n²))
- Insertion Sort (O(n²))
- Merge Sort (O(n log n))
## Implementation Details
The algorithms were implemented in C++ and tested on arrays of various sizes:

- Array 1: 5 elements
- Array 2: 10 elements
- Array 3: 50 elements
- Array 4: 100 elements

Each algorithm was run 5 times per input size to ensure statistical validity, and the average execution time was recorded.

## Analysis Methodology

### Time Measurement
Used C++'s std::chrono high-resolution clock for precise timing measurements.
### Statistical Averaging
Each algorithm was run 5 times for each input size, and the average execution time was calculated.
### Controlled Environment
Tests were performed on the same machine with minimal background processes to ensure consistency.

## How to Run

### Cloning the Repository

```bash
# Clone the repository to your local machine
git clone https://github.com/Jaffar-Kazmi/Sorting-Algorithms.git

# Navigate into the project directory
cd Sorting-Algorithms
```

### Prerequisites

- C++ compiler
- An IDE of your choice
- 
### Running in an IDE

#### Visual Studio
1. Open Visual Studio
2. Select "Open a project or solution"
3. Navigate to the cloned repository and open the `.sln` file (or create a new solution)
4. Build the project (F7 or Ctrl+Shift+B)
5. Run the program (F5)

#### VS Code
1. Open VS Code
2. Select "Open Folder" and navigate to the cloned repository
3. Install the C/C++ extension if not already installed
4. Configure the build task (Ctrl+Shift+B)
   - You can use tasks.json to set up g++ compilation
5. Run the program using the debugging features (F5) or create a custom task

## Conclusion
The empirical results align with theoretical expectations:

- The O(n²) algorithms (Bubble, Selection, Insertion) generally show quadratic growth as input size increases.
- Merge Sort demonstrates better scaling for larger inputs, confirming its O(n log n) complexity.
- Insertion Sort performs exceptionally well on these particular inputs because they are already sorted, showcasing its best-case O(n) behavior.
## Author
Syed Jaffar Raza Kazmi


