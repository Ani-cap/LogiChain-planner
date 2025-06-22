
# Smart Supply Chain Planner - Problem Statement

## Overview
You are tasked with building a **Smart Supply Chain Planner** for an e-commerce company that integrates three major graph algorithms to manage its operations effectively:

1. **Topological Sort** – For task dependency scheduling.
2. **Bellman-Ford** – For finding shortest delivery paths from a single hub with support for negative costs (like discounts or incentives).
3. **Floyd-Warshall** – For computing shortest paths between all delivery hubs, allowing global logistics analytics.

The system **must use all three algorithms together**, not as alternatives, but as **contributing modules** to a unified smart supply chain framework.

---

## Functional Requirements

### 1. Task Scheduling Module (Topological Sort)
- Input: A list of tasks and dependencies `(u → v)` meaning task `u` must precede task `v`.
- Output: A valid order of task execution.
- Must detect and report cycles if the dependency graph is invalid.

### 2. Delivery Route Optimizer (Bellman-Ford)
- Input: List of directed delivery routes with weights (some can be negative), and a source hub.
- Output: Shortest delivery cost from the source to every other hub.
- Detect negative weight cycles in the network and report.

### 3. Logistics Analytics Engine (Floyd-Warshall)
- Input: All delivery hubs and pairwise routes with weights.
- Output: A matrix with the shortest cost between every pair of hubs.
- Useful for centralized cost comparison and route optimization dashboards.

---

## Sample Input

### Tasks & Dependencies
Tasks: 0 = Build Warehouse, 1 = Setup Software, 2 = Hire Staff  
Dependencies: (0 → 1), (1 → 2)

### Delivery Routes Between Hubs
Hubs: 0 = Delhi, 1 = Mumbai, 2 = Chennai, 3 = Kolkata  
Edges: (0→1, 4), (1→2, -3), (2→3, 2), (3→1, 1)

---

## Output

- A valid task execution order.
- Shortest path costs from a given hub to all others (Bellman-Ford).
- A full matrix of all-pairs shortest path costs (Floyd-Warshall).

---

## Objective

Build a **C++ project** that reads inputs, runs all three algorithms, and clearly displays their outputs. The modules should be logically connected, simulating a real-world system rather than isolated scripts.
