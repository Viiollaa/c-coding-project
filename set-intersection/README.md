# Set Intersection Counter

A high-performance C-based utility designed to efficiently count pairs of string segments that satisfy a specific character set intersection requirement. This project focuses on memory management and bitwise/boolean logic optimization.

## Problem Statement
Given a target set of characters and a string `k` divided into `n` segments, identify how many unique pairs of segments `(i, j)` have an intersection that matches the target set exactly.

## Technical Implementation
The core of this solution lies in **Boolean Mapping**, which avoids expensive string comparisons:
- **Boolean Frequency Arrays:** Each segment is mapped to a `bool[26]` array, acting as a bitmap for character existence.
- **Logical Intersection:** Uses logical AND (`&&`) operations to determine the intersection between two segment maps.
- **Complexity:** The solution operates at $O(part^2 \times 26)$, providing an efficient way to process character sets compared to naive string search.



## Key Skills Demonstrated
* **Systems Programming:** Proficient in C for memory-efficient data processing.
* **Algorithmic Optimization:** Replaced expensive operations with boolean logic and constant-time lookups ($O(1)$).
* **Data Representation:** Utilized multidimensional boolean arrays to handle complex set-based constraints.

## How to Run
1. Ensure you have a C compiler (like `gcc`) installed.
2. Compile the code: `gcc set_intersection.c -o set_intersection`
3. Run the executable: `./set_intersection`
4. Provide the required input as specified in the source code.
