#pragma once

#include <systemc>
#include <string>

// Convert strings with time specifications of the format matching the regular
// expression `[0-9]*[.]?[0-9]+[ _](sec|ms|us|ns|ps|fs|min|hr)` to `sc_time`
sc_core::sc_time to_sctime( const std::string& time_str );

// TAGS: Doulos, SystemC, extension
// ----------------------------------------------------------------------------
//
// This file is licensed under Apache-2.0, and
// Copyright 2022 David C Black <mailto:<david.black@doulos.com>>
// See accompanying LICENSE or visit <https://www.apache.org/licenses/LICENSE-2.0.txt> for more details.
