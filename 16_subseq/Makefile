
CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99
test: maxSeq.o test_subseq.o
	gcc -o test maxSeq.o test_subseq.o
maxSeq.o: maxSeq.c
	gcc $(CFLAGS) -c maxSeq.c
test_subseq.o: test_subseq.c
	gcc $(CFLAGS) -c test_subseq.c

.PHONY: clean
clean:
	rm -f test *.o *.c~ *.h~