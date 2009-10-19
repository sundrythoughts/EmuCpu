#ifndef JAF__CPU_COMPONENTS_HH
#define JAF__CPU_COMPONENTS_HH

#include "ExecutionUnit.hh"
#include "ArithmeticLogicUnit.hh"
#include "BusInterfaceUnit.hh"
#include "Memory.hh"
#include "InstructionDecoder.hh"
#include "Loader.hh"

class InstructionDecoder;
class ExecutionUnit;
class BusInterfaceUnit;
class ArithmeticLogicUnit;
class BusInterfaceUnit;
class Memory;
class Loader;

class CpuComponentsPrivate;

class CpuComponents {
	CpuComponentsPrivate *p;

public:
	/** */
	CpuComponents ();

	/** */
	~CpuComponents ();

	/** */
	ExecutionUnit& getExecutionUnit ();

	/** */
	BusInterfaceUnit& getBusInterfaceUnit ();

	/** */
	Memory& getMemory ();

	/** */
	ArithmeticLogicUnit& getArithmeticLogicUnit ();

	/** */
	InstructionDecoder& getInstructionDecoder ();

	/** */
	Loader& getLoader ();

	/** */
	bool getHalt ();

	/** */
	void setHalt (bool b);

}; //end class CpuComponents

#endif //JAF__CPU_COMPONENTS_HH

