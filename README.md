# Smart Supply Chain Planner

> A self-initiated logistics optimizer combining **Topological Sort**, **Bellman-Ford**, and **Floyd-Warshall** to simulate task scheduling and delivery routing for warehouses.

---

## 🔍 Problem

Design a logistics framework where:
- Tasks must respect dependencies (no cycles).
- Delivery costs vary and may include negative incentives.
- Route optimization is required both from single hub and globally.

---

## 🧠 Algorithms Used

- ✅ **Topological Sort**  
  Validates task dependencies and ensures executable scheduling.

- ✅ **Bellman-Ford Algorithm**  
  Computes shortest delivery paths even with negative weights.

- ✅ **Floyd-Warshall Algorithm**  
  Computes shortest paths between **all hubs** efficiently.

---

## 📁 Files

- `main.cpp` – Complete implementation and demonstration
- `problem_statement.md` – Original assignment brief

---

## 🧪 How to Run

```bash
g++ main.cpp -o planner
./planner
