#Joseph Elsisi jre3wjh
#108
#october 17
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -std=c++11
DEBUG= -Wall -g
OFILES = AVLTree.o AVLPathTest.o AVLNode.o 

.SUFFIXES: .o .cpp

a.out:$(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o a.out
	@echo "Did it work? ???"
clean:
	-rm -f *.o *~ a.out
AVLNode.o: AVLNode.cpp AVLNode.h
AVLTree.o: AVLTree.cpp AVLTree.h AVLNode.cpp AVLNode.h 
AVLPathTest.o: AVLPathTest.cpp AVLTree.cpp AVLTree.h AVLNode.cpp AVLNode.h