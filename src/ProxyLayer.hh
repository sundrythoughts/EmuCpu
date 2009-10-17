/**
@file ProxyLayer.hh
@brief Signal translation layer between the Gui and the Cpu.
*/

#ifndef JAF__PROXY_LAYER_HH
#define JAF__PROXY_LAYER_HH

#include "Cpu.hh"
#include "Sim86Window.hh"

#include "FlagRegisterSignalsAndSlots.hh"
#include "MemorySignalsAndSlots.hh"
#include "GeneralRegisterSignalsAndSlots.hh"
#include "SegmentRegisterSignalsAndSlots.hh"

#include <sigc++/sigc++.h>
#include <QObject>

/**
@class ProxyLayer
@brief Signal translation layer between the Gui and the Cpu.
*/
class ProxyLayer : public QObject {
	Q_OBJECT

	GeneralRegisterSignalsAndSlots m_gen_reg_s_s;
	FlagRegisterSignalsAndSlots m_flag_reg_s_s;
	SegmentRegisterSignalsAndSlots m_sreg_s_s;
	MemorySignalsAndSlots m_mem_s_s;

public:
	/** */
	ProxyLayer () {
	}

	/** */
	void connectCpuAndUi (Cpu &cpu, Sim86Window &win);

private:
	void connectCpuSignalsToUiSlots (Cpu &cpu, Sim86Window &win);
	void connectUiSignalsToCpuSlots (Sim86Window &win, Cpu &cpu);
}; //end class ProxyLayer

#endif //JAF__PROXY_LAYER_HH

