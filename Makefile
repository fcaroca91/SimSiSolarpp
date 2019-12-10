#%include "typemaps.i"
#%include "std_complex.i"
#using std::string;
#using std::vector;
#namespace std { 
#  %template(vector_cuerpo) vector<string>; 
#};
#%template(vector_cuerpo) std::vector<Cuerpo>;
SRCDIR = src
INCDIR = include
OUTDIR = python
TARGET = bin

FLAGS = -std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self

all: app clean

app:
	swig -c++ -python -outdir $(OUTDIR) -I$(INCDIR) gravitacion.i 
	g++ $(FLAGS) -c -fpic $(SRCDIR)/cuerpo.cc $(SRCDIR)/calculos.cc $(SRCDIR)/sim.cc gravitacion_wrap.cxx -I/usr/include/python3.6 -I $(INCDIR)
	g++ -shared cuerpo.o calculos.o sim.o gravitacion_wrap.o -o $(OUTDIR)/_gravitacion.so

main:
	g++ $(FLAGS) $(SRCDIR)/main.cc $(SRCDIR)/cuerpo.cc $(SRCDIR)/calculos.cc $(SRCDIR)/sim.cc -I $(INCDIR) -o $(TARGET)/sistema_solar

clean:
	rm -f __pycache__ *.pyc *.o *.cxx -R
