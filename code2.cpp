<%
cfg['compiler_args'] = ['-std=c++11', '-stdlib=libc++', '-mmacosx-version-min=10.7']
setup_pybind11(cfg)
%>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/complex.h>

namespace py = pybind11;

int* calculate_z(int maxiter, std::complex<float> *zs, std::complex<float> *cs) {
	int len_zs = (sizeof(zs)/sizeof(zs[0]));
	int n;
	std::complex<float> z,c;

	int *output = new int[len_zs];

    for (int i=0;i<len_zs;i++){
    	n = 0;
    	z = zs[i];
    	c = cs[i];
    	while (n < maxiter && z.real() * z.real() + z.imag() * z.imag() < 4){
    		z = z * z + c;
    		n += 1;
    	}

    	output[i] = n;
    }

    return output;
}

PYBIND11_PLUGIN(code2) {
    pybind11::module m("code", "auto-compiled c++ extension");
    m.def("calculate_z", calculate_z);
    return m.ptr();
}