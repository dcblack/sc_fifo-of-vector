# About sc_fifo-of_vector
This is the top-level of the sc_fifo-of-vector project.

Demonstrates how to wrap `std::vector<T>` (or any container) for use in `sc_signal<T>` and `sc_fifo<T>` use in SystemC.

### Directory organization:

```
sc_fifo-of-vector/
  ├── .git/
  ├── .gitignore
  ├── ABOUT.md <<<<<< This text file
  ├── cmake/
  │   ├── ABOUT.md
  │   ├── sc-project_defaults.cmake
  │   ├── set_target.cmake
  │   └── systemc.cmake
  ├── extern/
  │   ├── ABOUT.md
  │   ├── bin/
  │   │   ├── ABOUT.md
  │   │   ├── build
  │   │   ├── build-fmt
  │   │   └── build-gtest
  │   ├── include/
  │   │   └── ABOUT.md
  │   └── lib/
  │       ├── ABOUT.md
  │       └── cmake
  ├── main.cpp <<<<<<<<<<< Pertinent exmple source code is here
  └── setup.profile <<<<<< Source this file to setup environment
```

### Requirements

- C++17 compliant compiler or better
- SystemC (recommend 3.0)
- CMake version 3.20 or later
- bash version 5.2 or later (possibly works with earlier)

### Building

```bash
git clone "https://github.com/dcblack/sc_fifo-of-vector"
cd sc_fifo-of-vector
source setup.profile
build -test
```


#### End of file
