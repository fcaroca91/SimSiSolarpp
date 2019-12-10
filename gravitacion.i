%module gravitacion

%include "std_string.i"
%include "std_vector.i"
using std::string;
using std::vector;

%{
  #define SWIG_FILE_WITH_INIT
  #include "cuerpo.h"
  #include "calculos.h"
  #include "sim.h"
%}

%include "cuerpo.h"
%include "calculos.h"
%include "sim.h"

%template (vectorc) std::vector<Cuerpo>;
