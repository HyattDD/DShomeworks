main : main.o MyLinkList.o
	g++ *.o -o $@
%.o : %.c
	g++ -c $< -o $@

clean:
	rm -f *.o main