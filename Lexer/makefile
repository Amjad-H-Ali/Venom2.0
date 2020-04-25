build:
	rm -f Lexer.exe
	g++ -g -std=c++11 -Wall Lexer.cpp -o Lexer.exe

	
run:
	./Lexer.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./Lexer.exe
