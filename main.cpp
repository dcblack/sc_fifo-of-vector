#include <systemc>

#include <vector>
#include <string>
#include <cstdint>

// Debug aid
#define SHOW(expr) std::cout << #expr << "=" << expr << '\n'

// Simple wrapper
template<typename T>
struct Vector {
  Vector() = default;
  explicit Vector(size_t l) : data(l) {}
  Vector(size_t l, T val) : data(l,val) {}
  Vector(std::initializer_list<T> l) : data{l} {}
  bool operator==(T const& rhs) const {
    return data == rhs.data;
  }
  [[nodiscard]] size_t size() const { return data.size(); }
  friend std::ostream& operator<<(std::ostream& os, const Vector<T>& rhs )
  {
    os << "{ ";
    for( auto const& v:rhs.data) {
      os << v << ' ';
    }
    os << '}';
    return os;
  }
  std::vector<T> data;
};

SC_MODULE(Simple) {
  explicit SC_CTOR(Simple) {
    SC_THREAD(producer_thread);
    SC_METHOD(consumer_method);
    sensitive << fifo.data_written_event();
  }
  void producer_thread() {
    const auto PERIOD = 10*sc_core::sc_get_time_resolution();
    wait(PERIOD);

    Vector<uint16_t> v1;
    SHOW(v1);
    SHOW(v1.size());

    auto v2 = Vector<uint16_t>{1,2,3};
    SHOW(v2);
    SHOW(v2.size());

    auto v3 = Vector<uint16_t>{4,5};

    SHOW(fifo.num_available());
    wait(PERIOD);
    fifo.write(v1);
    fifo.write(v2);
    wait(PERIOD);
    fifo.write(v3);
    wait(PERIOD);
  }
  void consumer_method() {
    using namespace sc_core;
    auto vin = Vector<uint16_t>{};
    while( fifo.nb_read(vin) ) {
      std::cout << "At " << sc_time_stamp() << ' '
                << "received " << vin
                << '\n';
    }
  }
  sc_core::sc_fifo< Vector<uint16_t> > fifo;
};

[[maybe_unused]]
int sc_main( [[maybe_unused]]int argc
           , [[maybe_unused]]char* argv[] )
{
  Simple SC_NAMED(top);
  sc_core::sc_start();
  return 0;

}
