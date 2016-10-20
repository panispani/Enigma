CXX=g++
CXXFLAGS=-std=c++11

SOURCE=Main.cpp \
       Enigma.cpp \
	   Rotor_Box.cpp \
       IOmodule.cpp \
       Rotor.cpp \
       Plugboard.cpp \
       Reflector.cpp \

OBJS=$(SOURCE:.cpp=.o)

enigma: $(OBJS)
	g++ -o enigma $^

depend: .depend

.depend: $(SOURCE)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ -MF  ./.depend;

include .depend

clean:
	$(RM) enigma *.o ./.depend

.PHONY: clean
