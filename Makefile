CXX = g++
CXXFLAG = -std=c++14 Wall -MMD
EXEC = exec
OBJECTS = main.o game.o gameobject.o rectangle.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -lncurses -o ${EXEC}
-include ${DEPENDS}
PHONY:clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
