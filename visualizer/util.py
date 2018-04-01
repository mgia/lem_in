import sys

debug = True
file = open('logs.txt', 'w+')

def log(s):
	if debug:
		file.write(s)
		file.flush()

def read_line():
	line = sys.stdin.readline()
	log("read: " + line)
	return line