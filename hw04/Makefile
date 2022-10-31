main : main.o BinaryTree.o BinaryTreeNode.o
	g++ *.o -o $@
%.o : %.c
	g++ -c $< -o $@

clean:
	rm -f *.o main