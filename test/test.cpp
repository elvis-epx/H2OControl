#include <unistd.h>
#include <stdio.h>

#include "Plant.h"

static const double level_sensors[] = LEVEL_SENSORS;
static const uint32_t flow_rates[] = FLOWRATES;

GPIO gpio;
Pump pump;
FlowMeter flowmeter(FLOWMETER_PULSE_RATE, flow_rates);
LevelMeter levelmeter(level_sensors, TANK_CAPACITY);
Display display;
H2OStateMachine sm;

int main()
{
	display.init();
	gpio.init();
	flowmeter.init();
	levelmeter.init();
	pump.init();
	sm.start();

	while (true) {
		gpio.eval();
		flowmeter.eval();
		levelmeter.eval();
		sm.eval();
		display.eval();
		usleep(100000);
	}
}
