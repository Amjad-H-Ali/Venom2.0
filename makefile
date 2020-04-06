build:
	rm -f program.exe
	g++ -g -std=c++11 -Wall Lexer.cpp -o Venom.exe

	
run:
	./Venom.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./Venom.exe
