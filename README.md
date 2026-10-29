# ⚡ Circuit Theory Learning Program (UGEA1243)

A console-based C++ program that helps students learn and practise the basics of **Circuit Theory (UGEA1243)**. It includes a user login system, a course overview, a 20-question quiz with a scoreboard, and three calculators (resistor/capacitor, Ohm's law and transformer).

---

## 📑 Table of Contents

1. [Features](#-features)
2. [Project Structure](#-project-structure)
3. [Requirements](#-requirements)
4. [How to Compile and Run](#-how-to-compile-and-run)
5. [Program Flow](#-program-flow)
6. [Menus Explained](#-menus-explained)
7. [The Activities](#-the-activities)
8. [Data Files and Their Format](#-data-files-and-their-format)
9. [Input Validation Rules](#-input-validation-rules)
10. [Function Reference](#-function-reference)
11. [Formulas Used](#-formulas-used)
12. [Known Limitations](#-known-limitations)
13. [Possible Improvements](#-possible-improvements)

---

## ✨ Features

| Feature | Description |
|---|---|
| **Login & Sign Up** | Users create an account (stored in `udata.txt`) and must log in before using the activities. |
| **Course Information** | Shows the course title banner, course introduction, learning outcomes (CLOs) and the full chapter list. |
| **Activity 1 – Quiz** | 10 multiple-choice + 10 true/false questions, instant feedback with explanations, final score saved to a scoreboard. |
| **Activity 2 – Resistor & Capacitor Calculator** | Adds resistors/capacitors in series or parallel and converts between units (milli, micro, kilo, mega). |
| **Activity 3 – Ohm's Law Calculator** | Calculates Voltage, Current or Resistance. |
| **Activity 4 – Transformer Calculator** | Calculates primary/secondary voltage or number of coil turns, and shows the turns ratio. |

---

## 📁 Project Structure

```
.
├── finaldraft4.cpp     # Main source code (all program logic)
├── mcqquestion.txt     # Multiple-choice questions + options
├── mcqanswer.txt       # Multiple-choice answers + explanations
├── tfquestions.txt     # True/False questions
├── tfanswers.txt       # True/False answers + explanations
├── udata.txt           # Stores registered users (username:password)
├── scoresheet.txt      # Stores quiz results (nickname:score)
└── README.md           # This file
```

> ⚠️ All `.txt` files **must be in the same folder** the program is run from, otherwise the quiz and login will not find their data.

---

## 🛠 Requirements

- A C++ compiler supporting **C++11 or newer** (e.g. `g++`, MinGW, Dev-C++, Code::Blocks, Visual Studio)
- Any terminal / command prompt

---

## ▶️ How to Compile and Run

### Using g++ (Linux / macOS / Windows with MinGW)

```bash
g++ -std=c++11 finaldraft4.cpp -o circuit
./circuit          # Linux / macOS
circuit.exe        # Windows
```

### Using an IDE (Dev-C++ / Code::Blocks)

1. Open `finaldraft4.cpp`.
2. Make sure all `.txt` files are in the same folder as the `.cpp` file.
3. Click **Compile & Run**.

> 💡 If you get an error like `'pow' was not declared in this scope`, add `#include <cmath>` to the top of the file (see [Known Limitations](#-known-limitations)).

---

## 🔄 Program Flow

```
main()
 └── MAIN MENU
      ├── 1. Course Title          → shows ASCII banner
      ├── 2. Course Introduction   → course description + CLOs
      ├── 3. Menu  ──────────────► LOGIN MENU
      │                              ├── 1. Login  ──(success)──► ACTIVITY MENU
      │                              ├── 2. Sign up                 ├── 1. Introduction
      │                              └── 3. Exit                    ├── 2. Topic (chapters)
      │                                                             ├── 3. Activity Description
      │                                                             ├── 4. Activity 1 – Quiz
      │                                                             ├── 5. Activity 2 – R & C Calculator
      │                                                             ├── 6. Activity 3 – Ohm's Law
      │                                                             ├── 7. Activity 4 – Transformer
      │                                                             └── 8. Exit
      └── 4. Exit
```

---

## 📋 Menus Explained

### 1. Main Menu (`mainmenu()`)
The first screen. Lets the user view the course title banner, read the course introduction, go to the login menu, or exit.

### 2. Login Menu (`loginmenu()`)
Users **must log in** before reaching the activities.
- **Login** – checks the entered username and password against `udata.txt`.
- **Sign up** – creates a new account after validating the username and password.

### 3. Activity Menu (`menu()`)
The main learning area with 8 options, including the 4 activities.

---

## 🎯 The Activities

### Activity 1 – Interactive Quiz
- **Part 1:** 10 multiple-choice questions (answer `A`, `B`, `C` or `D`)
- **Part 2:** 10 true/false questions (answer `T` or `F`)
- Lowercase input is accepted (it is converted to uppercase).
- After every question, the correct answer and an explanation are shown.
- At the end, the total score (out of 20) is shown and the user enters a **nickname** to save it to `scoresheet.txt`.
- **View Past Results** lists all saved scores.

**Topics covered:** current, Ohm's law, conductance, KVL, KCL, series/parallel resistance, source transformation, power, Δ–Y transformation, capacitors and current sources.

### Activity 2 – Resistor & Capacitor Calculator
| Option | What it does |
|---|---|
| Add resistors | Series: `R = R1 + R2 + …` · Parallel: `1/R = 1/R1 + 1/R2 + …` |
| Add capacitors | Parallel: `C = C1 + C2 + …` · Series: `1/C = 1/C1 + 1/C2 + …` |
| Conversion calculator | Converts between Ω/mΩ/µΩ/kΩ/MΩ or F/mF/µF/kF/MF |

The calculator also prints the working, e.g.:
```
Calculations:
resistor total = 5 + 10 + 15 = 30
```

> Note: resistors and capacitors combine in **opposite** ways — series resistors add directly, but parallel capacitors add directly. The program handles this by reusing the same two functions (`normal()` and `inverse()`) in swapped order.

### Activity 3 – Ohm's Law Calculator
Choose what to calculate:
1. Voltage `V = I × R`
2. Current `I = V / R`
3. Resistance `R = V / I`

The user can repeat calculations by answering `Y`.

### Activity 4 – Transformer Calculator
Choose what to calculate:
1. Primary voltage `Vp = (Np / Ns) × Vs`
2. Secondary voltage `Vs = (Ns / Np) × Vp`
3. Primary turns `Np = (Vp / Vs) × Ns`
4. Secondary turns `Ns = (Vs / Vp) × Np`

The program also shows the related ratio (voltage ratio or turns ratio).

---

## 🗂 Data Files and Their Format

Every data file uses a **colon (`:`) as the separator**. The program splits each line at the **first** colon only.

| File | Format | Example |
|---|---|---|
| `udata.txt` | `username:password` | `nadsstudent01:Pass@1234` |
| `scoresheet.txt` | `nickname:score` | `nadsplayer:17` |
| `mcqquestion.txt` | `question:options` | `Q2. ... what is the voltage across it?: A) 3V B) 16V C) 48V D) 60V` |
| `mcqanswer.txt` | `answer:explanation` | `C: 48V (V = I × R ⇒ 12Ω × 4A = 48V)` |
| `tfquestions.txt` | `question:options` | `Q6. The conductance ... resistance.: T(True) or F(False)` |
| `tfanswers.txt` | `answer:explanation` | `T: Conductance=1/Resistance` |

### Adding or editing quiz questions
- Line *n* in the question file must match line *n* in the answer file.
- The answer (left of the colon) must be a **single capital letter** with no spaces, e.g. `B`.
- Each quiz part reads exactly **10 lines**, so each file needs at least 10 valid lines.
- Do **not** put a colon inside the question text itself, or the split will happen in the wrong place.

This is also why usernames and passwords are not allowed to contain `:`.

---

## ✅ Input Validation Rules

### Username (also used for quiz nickname)
- 8 – 30 characters
- Letters and numbers only (no spaces or symbols)
- Must not already exist in `udata.txt` (sign up only)

### Password
- 8 – 30 characters
- At least **1 uppercase**, **1 lowercase**, **1 number** and **1 symbol**
- Must **not** contain a colon `:`

### Numeric input
Most menus use `clear()` to detect non-numeric input, reset `cin` and discard the bad line so the program does not get stuck in an infinite loop.

---

## 📚 Function Reference

### Utility functions
| Function | Purpose |
|---|---|
| `clear()` | If `cin` is in a fail state, prints "Invalid input", clears the error and discards the rest of the line. |
| `getdata(a, b, filename)` | Reads a file line by line, splits each line at the first `:`, and stores the left part in vector `a` and the right part in vector `b`. Used by the quiz and sign-up. |

### Account functions
| Function | Purpose |
|---|---|
| `PasswordChecker(password)` | Validates password rules; returns `true` if accepted. |
| `usernamechecker(username)` | Validates username rules; returns `true` if accepted. |
| `login(isLoggedIn)` | Loads all users from `udata.txt`, looks up the username, compares the password and sets `isLoggedIn = true` on success. |
| `signup()` | Asks for a unique, valid username and a valid password, then appends `username:password` to `udata.txt`. |

### Information functions
| Function | Purpose |
|---|---|
| `title()` | Prints the ASCII art banner. |
| `courseintroduction()` | Prints the course description and the 4 CLOs. |
| `intrduction()` | Short introduction to the program. |
| `chapters()` | Lists all 6 chapters and their sub-topics. |
| `activitydescription()` | Describes the 4 activities. |

### Quiz functions (Activity 1)
| Function | Purpose |
|---|---|
| `quizz(qFile, aFile, points)` | Loads a question file and answer file, asks 10 questions, checks answers and counts points. |
| `sumscore()` | Runs the MCQ part then the T/F part, totals the score, asks for a nickname and saves it. |
| `storedata(name, score)` | Appends `name:score` to `scoresheet.txt`. |
| `showresult()` | Reads and prints every saved score. |
| `activity1()` | Quiz sub-menu (Start / View results / Exit). |

### Calculator functions (Activity 2)
| Function | Purpose |
|---|---|
| `normal(device, symbol, letter)` | Direct sum: `X = X1 + X2 + …` (series resistors, parallel capacitors). |
| `inverse(device, symbol, letter)` | Reciprocal sum: `1/X = 1/X1 + 1/X2 + …` (parallel resistors, series capacitors). |
| `conversioncalc(choice)` | Unit converter. Converts the value to the base unit using powers of 10, then to the target unit. |
| `activity2()` | Sub-menu for Activity 2. |

### Calculator functions (Activities 3 & 4)
| Function | Purpose |
|---|---|
| `ohm(choice, V, I, R, result)` | Reads the two known values and calculates the third. |
| `ohmslawcalc()` | Menu and repeat loop for the Ohm's law calculator. |
| `transformer(choice, Vp, Vs, Np, Ns, ratio, result)` | Reads the three known values and calculates the fourth plus the ratio. |
| `transformercalc()` | Menu and repeat loop for the transformer calculator. |

### Menu functions
| Function | Purpose |
|---|---|
| `mainmenu()` | Top-level menu. |
| `loginmenu()` | Login / sign-up menu. |
| `menu()` | Activity menu (only reachable after login). |
| `main()` | Entry point – calls `mainmenu()`. |

---

## 🧮 Formulas Used

| Concept | Formula |
|---|---|
| Ohm's law | `V = I × R`, `I = V / R`, `R = V / I` |
| Conductance | `G = 1 / R` |
| Power | `P = V × I = V² / R` |
| Series resistors | `Req = R1 + R2 + … + Rn` |
| Parallel resistors | `1/Req = 1/R1 + 1/R2 + … + 1/Rn` |
| Parallel capacitors | `Ceq = C1 + C2 + … + Cn` |
| Series capacitors | `1/Ceq = 1/C1 + 1/C2 + … + 1/Cn` |
| Transformer | `Vp / Vs = Np / Ns` |
| Unit conversion | `result = value × 10^(from) ÷ 10^(to)` |

---

## ⚠️ Known Limitations

These are things a reviewer may notice in the current version:

1. **Passwords are stored in plain text** in `udata.txt`. This is fine for a class project but is not secure for real use. Do not commit a `udata.txt` that contains real passwords.
2. **`#include <cmath>` is missing.** `pow()` is used in Activity 2; some compilers will fail to build without it.
3. **`isLoggedIn` is not initialised** in `loginmenu()` (`bool isLoggedIn;`). It should be `bool isLoggedIn = false;` so a failed login can never open the menu by accident.
4. **No division-by-zero check** in the Ohm's law, transformer and parallel/series calculators (e.g. entering `R = 0` for current).
5. **Transformer menu label for option 3** reads `Np = (Vs/Vp) x Np`; the code correctly calculates `Np = (Vp / Vs) × Ns`, so only the printed label is wrong.
6. **Minor text issues:** a stray `3` after the chapter heading, a stray `7` in the series prompt, no space before `score =` on the results screen, and some typos (e.g. "intrduction", "varifies").
7. Activity 2 menu checks `cin.fail()` **before** reading the choice, so letters entered at that menu are not caught correctly.
8. The quiz always reads exactly **10 questions** per part; fewer lines in a file would crash the program.

---

## 🚀 Possible Improvements

- Hash passwords (e.g. SHA-256) instead of storing them in plain text.
- Add a leaderboard sorted from highest to lowest score.
- Randomise question order.
- Add the remaining chapters (mesh/nodal analysis, Thevenin/Norton, AC phasors) as new activities.
- Split the code into several `.cpp`/`.h` files (e.g. `auth`, `quiz`, `calculators`) for easier maintenance.

---

## 👥 Authors

Developed as a group project for **UGEA1243 Circuit Theory**.
<!-- Add group member names and student IDs here -->

## 📄 License

This project is for educational purposes.
