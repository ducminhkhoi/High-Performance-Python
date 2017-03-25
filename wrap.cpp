#include <pybind11/pybind11.h>
#include "funcs.hpp"

namespace py = pybind11;

using namespace pybind11::literals;

PYBIND11_PLUGIN(wrap) {
    py::module m("wrap", "pybind11 example plugin");
    m.def("fib", &fib, "Calculate fibonacci",
          "n"_a=5);
    return m.ptr();
}
