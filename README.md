# Vector Calculator — Qt GUI

A C++ desktop application built with Qt 6 for performing 2D and 3D vector operations through a graphical user interface.

---

## Preview

The application features a fixed 800×600 window with two vector input rows, mode checkboxes, and operation buttons. Results are displayed in a large output field at the bottom.

```
┌─────────────────────────────────────────┐
│          VECTOR CALCULATOR              │
│  [  x  ] [  y  ] [  z  ]   ☐ 3-D      │
│  [  x  ] [  y  ] [  z  ]   ☐ Multiply  │
│                              ☐ Magnitude│
│  [ Add ] [ Sub ] [ Mult ]              │
│  [ Dot ] [Cross] [Angle ]              │
│  [ Mag ]         [ Plot ]              │
│                                         │
│         Resultant: {x, y, z}           │
└─────────────────────────────────────────┘
```

---

## Features

- **Vector Addition** — Add two 2D or 3D vectors
- **Vector Subtraction** — Subtract two 2D or 3D vectors
- **Scalar Multiplication** — Multiply a vector by a scalar value
- **Dot Product** — Compute the scalar dot product of two vectors
- **Cross Product** — Compute the cross product (3D only)
- **Magnitude** — Compute the length of a single vector
- **Angle Between Vectors** — Compute the angle in degrees between two vectors
- **Plot** — *(In development)*

---

## Project Structure

```
ActualVectorCalculator/
├── main.cpp            # Application entry point
├── mainwindow.h        # MainWindow class declaration
├── mainwindow.cpp      # MainWindow implementation and slot logic
├── mainwindow.ui       # Qt Designer UI file (800x600 layout)
├── vector.h            # Vector2D and Vector3D class declarations
└── vector.cpp          # Vector2D and Vector3D method implementations
```

---

## Dependencies

| Dependency | Version | Purpose |
|:-----------|:-------:|:--------|
| [Qt](https://www.qt.io/) | 6.x | GUI framework |
| C++ Standard Library | C++17 | `std::variant`, `std::visit` |

No external libraries required beyond Qt.

---

## Building the Project

### Using Qt Creator (Recommended)

1. Open Qt Creator
2. Open the project `.pro` or `CMakeLists.txt` file
3. Select your kit (e.g., Desktop Qt 6.9.1 MinGW 64-bit)
4. Click **Build** → **Run**

### Using CMake from the command line

```bash
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/path/to/Qt/6.x.x/mingw_64
cmake --build .
```

---

## Usage

### Entering Vectors

Two rows of input fields are provided — one for each vector. Each row has three fields for X, Y, and Z components.

- **2D mode (default):** Fill in X and Y only. The Z field is disabled.
- **3D mode:** Check the **3-D** checkbox to enable the Z field for both vectors.

All fields only accept real numbers — invalid input is rejected automatically.

### Mode Checkboxes

| Checkbox | Effect |
|:---------|:-------|
| **3-D** | Enables the Z component fields and unlocks Cross Product |
| **Vector Multiplication** | Disables Vector 2 fields (except the scalar field in V2's Y slot), enables only the Multiply button |
| **Magnitude** | Disables Vector 2 fields entirely, enables only the Magnitude button |

### Operation Buttons

Click any enabled button to compute the result — it appears in the result field at the bottom.

| Button | Input Required | Output |
|:-------|:--------------|:-------|
| Vector Addition | Two vectors (same dimension) | Vector |
| Vector Subtraction | Two vectors (same dimension) | Vector |
| Vector Multiplication | One vector + scalar in V2.Y field | Vector |
| Dot Product | Two vectors (same dimension) | Scalar |
| Cross Product | Two 3D vectors | Vector |
| Angle Between | Two vectors (same dimension) | Scalar (degrees) |
| Magnitude | One vector | Scalar |
| Plot | *(not yet implemented)* | — |

### Example — Dot Product (2D)

```
Vector 1:  [ 3 ]  [ 4 ]  [   ]
Vector 2:  [ 1 ]  [ 2 ]  [   ]

→ Resultant: {11}
```

### Example — Cross Product (3D)

```
☑ 3-D

Vector 1:  [ 1 ]  [ 0 ]  [ 0 ]
Vector 2:  [ 0 ]  [ 1 ]  [ 0 ]

→ Resultant: {0, 0, 1}
```

---

## Supported Operations by Dimension

| Operation | 2D | 3D |
|:----------|:--:|:--:|
| Addition | ✅ | ✅ |
| Subtraction | ✅ | ✅ |
| Scalar Multiplication | ✅ | ✅ |
| Dot Product | ✅ | ✅ |
| Cross Product | ❌ | ✅ |
| Magnitude | ✅ | ✅ |
| Angle Between | ✅ | ✅ |
| Plot | 🔧 | 🔧 |

---

## Vector Class API

### Vector2D

```cpp
Vector2D(double x, double y);
Vector2D operator+(const Vector2D& other) const;
Vector2D operator-(const Vector2D& other) const;
Vector2D operator*(double scalar) const;
double dotProduct(const Vector2D& other) const;
double magnitude() const;
double angleBetween(const Vector2D& other) const; // returns degrees
Vector2D normalize() const;
```

### Vector3D

```cpp
Vector3D(double x, double y, double z);
Vector3D operator+(const Vector3D& other) const;
Vector3D operator-(const Vector3D& other) const;
Vector3D operator*(double scalar) const;
double dotProduct(const Vector3D& other) const;
Vector3D crossProduct(const Vector3D& other) const;
double magnitude() const;
double angleBetween(const Vector3D& other) const; // returns degrees
Vector3D normalize() const;
```

---

## Implementation Notes

- `std::variant<Vector2D, Vector3D>` is used to hold either a 2D or 3D vector without inheritance
- `std::visit` dispatches operations at runtime based on which type is active in the variant
- Dimension detection is automatic — if any Z field is filled, both vectors are treated as 3D
- The window is fixed at 800×600 and cannot be resized or maximized
- Input validation uses `QDoubleValidator` to restrict fields to real numbers only

---

## Known Limitations

- Plot button is not yet implemented
- Scalar multiplication reads the scalar from the V2 Y-component field — this field is repurposed as the scalar input when Scalar Multiplication mode is active
- No error dialog shown when mismatched dimensions are entered — result field simply stays blank

---

## Roadmap

- [ ] Implement vector plotting with Qt Charts or Gnuplot integration
- [ ] Add error dialogs for invalid operations
- [ ] Dedicated scalar input field for multiplication mode
- [ ] Unit vector display alongside results

---

## License

This project is open source. Feel free to use, modify, and distribute.
