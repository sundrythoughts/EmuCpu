/**
@file FlagRegisterSignalsAndSlots.hh
@brief Flag register signal translation layer between Sigc++ and Qt.
*/

#ifndef JAF__FLAG_REGISTER_SIGNALS_AND_SLOTS_HH
#define JAF__FLAG_REGISTER_SIGNALS_AND_SLOTS_HH

#include <QObject>

/**
@class FlagRegisterSignalsAndSlots
@brief Flag register signal translation layer between Sigc++ and Qt.
*/
class FlagRegisterSignalsAndSlots : public QObject {
	Q_OBJECT

public:
	/** */
	void sigcSlotValueChangedFlags (unsigned short i);

	//FIXME - I don't think these are needed
	void sigcSlotValueChangedFlagAF (bool b);
	void sigcSlotValueChangedFlagCF (bool b);
	void sigcSlotValueChangedFlagDF (bool b);
	void sigcSlotValueChangedFlagIF (bool b);
	void sigcSlotValueChangedFlagOF (bool b);
	void sigcSlotValueChangedFlagPF (bool b);
	void sigcSlotValueChangedFlagSF (bool b);
	void sigcSlotValueChangedFlagTF (bool b);
	void sigcSlotValueChangedFlagZF (bool b);

public slots:
	/** */
	void enableDisable (bool b);

signals:
	/** */
	void valueChangedFlags (unsigned short i);

	//FIXME - I don't think these are needed
	void valueChangedFlagAF (bool b);
	void valueChangedFlagCF (bool b);
	void valueChangedFlagDF (bool b);
	void valueChangedFlagIF (bool b);
	void valueChangedFlagOF (bool b);
	void valueChangedFlagPF (bool b);
	void valueChangedFlagSF (bool b);
	void valueChangedFlagTF (bool b);
	void valueChangedFlagZF (bool b);

}; //end class FlagRegisterSignalsAndSlots

#endif //JAF__FLAG_REGISTER_SIGNALS_AND_SLOTS_HH

