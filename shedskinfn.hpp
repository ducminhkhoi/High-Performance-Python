#ifndef __SHEDSKINFN_HPP
#define __SHEDSKINFN_HPP

using namespace __shedskin__;
namespace __shedskinfn__ {

extern str *const_0;



extern __ss_int maxiter;
extern list<complex> *cs, *zs;
extern str *__name__;
extern list<__ss_int> *output;


list<__ss_int> *calculate_z(__ss_int maxiter, list<complex> *zs, list<complex> *cs);

extern "C" {
PyMODINIT_FUNC initshedskinfn(void);

PyMODINIT_FUNC addshedskinfn(void);

}
} // module namespace
namespace __shedskin__ { /* XXX */

}
#endif
