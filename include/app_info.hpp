#pragma once

// Provides compiler and run-time version information using compiler provided
// defines.  See <https://sourceforge.net/p/predef/wiki/Home/>.

#include <string>

namespace Doulos {

  using namespace std::string_literals;

  // Return a single string with all the information
  inline std::string app_info( const std::string& app_specific = "" );

  // Return C++ compiler version and C++ standard version based on #defines
  inline std::string cpp_version();

  // Return the Operating System and version based on #defines
  inline std::string os_version();

  // Return the target processor architecture based on #defines
  inline std::string arch_version();

  // Return the current date and time
  // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime for more information about date/time format
  inline std::string currentDateTime(const char* dateFormat = "%c" );

  // Return a simple fixed width horizontal line with an option heading embedded
  inline std::string horizontal_separator( const std::string& heading = "", char sep = '-', size_t lineWidth = 80 ) {
    auto result = std::string( 3, sep );
    if ( not heading.empty() ) result += " "s + heading + " "s;
    if ( result.length() < lineWidth ) result += std::string( lineWidth - result.length(), sep );
    return result;
  }
  [[maybe_unused]]
  inline std::string horizontal_separator( char sep, size_t lineWidth = 80 ) { return horizontal_separator( "", sep, lineWidth ); }

  // Return copyright information with with Doulos copyright
  inline std::string copyright( std::string license );

  //----------------------------------------------------------------------------
  std::string app_info( const std::string& app_specific )
  {
    auto result = "\n"s + horizontal_separator( "Version information" ) + "\n"s;
    result += "Current time: "s + currentDateTime() + "\n"s;
    result += "SystemC "s + std::string{ SC_VERSION } + "\n"s;
    result += "Compiled with "s + cpp_version() + " using C++ version "s + std::to_string(__cplusplus) + "\n"s;
    result += "Running under "s + os_version() + " on "s  + arch_version() + " architecture\n"s;
    if ( not app_specific.empty() ) {
      result += app_specific;
      if( result.back() != '\n' ) result += '\n';
    }
    result += horizontal_separator();
    return result;
  }

  //----------------------------------------------------------------------------
  std::string cpp_version()
  {
    using std::to_string;
    std::string result;
  #if defined(__clang__)
    result = "Clang/LLVM version "s + to_string(__clang_major__) + "."s + to_string(__clang_minor__) + "."s + to_string(__clang_patchlevel__);

  #elif defined(__ICC) || defined(__INTEL_COMPILER)
    result = "Intel ICC/ICPC version "s + to_string(__ICC);

  #elif defined(__GNUC__) || defined(__GNUG__)
    result = "GNU GCC/G++ version "s + to_string(__GNUC__) + "."s + to_string(__GNUC_MINOR__) + "."s + to_string(__GNUC_PATCHLEVEL__);

  #elif defined(__HP_cc) || defined(__HP_aCC)
    result = "Hewlett-Packard C/aC++ version "s + to_string(__HP_cc);

  #elif defined(__IBMC__) || defined(__IBMCPP__)
    result = "IBM XL C/C++ version "s + to_string(__IBMCPP__);

  #elif defined(_MSC_VER)
    result = "Microsoft Visual Studio version "s + to_string(_MSC_FULL_VER);

  #elif defined(__PGI)
    result = "Portland Group PGCC/PGCPP version "s + to_string(__PGIC__) + "."s + to_string(__PGIC_MINOR__) + "." + to_string(__PGIC_PATCHLEVEL__);

  #elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
    result = "Oracle Solaris Studio version "s + hex + to_string(__SUNPRO_CC);

  #else
    result = "unknown";
  #endif
    return result;
  }

  //----------------------------------------------------------------------------
  std::string os_version()
  {
  #if defined(__AIX)
    return "AIX";

  #elif defined(__ANDROID__)
    return "ANDROID API(" __ANDROID_API__ ")";

  #elif defined(__bsdi__)
    return "BSD/OS";

  #elif defined(__CYGWIN__)
    return "Cygwin environment";

  #elif defined(__FreeBSD__)
    return "FreeBSD version" __FreeBSD_version;

  #elif defined(__gnu_hurd__)
    return "GNU/Hurd";

  #elif defined(__gnu_linux__)
    return "GNU/Linux";

  #elif defined(_hpux)
    return "HP-UX";

  #elif defined(__OS400__)
    return "IBM OS/400";

  #elif defined(__linux__)
    return "Linux";

  #elif defined(__APPLE__) && defined(__MACH__)
    return "MacOS";

  #elif defined(__MSDOS__)
    return "MSDOS";

  #elif defined(__NetBSD__)
    return "NetBSD";

  #elif defined(__OpenBSD__)
    return "OpenBSD";

  #elif defined(__sun)
    return "Solaris";

  #elif defined(__sysv__)
    return "SVR4 Environment";

  #elif defined(__unix__)
    return "UNIX";

  #elif defined(__VXWORKS__)
    return "VxWorks";

  #elif defined(__WIN16)
    return "Windows 16";

  #elif defined(__WIN32)
    return "Windows 32";

  #elif defined(__WIN64)
    return "Windows 64";

  #else
    return "unknown";

  #endif
  }

  //----------------------------------------------------------------------------
  std::string arch_version()
  {
  #if defined(__alpha__)
    return "alpha";

  #elif defined(__thumb__)
    return "T32";

  #elif defined(__arm__)
    return "arm32";

  #elif defined(__arm64__)
    return "arm64";

  #elif defined(__amd64__)
    return "amd64";

  #elif defined(__hppa__)
    return "HPPA";

  #elif defined(__i386__) or defined(__i486__) or defined(__i586__) or defined(__i686__) or defined(_INTEL__)
    return "x86";

  #elif defined(__ia64__) or defined(__itanium__)
    return "ia64";

  #elif defined(__m68k__)
    return "m68k";

  #elif defined(__mips__)
    return "mips";

  #elif defined(__powerpc__)
    return "powerpc";

  #elif defined(__sparc__)
    return "sparc";

  #else
    return "unknown";

  #endif
  }

  //----------------------------------------------------------------------------
  #include <time.h>
  std::string currentDateTime(const char* dateFormat) {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), dateFormat, &tstruct);
    return buf;
  }

  //----------------------------------------------------------------------------
  std::string copyright( const std::string& license = "" )
  {
    auto result = "LICENSE:\n"s;
    if( not license.empty() ) result += license + "\n"s;
    result += R"(Portions copyright 2023 Doulos Ltd and licensed under Apache 2.0. See LICENSE for details.)"s;
    return result;
  }

}

// TAGS: Doulos, SystemC, sc_main, SOURCE
// ----------------------------------------------------------------------------
//
// This file is licensed under Apache-2.0, and
// Copyright 2023 David C Black <mailto:<david.black@doulos.com>>
// See accompanying LICENSE or visit <https://www.apache.org/licenses/LICENSE-2.0.txt> for more details.
