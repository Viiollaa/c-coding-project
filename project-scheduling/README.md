# Project Scheduling

A robust task scheduler implemented in C, designed to calculate the total duration of a project by analyzing task dependencies and calculating the earliest possible finish time for each task.

## Key Features
* **Dependency Resolution:** Uses Topological Sort (Kahn's Algorithm) to handle complex inter-task dependencies.
* **Early Finish Calculation:** Dynamically updates the earliest possible completion time for each task based on its predecessors.
* **Efficiency:** Operates with $O(V + E)$ time complexity, where $V$ is the number of tasks and $E$ is the number of dependencies, ensuring high performance even with large projects.

## Technical Implementation
- **Data Structure:** Utilizes a custom `struct` to encapsulate task properties (duration, waitlist, dependencies, and finish times).
- **Graph Traversal:** Implements a greedy approach to process tasks with zero pending dependencies (in-degree = 0).
- **Concurrency Logic:** Correctly propagates finish times through the dependency chain to identify the project's critical path.
