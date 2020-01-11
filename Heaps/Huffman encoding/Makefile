#Joseph ELsisi jre3wjh
#Lab 108
#Nov 30
OFILES1 = huffmanenc.cpp heap.cpp huffNode.cpp
OFILES2 = huffmandec.cpp heap.cpp huffNode.cpp
CXXFLAGS	= -Wall -g -std=c++11
.SUFFIXES: .o .cpp
.SUFFIXES: .o .s
main: main2 main3

main2:	$(OFILES1)
	$(CXX) $(CXXFLAGS) $(OFILES1) -o encoder
main3:	$(OFILES2)
	$(CXX) $(CXXFLAGS) $(OFILES2) -o decoder
clean:
		/bin/rm -f *.o *~