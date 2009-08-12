LINKED_LIBS=`pkg-config glib-2.0 --cflags --libs`

main:
	g++ -Wall -Wextra -o main main.cc Operand.cc InstructionDecoder.cc InstructionDecoder8086.cc Cpu.cc Cpu8086.cc

Value_test: Value.o Value_test.o
	g++ -Wall -Wextra -o Value_test Value.o Value_test.o $(LINKED_LIBS)

Value_test.o: Value_test.cc Value.hh
	g++ -Wall -Wextra -c Value_test.cc $(LINKED_LIBS)

Value.o: Value.cc Value.hh
	g++ -Wall -Wextra -c Value.cc $(LINKED_LIBS)

Value_test_clean:
	rm *.o Value_test

Instructions_test: Instructions.o Instructions_test.o
	g++ -Wall -Wextra -o Instructions_test Instructions.o Instructions_test.o $(LINKED_LIBS)

Instructions_test.o: Instructions_test.cc Instructions.hh
	g++ -Wall -Wextra -c Instructions_test.cc $(LINKED_LIBS)

Instructions.o: Instructions.cc Instructions.hh Value.o
	g++ -Wall -Wextra -c Instructions.cc $(LINKED_LIBS)

Instructions_test_clean:
	rm *.o Instructions_test

Cpu.o: Cpu.cc Cpu.hh
	g++ -Wall -Wextra -c Cpu.cc

Cpu8086_test: Cpu8086.o Cpu8086_test.o
	g++ -Wall -Wextra -o Cpu8086_test Cpu8086.o Cpu8086_test.o

Cpu8086.o: Cpu8086.cc Cpu8086.hh
	g++ -Wall -Wextra -c Cpu8086.cc

clean:
	rm main

