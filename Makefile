user: main_user.o solver_equation.o
	g++ main_user.o solver_equation.o -o solver_user
main_user.o: main_user.cpp solver_equation.cpp test_equation.cpp solver_equation.hpp colors.hpp test_equation.hpp
	g++ -c main_user.cpp
solver_equation.o: solver_equation.cpp solver_equation.hpp colors.hpp test_equation.hpp
	g++ -c solver_equation.cpp

test: main_tester.o solver_equation.o test_equation.o
	g++ main_tester.o solver_equation.o test_equation.o -o tester_user
main_tester.o: main_tester.cpp solver_equation.cpp test_equation.cpp solver_equation.hpp colors.hpp test_equation.hpp
	g++ -c main_tester.cpp
test_equation.o: test_equation.cpp solver_equation.hpp colors.hpp test_equation.hpp
	g++ -c test_equation.cpp



















