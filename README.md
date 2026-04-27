# Knapsack Problem with Magic Spheres 🎒

A creative implementation of the classic **0/1 Knapsack Problem** in C++, featuring a unique "Magic Spheres" mechanic.

## 💡 The Problem
In this variation, you are not just choosing items to fit into a backpack. You can also carry **Magic Spheres**.
* **Regular Items:** Have a specific weight and value.
* **Magic Spheres:** Take up space (`sphere_weight`) but **exponentially increase** the total value of all collected items by a factor of $2^k$ (where $k$ is the number of spheres).

The goal is to find the perfect equilibrium between carrying heavy loot and sacrificing space for magic multipliers.

## 🚀 Complexity
The algorithm uses **Dynamic Programming** to solve the base problem and then optimizes for the number of spheres:
* **Time Complexity:** $O(n \cdot \text{capacity} + M)$
* **Space Complexity:** $O(n \cdot \text{capacity})$
