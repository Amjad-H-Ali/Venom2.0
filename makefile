build:
    rm -f venom.exe
    g++ -g -std=c++11 -Wall Lexer.cpp -o venom.exe

run:
    ./venom.exe

valgrind:
    valgrind --tool=memcheck --leak-check=yes ./venom.exe