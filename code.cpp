<%
cfg['compiler_args'] = ['-std=c++11', '-stdlib=libc++', '-mmacosx-version-min=10.7']
setup_pybind11(cfg)
%>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

double fib(int n) {
    return  n < 2?n:fib(n-1)+fib(n-2);
}

PYBIND11_PLUGIN(code) {
    pybind11::module m("code", "auto-compiled c++ extension");
    m.def("fib", fib);
    return m.ptr();
}