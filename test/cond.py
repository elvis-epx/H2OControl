#!/usr/bin/env python3

import sys, mylib

conds = {}
conds["eq"] = lambda a, b: a == b
conds["ne"] = lambda a, b: a != b
conds["gt"] = lambda a, b: a > b
conds["ge"] = lambda a, b: a >= b
conds["lt"] = lambda a, b: a < b
conds["le"] = lambda a, b: a <= b

arg = sys.argv[1]
cond = sys.argv[2]
val = sys.argv[3]
state = mylib.read_state()
if arg not in state:
	raise Exception("arg not in state")
if cond not in conds:
	raise Exception("invalid condition")
if arg in ("state", "level_err"):
	if cond not in ("eq", "ne"):
		raise Exception("Invalid condition for string")
else:
	val = float(val)

if conds[cond](state[arg], val):
	sys.exit(0)
sys.exit(1)
