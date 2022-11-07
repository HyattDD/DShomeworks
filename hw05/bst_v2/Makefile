CPP_FLAGS = -Werror '-std=c++11'

BST : BST.o
	g++ ${CPP_FLAGS} *.o -o $@
%.o : %.cpp
	g++ ${CPP_FLAGS} -c $< -o $@

clean:
	rm -f *.o BST