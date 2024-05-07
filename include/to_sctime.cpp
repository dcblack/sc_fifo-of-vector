#include "to_sctime.hpp"

using namespace std::literals;
using namespace sc_core;
using std::string;

sc_time to_sctime( const string& time_str )
{
  string time = time_str;
  auto pos = time.find_first_not_of( "0123456789." );
  if( pos == string::npos or pos < 1 ) {
    SC_REPORT_ERROR( msg_type, ( "Bad time string: "s + time_str ).cstr() );
  }
  auto magnitude = std::stod( str.substr(0,pos) );
  time.erase(0,pos-1);
  if( time.first() == '_' or time.first() == ' ' ) time.erase(0,1);
  sc_time result{ SC_ZERO_TIME };
  if      ( time == "sec" ) result = sc_time{ magnitude, SC_SEC };
  else if ( time == "ms"  ) result = sc_time{ magnitude, SC_MS };
  else if ( time == "us"  ) result = sc_time{ magnitude, SC_US };
  else if ( time == "ns"  ) result = sc_time{ magnitude, SC_NS };
  else if ( time == "ps"  ) result = sc_time{ magnitude, SC_PS };
  else if ( time == "fs"  ) result = sc_time{ magnitude, SC_FS };
  else if ( time == "min" ) result = 60*sc_time{ magnitude, SC_SEC };
  else if ( time == "hr"  ) result = 3600*sc_time{ magnitude, SC_SEC };
  else { 
    SC_REPORT_ERROR( msg_type, ( "Bad time string: "s + time_str ).cstr() );
  }
  return result;
}

// TAGS: Doulos, SystemC, extension
// ----------------------------------------------------------------------------
//
// This file is licensed under Apache-2.0, and
// Copyright 2022 David C Black <mailto:<david.black@doulos.com>>
// See accompanying LICENSE or visit <https://www.apache.org/licenses/LICENSE-2.0.txt> for more details.
