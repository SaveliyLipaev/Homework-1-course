Number_4: ListFor6.4.o Source.o test.o
	g++ -o Number_4 ListFor6.4.o Source.o test.o

ListFor6.4.o: ListFor6.4.cpp ListFor6.4.h
	g++ -c ListFor6.4.cpp

test.o: test.cpp ListFor6.4.h test.h
	g++ -c test.cpp

Source.o: Source.cpp ListFor6.4.h test.h
	g++ -c Source.cpp

clean:
	rm -rf *.o Number_4