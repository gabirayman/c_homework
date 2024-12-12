CFLAGS = -Wall -g -fPIC

all: mains maindloop maindrec loops recursive

loops: libclassloops.a

libclassloops.a: advancedClassificationLoop.o basicClassification.o
	ar rcs libclassloops.a advancedClassificationLoop.o basicClassification.o

recursive: libclassrec.a

libclassrec.a: advancedClassificationRecursion.o basicClassification.o
	ar rcs libclassrec.a advancedClassificationRecursion.o basicClassification.o

mains: main.o libclassrec.a
	gcc $(CFLAGS) -o mains main.o libclassrec.a

libclassloops.so: advancedClassificationLoop.o basicClassification.o
	gcc $(CFLAGS) -shared -o libclassloops.so advancedClassificationLoop.o basicClassification.o

libclassrec.so: advancedClassificationRecursion.o basicClassification.o
	gcc $(CFLAGS) -shared -o libclassrec.so advancedClassificationRecursion.o basicClassification.o

maindloop: main.o libclassloops.so
	gcc $(CFLAGS) -o maindloop main.o -L. -lclassloops -Wl,-rpath=.


maindrec: main.o libclassrec.so
	gcc $(CFLAGS) -o maindrec main.o -L. -lclassrec -Wl,-rpath=.


%.o: %.c Numclass.h
	gcc $(CFLAGS) -c $<

clean:
	rm -f *.o *.a *.so mains maindloop maindrec