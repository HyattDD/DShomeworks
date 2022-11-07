CPP_FLAGS = -Werror '-std=c++11'

BinTreeNode : BinTreeNode.o
	g++ ${CPP_FLAGS} *.o -o $@ 
%.o : %.cpp
	g++ ${CPP_FLAGS} -c $< -o $@ 

clean:
	rm -f *.o main *.out BinTreeNode