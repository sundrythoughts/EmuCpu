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

public slots:
	/** */
	void enableDisable (bool b);

signals:
	/** */
	void valueChangedFlags (unsigned short i);

}; //end class FlagRegisterSignalsAndSlots

#endif //JAF__FLAG_REGISTER_SIGNALS_AND_SLOTS_HH

