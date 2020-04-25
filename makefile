build:
	rm -f Venom.exe
	g++ -g -std=c++11 -Wall main.cpp Lexer/Lexer.cpp -o Venom.exe

	
run:
	./Venom.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./Venom.exe