#ifndef __PUMP_H
#define __PUMP_H

#include "Timestamp.h"

class Pump
{
public:
	Pump();
	void on();
	void off();
	bool is_running() const;
	Timestamp running_time() const;

	bool is_on;
	Timestamp since;
};

#endif
