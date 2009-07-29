main:
	g++ -Wall -Wextra -o main main.cc Operand.cc InstructionDecoder.cc InstructionDecoder8086.cc Cpu.cc Cpu8086.cc `pkg-config gobject-2.0 --cflags --libs`

Value_test: Value.o Value_test.o
	g++ -Wall -Wextra -o Value_test Value.o Value_test.o

Value_test.o: Value_test.cc
	g++ -Wall -Wextra -c Value_test.cc

Value.o: Value.cc Value.hh
	g++ -Wall -Wextra -c Value.cc

Value_test_clean:
	rm *.o Value_test

clean:
	rm main

