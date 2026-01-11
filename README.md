# ⚓ Advanced Naval Battle Simulation System

## 📌 Project Overview

The Advanced Naval Battle Simulation System is a C based simulation that models a naval combat scenario involving a battleship and multiple escort ships. The system calculates ship positions, firing ranges, hit probabilities, and battle outcomes using mathematical and logical rules. A two dimensional grid is used to visualize the battlefield and ship movements.

This project was developed as part of the SE1012 Programming Module.

---

## 🎯 Objectives

- Simulate a naval battle using structured C programming
- Model escort ships and a battleship using structures
- Read battle configurations from an external data file
- Calculate distances, firing angles, and ranges
- Simulate battleship movement and gun jamming
- Visualize the battlefield using a 2D grid
- Produce detailed battle results and statistics

---

## 🛠️ Technologies Used

- Programming Language: C  
- Compiler: GCC  
- Key Concepts:
  - Structures
  - File handling
  - Mathematical computations
  - Conditional logic and loops
  - Simulation modeling

---

## 📂 Project Structure

```
Advanced-Naval-Battle-Simulation/
│
├── main.c
├── data.dat
├── README.md
```

---

## 📥 Input Description

The simulation reads data from `data.dat`, which includes:

- Number of escort ships
- Escort ship details:
  - ID and type (A, B, C, D, E)
  - Position coordinates (x, y)
  - Impact power
  - Time between two firings
  - Shooting angle range
  - Shell velocity range
  - Minimum and maximum range
  - Gamma value
- Battleship details:
  - Type
  - Starting position
  - Travel points
  - Shell velocity range
  - Maximum firing range
  - Gamma value

---

## 📤 Output Description

The program outputs:

- A two dimensional battlefield grid
- Battleship movement path
- Gun jamming events
- Updated attacking angles
- Number of escort ships hit
- Battle duration
- Battleship remaining health or sinking status
- Order of escort ships attacked

---

## 🗺️ 2D Battlefield Grid Representation

The battlefield is represented using a two dimensional grid to provide a clear spatial view of ship positions and movement.

### Symbols Used

| Symbol | Meaning |
|--------|---------|
| A, B, C, D, E | Escort ship types |
| # | Battleship starting position |
| * | Battleship travel point |
| - | Empty sea cell |

This grid helps in understanding engagement zones, validating distance calculations, and visually tracking the progress of the battle.

---

## ▶️ How to Compile and Run

### Compile

```
gcc main.c -o naval_simulation -lm
```

### Run

```
./naval_simulation
```

Make sure `data.dat` is in the same directory as `main.c`.

---

## 📊 Results Summary

- Escort ships hit range from 11 to 18 depending on scenario
- Battle duration varies based on escort ship density
- Gun jamming directly affects battleship attack capability
- Battleship may survive or sink based on damage received

---

## 🚀 Future Improvements

- Graphical user interface
- Dynamic ship movement
- Advanced probability based damage modeling
- Multiple battleship coordination
- Real time simulation visualization

---

## 👤 Author

Dilusha Chamika  
Undergraduate, Computer Systems Engineering  
SLIIT  

---

## 📜 License

This project is developed for educational purposes as part of university coursework.
