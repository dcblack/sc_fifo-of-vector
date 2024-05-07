#pragma once

#if __cplusplus < 201103L
#error This code requires at least C++11
#endif

// These are some miscellaneous bits used various places and common to
// several areas of the exercises.

// Use the following to eliminate intentionally unused arguments and suppress warnings for C++17 and above
#if __cplusplus >= 201703L
#define UNUSED [[maybe_unused]]
#else
#define UNUSED
#endif

// Generate 2**N bits evenly distributed; where N = 1..64
// Seed is only good on first call to each random_bits<N>.
// This algorithm is fast and consistent across platforms.
// Use this to replace std::rand, which is considered bad 
// practice to use. See the following for more information:
// - [Rand Considered Harmful](https://www.google.com/search?q=rand+considered+harmful&oq=rand+considered+harmful&aqs=chrome..69i57j69i59.5172j0j4&sourceid=chrome&ie=UTF-8#kpvalbx=_UFhiYoWoBv6sqtsPwc6gsA016)
// - [PCG, Better Random Number Generator](https://www.pcg-random.org/)
#include <random>

template<int N>
auto random_bits(uint64_t seed=1ull) {
  static_assert( 0 < N && N <= 64 );
  static std::mt19937_64 gen{seed}; // 64-bit Mersenne Twister by Matsumoto and Nishimura, 1998
  auto mask = (~0ull)>>(64-N);
  auto value = gen() & mask;
  return value;
}

