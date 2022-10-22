CPP_FLAGS = -std=c++11

main : main.o Stack.o Queue.o
	g++ ${CPP_FLAGS} *.o -o $@ 
%.o : %.c
	g++ ${CPP_FLAGS} -c $< -o $@ 

clean:
	rm -f *.o main