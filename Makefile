CXXFLAGS=-g -std=c++11
OBJS=main.o triangle.o

opengl: $(OBJS)
	g++ $(OBJS) -o opengl -g -lGL -lGLU -lglut

main.o: main.h triangle.h

triangle.o: triangle.h

.PHONY: clean

clean:
	-rm -rf opengl $(OBJS)