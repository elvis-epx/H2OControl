#include "Pump.h"
#include "Plant.h"

Pump::Pump()
{
	since = now();
	is_on = false;
}

void Pump::on()
{
	if (! is_on) {
		display.debug("pump on");
		since = now();
		is_on = true;
		flowmeter.reset();
	}
}

void Pump::off()
{
	if (is_on) {
		display.debug("pump off");
		since = now();
		is_on = false;
	}
}

bool Pump::is_running() const
{
	return is_on;
}

Timestamp Pump::running_time() const
{
	return now() - since;
}

Timestamp Pump::flow_delay()
{
	double pipe_area_mm2 = (PIPE_DIAMETER * PIPE_DIAMETER / 4.0) * 3.142;
	double pipe_area_cm2 = pipe_area_mm2 / 100;
	double pipe_length_cm = PIPE_LENGTH * 100.0;
	double pipe_volume_mL = pipe_area_cm2 * pipe_length_cm;
	double pipe_volume_L = pipe_volume_mL / 1000.0;

	return (pipe_volume_L / ESTIMATED_PUMP_FLOWRATE) * MINUTES;
}
