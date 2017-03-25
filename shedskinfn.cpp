#include "builtin.hpp"
#include "shedskinfn.hpp"

namespace __shedskinfn__ {

str *const_0;


__ss_int maxiter;
list<__ss_int> *output;
list<complex> *cs, *zs;
str *__name__;




list<__ss_int> *calculate_z(__ss_int maxiter, list<complex> *zs, list<complex> *cs) {
    /**
    Calculate output list using Julia update rule
    */
    __ss_bool __2, __3;
    __ss_int __0, __1, i, n;
    complex c, z;
    list<__ss_int> *output;

    output = ((new list<__ss_int>(1,0)))->__mul__(len(zs));

    FAST_FOR(i,0,len(zs),1,0,1)
        n = 0;
        z = zs->__getfast__(i);
        c = cs->__getfast__(i);

        while (((n<maxiter) and (((z.real*z.real)+(z.imag*z.imag))<((double)(4))))) {
            z = ((z*z)+c);
            n = (n+1);
        }
        output->__setitem__(i, n);
    END_FOR

    return output;
}

void __init() {
    const_0 = new str("__main__");

    __name__ = new str("shedskinfn");

    if (__eq(__shedskinfn__::__name__, const_0)) {
        maxiter = 1;
        zs = (new list<complex>(1,mcomplex(0, 0)));
        cs = (new list<complex>(1,mcomplex((-0.62772), (-0.42193))));
        output = calculate_z(__shedskinfn__::maxiter, __shedskinfn__::zs, __shedskinfn__::cs);
    }
}

} // module namespace

/* extension module glue */

extern "C" {
#include <Python.h>
#include "shedskinfn.hpp"
#include <structmember.h>
#include "shedskinfn.hpp"

PyObject *__ss_mod_shedskinfn;

namespace __shedskinfn__ { /* XXX */
PyObject *Global_shedskinfn_calculate_z(PyObject *self, PyObject *args, PyObject *kwargs) {
    try {
        __ss_int arg_0 = __ss_arg<__ss_int >("maxiter", 0, 0, 0, args, kwargs);
        list<complex> *arg_1 = __ss_arg<list<complex> *>("zs", 1, 0, 0, args, kwargs);
        list<complex> *arg_2 = __ss_arg<list<complex> *>("cs", 2, 0, 0, args, kwargs);

        return __to_py(__shedskinfn__::calculate_z(arg_0, arg_1, arg_2));

    } catch (Exception *e) {
        PyErr_SetString(__to_py(e), ((e->message)?(e->message->c_str()):""));
        return 0;
    }
}

static PyNumberMethods Global_shedskinfn_as_number = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

static PyMethodDef Global_shedskinfnMethods[] = {
    {(char *)"__newobj__", (PyCFunction)__ss__newobj__, METH_VARARGS | METH_KEYWORDS, (char *)""},
    {(char *)"calculate_z", (PyCFunction)Global_shedskinfn_calculate_z, METH_VARARGS | METH_KEYWORDS, (char *)""},
    {NULL}
};

PyMODINIT_FUNC initshedskinfn(void) {
    __shedskin__::__init();
    __shedskinfn__::__init();

    __ss_mod_shedskinfn = Py_InitModule((char *)"shedskinfn", Global_shedskinfnMethods);
    if(!__ss_mod_shedskinfn)
        return;


    addshedskinfn();

}

PyMODINIT_FUNC addshedskinfn(void) {
    PyModule_AddObject(__ss_mod_shedskinfn, (char *)"output", __to_py(__shedskinfn__::output));
    PyModule_AddObject(__ss_mod_shedskinfn, (char *)"maxiter", __to_py(__shedskinfn__::maxiter));
    PyModule_AddObject(__ss_mod_shedskinfn, (char *)"cs", __to_py(__shedskinfn__::cs));
    PyModule_AddObject(__ss_mod_shedskinfn, (char *)"zs", __to_py(__shedskinfn__::zs));

}

} // namespace __shedskinfn__

} // extern "C"
int main(int, char **) {
    __shedskin__::__init();
    __shedskin__::__start(__shedskinfn__::__init);
}
