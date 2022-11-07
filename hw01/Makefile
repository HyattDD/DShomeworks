main : main.o MyLinkList.o
	g++ *.o -o $@
%.o : %.cpp
	g++ -c $< -o $@

clean:
	rm -f *.o main