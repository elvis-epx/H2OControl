#!/bin/bash

set -e
rm -f *.sim

function sensors () {
	./sensors $*
}

function cond () {
	./cond $1 $2 "$3"
}

function flow () {
	rounds=$2
	while [ "$rounds" -gt 0 ]; do
		echo $1 > pulses.sim
		sleep 1
		rounds=$(($rounds - 1))
	done
}

function advance () {
	echo $1 > timeadvance.sim
	sleep 1
}

function runme () {
	if which valgrind >/dev/null; then
		./val &
	else
		./test &
	fi
	export err=0
	export PID=$!
	sleep 10
}

function quit () {
	err=$?
	echo > quit.sim
	if ! wait $PID; then
		echo "test.cpp exited with error"
		exit 1
	fi
	exit $err
}

trap quit EXIT
