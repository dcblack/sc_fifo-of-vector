This is the top-level of the fifo_of_vect project.

Demonstrates how to wrap `std::vector<T>` (or any container) for use in `sc_signal<T>` and `sc_fifo<T>` use in SystemC.

Directory organization:

```
  fifo_of_vect/
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

## Building

```bash
cd fifo_of_vect
source setup.profile
build -test
```


#### End of file
