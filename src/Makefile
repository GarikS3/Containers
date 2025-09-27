CC=gcc 
CFLAGS=-Wextra -Wall -Werror -std=c++20
FILES_LIB = 
LIB_A = s21_containers.a
RUN_TEST = test
OPEN = open

all: clean test

$(LIB_A):  
	$(CC) $(CFLAGS) -c $(FILES_LIB) -lstdc++
	ar rcs $(LIB_A) *.o
	ranlib $(LIB_A)	
	rm *.o	

build:
	$(CC) $(CFLAGS) $(FILES_LIB) ./tests/*.cpp -lgtest -lgmock -lstdc++ -lm -pthread -o $(RUN_TEST)

test: build
	./$(RUN_TEST)

gcov_report:  
	$(CC) $(CFLAGS) ./tests/*.cpp --coverage $(FILES_LIB) -lgtest -lstdc++ -lm -lsubunit -o gcov_report_test
	./gcov_report_test
	lcov -t "Report" -d . -c --output-file coverage.info --ignore-errors mismatch
	lcov -r coverage.info '/usr/include/*' '/tests/*' -o filtered.info
	genhtml filtered.info --output-directory report/
	$(OPEN) ./report/index.html

valgrind: build
	valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all -s ./$(RUN_TEST)

clang_check:
	clang-format -n ./*/*.tpp ./*/*.h ./*/*.cpp *.h
	clang-format -n tests/*.cpp tests/*.h

clang_format:
	clang-format -i ./*/*.tpp ./*/*.h ./*/*.cpp *.h
	clang-format -i tests/*.cpp tests/*.h

clean: 
	rm -f *.out *.o *.a *.gch *.gcno *.gcda $(RUN_TEST) gcov_test *.info
	rm -rf ./report gcov_report_test

rebuild: clean all