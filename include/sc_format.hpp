#pragma once

// Formatters for sc_string, sc_int<W>, sc_uint<W>

#include <systemc>
#include <string>
#include <fmt/format.h>

template <> // Custom formatter for sc_core::sc_time
struct fmt::formatter<sc_core::sc_time> : fmt::formatter<std::string> {
  char presentation = 't'; // 't'=>normal
  constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    auto it = ctx.begin(), end=ctx.end();
    if( it != end && (*it == 't')) presentation = *it++;
    if( it != end && *it != '}') throw format_error("invalid format");
    return it;
  }
  auto format(const sc_core::sc_time& time, format_context& ctx) const -> decltype(ctx.out()) {
    if( presentation == 't' ) {
      return format_to( ctx.out(), "{}", time.to_string() );
    } else {
      return format_to( ctx.out(), "Formatting error to sc_time" );
    }
  }
};

template <int W> // Custom formatter for sc_dt::sc_int<W>
struct fmt::formatter<sc_dt::sc_int<W>> : fmt::formatter<std::string> {
  char presentation = 'd';
  constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    auto it = ctx.begin(), end=ctx.end();
    if( it != end && (*it == 'd')) presentation = *it++;
    if( it != end && *it != '}') throw format_error("invalid format");
    return it;
  }
  auto format(const sc_dt::sc_int<W>& data, format_context& ctx) const -> decltype(ctx.out()) {
    if( presentation == 'd' ) {
      return format_to( ctx.out(), "{}", data.to_string() );
    } else {
      return format_to( ctx.out(), "Formatting error to sc_int<W>" );
    }
  }
};

template <int W> // Custom formatter for sc_dt::sc_uint<W>
struct fmt::formatter<sc_dt::sc_uint<W>> : fmt::formatter<std::string> {
  char presentation = 'd';
  constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
    auto it = ctx.begin(), end=ctx.end();
    if( it != end && (*it == 'd')) presentation = *it++;
    if( it != end && *it != '}') throw format_error("invalid format");
    return it;
  }
  auto format(const sc_dt::sc_uint<W>& data, format_context& ctx) const -> decltype(ctx.out()) {
    if( presentation == 'd' ) {
      return format_to( ctx.out(), "{}", data.to_string() );
    } else {
      return format_to( ctx.out(), "Formatting error to sc_int<W>" );
    }
  }
};

// TAGS: Doulos, Systemc, format, SOURCE
// ----------------------------------------------------------------------------
//
// This file is licensed under Apache-2.0, and
// Copyright 2023 Doulos Inc. <mailto:info@doulos.com>
// See accompanying LICENSE or visit <https://www.apache.org/licenses/LICENSE-2.0.txt> for more details.
