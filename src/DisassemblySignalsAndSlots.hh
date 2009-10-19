/**
@file DisassemblySignalsAndSlots.hh
@brief Disassembly signal translation layer between Sigc++ and Qt.
*/

#ifndef JAF__DISASSEMBLY_SIGNALS_AND_SLOTS_HH
#define JAF__DISASSEMBLY_SIGNALS_AND_SLOTS_HH

#include <string>
#include <QtCore>

/**
@class DisassemblySignalsAndSlots
@brief Disassembly signal translation layer between Sigc++ and Qt.
*/
class DisassemblySignalsAndSlots : public QObject {
	Q_OBJECT

public:
	void sigcSlotNextInstruction (const std::string&, const std::string&, const std::string&, const std::string&);

public slots:
	/** */
	void enableDisable (bool b);

signals:
	void nextInstruction (QString seg_off, QString mcode, QString asm_code, QString addr_mode);

}; //end class DisassemblySignalsAndSlots

#endif //JAF__DISASSEMBLY_SIGNALS_AND_SLOTS_HH

