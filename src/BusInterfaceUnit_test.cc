#include "BusInterfaceUnit.hh"
#include "Register.hh"
#include "MemoryAddress.hh"
#include <memory>

using namespace std;

static bool ps;

static void print_passed (int i) {
	cout << "Test " << i << ": Passed" << endl;
}

static void print_failed (int i) {
	cout << "Test " << i << ": Failed" << endl;
	ps = false;
}

int main (int argc, char **argv) {
	Memory mem (1048576);
	BusInterfaceUnit biu;
	biu.connect_to (mem);
	int TEST_NUMBER = 0;

	{//Test 1
		++TEST_NUMBER;
		ps = true;
		biu.set_sreg_cs (257);

		if (biu.get_sreg_cs () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 1


	{//Test 2
		++TEST_NUMBER;
		ps = true;
		biu.set_sreg_ds (257);

		if (biu.get_sreg_ds () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 2


	{//Test 3
		++TEST_NUMBER;
		ps = true;
		biu.set_sreg_es (257);

		if (biu.get_sreg_es () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 3


	{//Test 4
		++TEST_NUMBER;
		ps = true;
		biu.set_sreg_ss (257);

		if (biu.get_sreg_ss () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 4


	{//Test 5
		++TEST_NUMBER;
		ps = true;
		biu.set_reg_ip (257);

		if (biu.get_reg_ip () != 257) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 5

	{//Test 6
		++TEST_NUMBER;
		ps = true;
		unsigned short seg = 0;
		unsigned short offset = 0;

		MemoryAddress<int> *tmp_addr;
		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr (tmp_addr);

		int src = 250;
		int dest;
		*addr = src;
		dest = *addr;
		if (src != dest) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 6


	{//Test 7
		++TEST_NUMBER;
		ps = true;
		unsigned short seg = 0xF000;
		unsigned short offset = 0xFFFF;

		MemoryAddress<char> *tmp_addr;
		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<char> > addr (tmp_addr);

		char src = 'J';
		char dest;
		*addr = src;
		dest = *addr;
		if (src != dest) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 7


	{//Test 8
		++TEST_NUMBER;
		ps = true;
		unsigned short seg = 0xF000;
		unsigned short offset = 0xFFFF;

		MemoryAddress<int> *tmp_addr;
		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr (tmp_addr);

		int src = 10;
		int dest;
		*addr = src;
		dest = *addr;

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 8

	{//Test 9
		++TEST_NUMBER;
		ps = true;
		unsigned short seg = 0;
		unsigned short offset = 0;

		MemoryAddress<int> *tmp_addr;
		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr (tmp_addr);

		Register<int> src = 113;
		Register<int> dest;
		*addr = src;
		dest = *addr;

		if (src != dest) {
			print_failed (TEST_NUMBER);
		}

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 9


	{//Test 10
		++TEST_NUMBER;
		ps = true;

		unsigned short seg = 0x0;
		unsigned short offset = 0x0;

		MemoryAddress<int> *tmp_addr;
		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr (tmp_addr);

		*addr = 0x10203040;

		offset = 10;
		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr2 (tmp_addr);

		*addr2 = 0x1234;

		cout << "DUMP:" << endl;
		mem.print_memory_dump (0, 12);

		biu.set_seg_override (0x0002);
		seg = 0x0000;
		offset = 0x0000;

		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr3 (tmp_addr);

		*addr3 = 0x72;

		seg = 0x0001;

		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr4 (tmp_addr);

		*addr4 = 0x56;

		cout << "DUMP:" << endl;
		mem.print_memory_dump (0, 35);

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 10

	{//Test 11
		++TEST_NUMBER;
		ps = true;

		unsigned short seg = 0x0;
		unsigned short offset = 0x0;

		MemoryAddress<int> *tmp_addr;
		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr (tmp_addr);

		*addr = 0x10203040;

		offset = 10;

		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr2 (tmp_addr);

		*addr2 = 0x1234;

		cout << "DUMP:" << endl;
		mem.print_memory_dump (0, 12);

		seg = 0xF000;
		offset = 0xFFFF;

		biu.get_memory_address (tmp_addr, seg, offset);
		auto_ptr<MemoryAddress<int> > addr3 (tmp_addr);

		*addr3 = 0x72;

		cout << "DUMP:" << endl;
		mem.print_memory_dump (1048570, 1048576);

		if (ps) {
			print_passed (TEST_NUMBER);
		}
	}//end Test 11
}

