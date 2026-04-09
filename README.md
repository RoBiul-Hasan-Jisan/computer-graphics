#  Computer Graphics Algorithms (OpenGL - C/C++)

This repository contains implementations of fundamental **Computer Graphics algorithms** using **OpenGL (GLUT) in C/C++**.
It is designed for learning, practice, and academic purposes .

---

##  Implemented Algorithms

###  Line Drawing

*  **DDA (Digital Differential Analyzer) Algorithm**
*  **Bresenham Line Drawing Algorithm**

###  Circle Drawing

*  **Midpoint Circle Algorithm (Bresenham Circle)**

###  Filling Algorithms

*  **Flood Fill Algorithm (4-connected)**
*  **Boundary Fill Algorithm (4-connected)**

###  Fractals

*  **Sierpinski Gasket (Recursion, Depth-based)**

---

##  Concepts Covered

* Incremental algorithms
* Integer vs floating-point computation
* Recursion in graphics
* Symmetry in drawing (circle)
* Pixel-level manipulation using OpenGL

---

##  Requirements

* C/C++ Compiler (GCC / MinGW / CodeBlocks)
* OpenGL Libraries:

  * `GL`
  * `GLU`
  * `GLUT`

---

##  How to Run

###  Compile (Windows - CodeBlocks / MinGW)

```bash
g++ filename.cpp -o output -lglut -lGLU -lGL
```

###  Run

```bash
./output
```

---

##  Usage

* Some programs use **keyboard input** (e.g., line endpoints, circle radius)
* Some use **mouse interaction**:

  *  Click inside shape → fill (Flood/Boundary Fill)

---



##  Output Preview

* Line drawing using DDA & Bresenham
* Circle using Midpoint Algorithm
* Filled shapes using Flood/Boundary Fill
* Recursive fractal (Sierpinski Triangle)

---

##  Learning Purpose

This project helps to understand:

* How graphics are rendered at pixel level
* Differences between classic algorithms
* Efficiency improvements (DDA vs Bresenham)

---

##  Future Improvements

* [ ] 8-connected fill algorithms
* [ ] Scan-line polygon fill
* [ ] Ellipse drawing algorithm
* [ ] Interactive UI (mouse-based drawing)

---

##  Author
**Robiul Hasan Jisan**

- **Portfolio:** [robiulhasanjisan.vercel.app](https://robiulhasanjisan.vercel.app/)
- **GitHub:** [@RoBiul-Hasan-Jisan](https://github.com/RoBiul-Hasan-Jisan)


---




**This project is open-source and free to use for educational purposes.**
