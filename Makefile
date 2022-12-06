CXX = g++
CXXFLAG = -std=c++14 Wall -MMD
EXEC = build
OBJECTS = main.o game.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}
PHONY:clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
