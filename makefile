all:
	gcc main.c funcoes.c -o termo.exe

run:
	./termo.exe

clean:
	rm termo.exe