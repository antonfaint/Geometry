CC=g++ 
CCFLAGS = -std=c++0x 
APPNAME = PointChecker
DEPS=GeometryStructures.h GeometryStructures.cpp PointLocationChecker.h PointLocationChecker.cpp main.cpp

%.o: %.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c $< -o $@ 

all:
	$(CC) $(CCFLAGS) PointLocationChecker.cpp GeometryStructures.cpp main.cpp -o PointChecker

clean_temp:
	rm -f *.o

clean: clean_temp
	rm -f $(APP)
