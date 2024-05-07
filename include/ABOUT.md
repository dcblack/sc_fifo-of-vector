This directory contains various non-essential but helpful include files that can be shared by all exercises and samples.

```
├── ABOUT.md -------------- this text
├── ABOUT_Objections.md --- describes `objection.h`
├── chronout.hpp ---------- format output from the chron library prior to C++20
├── common.hpp ------------ provides a proper random function (so you don't use C's awful `rand`). Also define UNUSED macro to replace [[maybe_unused]].
├── objection.hpp --------- a mechnism similar to objections in UVM.
├── report.hpp ------------ improves efficiency of REPORT_INFO_VERB and support REPORT_VERB_FORMAT(msg_type,verbosity,fmt,...)
├── sc_format.hpp --------- custom {fmtlib} formatters for SystemC sc_time, sc_int<W>, and sc_uint<W>. Expand as needed.
├── sc_time_literals.hpp -- support for user-defined simulation time literals (e.g., 10.5_us)
└── timer.hpp ------------- simplify measuring CPU time with this Timer class.
```

