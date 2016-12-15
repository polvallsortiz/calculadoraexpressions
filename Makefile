OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -ansi -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: program.o Resultat.o Dades.o Expressio.o Operacio.o
	g++ -o program.exe program.o Resultat.o Dades.o Expressio.o Operacio.o
	
Operacio.o: Operacio.cc Operacio.hh
	g++ -c Operacio.cc $(OPCIONS)
	
	
Expressio.o: Expressio.cc Expressio.hh
	g++ -c Expressio.cc $(OPCIONS)

Resultat.o:  Resultat.cc Resultat.hh 
	g++ -c Resultat.cc $(OPCIONS)

Dades.o:  Dades.cc Dades.hh
	g++ -c Dades.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

program.tar: *.cc *.hh Makefile
	tar -cvf program.tar *hh *.cc Makefile
clean:
	rm *.o
	rm *.exe