clean:
	rm ./LL

run: stringy.c
	gcc linkedlist.cpp -o LL
	./LL
