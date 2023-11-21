all:
	gcc main.c ./src/*.c -I include -o termo.exe

run:
	./termo.exe

clean:
	rm termo.exe