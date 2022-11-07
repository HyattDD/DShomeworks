CPP_FLAGS = -std=c++11

main : main.o
	g++ ${CPP_FLAGS} *.o -o $@ 
%.o : %.cpp
	g++ ${CPP_FLAGS} -c $< -o $@ 

clean:
	rm -f *.o main