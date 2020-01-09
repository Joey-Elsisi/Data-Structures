#Joseph Elsisi jre3wjh
#108
#october 20
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -std=c++11 -O2
DEBUG= -Wall -g
OFILES = hashTable.o timer.o wordPuzzle.o

.SUFFIXES: .o .cpp

a.out:$(OFILES)
	$(CXX) $(DEBUG) $(OFILES) 
	@echo "Did it work? ???"
clean:
	-rm -f *.o *~ a.out
timer.o: timer.cpp timer.h
wordPuzzle.o: hashTable.cpp hashTable.h timer.cpp timer.h 
hashTable.o: hashTable.cpp hashTable.h 