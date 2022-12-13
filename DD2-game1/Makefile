all: game1 game2
CXX = g++
CXXFLAG = -std=c++14 Wall -MMD -g
EXECS = game1.o game1.d game1 game2.o game2.d game2
OBJECTS = bullet.o spaceAlien.o rocketShip.o game.o gameObject.o rectangle.o borderDisplay.o gameDisplay.o border.o bitmap.o character.o statusDisplay.o iceCreamDrop.o keyboard.o controller.o iceCream.o iceCreamDisplay.o fly.o collision.o spaceInvaders.o spaceInvadersDisplay.o
DEPENDS = ${OBJECTS:.o=.d}
game1: game1.o ${OBJECTS}
	${CXX} ${OBJECTS} game1.o -lncurses -o game1
game2: game2.o ${OBJECTS}
	${CXX} ${OBJECTS} game2.o -lncurses -o game2
-include ${DEPENDS}
PHONY:clean
clean:
	rm ${OBJECTS} ${DEPENDS} ${EXECS}
