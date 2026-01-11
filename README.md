
# kmath

My 2D math utility library written in C, focused on **trigonometry and basic geometry** for learning purposes and simple simulations.

This project was created to better understand how common math functions (such as `sin`, `cos`, and `sqrt`) can be implemented internally, rather than relying directly on the standard library.


### Trigonometric functions

Implemented using a **CORDIC-based approximation**:

* `ksin(double angle)`
* `kcos(double angle)`
* `ktan(double angle)`

These functions are intended for:

* object rotation
* aiming calculations
* movement along curves

### Geometry & utility functions

* `ksqrt(double x)` — square root (iterative approximation)
* `kfabs(double x)` — absolute value
* `khypot(double x, double y)` — vector magnitude / distance

Useful for:

* distance calculations
* velocity magnitude
* simple 2D physics

---

## API Overview

```c
/* Trigonometric functions */
double ksin(double angle);
double kcos(double angle);
double ktan(double angle);

/* Geometry & utility */
double ksqrt(double x);
double kfabs(double x);
double khypot(double x, double y);
```

---
