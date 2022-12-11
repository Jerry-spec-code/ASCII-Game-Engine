all: exec1 exec2
CXX = g++
CXXFLAG = -std=c++14 Wall -MMD -g
EXECS = exec1.o exec1.d exec1 exec2.o exec2.d exec2
OBJECTS = game.o gameObject.o rectangle.o borderDisplay.o gameDisplay.o border.o bitmap.o character.o statusDisplay.o iceCreamDrop.o
DEPENDS = ${OBJECTS:.o=.d}
exec1: exec1.o ${OBJECTS}
	${CXX} ${OBJECTS} exec1.o -lncurses -o exec1
exec2: exec2.o ${OBJECTS}
	${CXX} ${OBJECTS} exec2.o -lncurses -o exec2
-include ${DEPENDS}
PHONY:clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXECS}
