from util import *
from room import Room
from room import Edge

class Parser:
	def __init__(self):
		pass

	def parse_input(self):
		ants_count = int(read_line())
		line, rooms = self.parse_rooms()
		ants = self.parse_ants(line)
		return rooms, ants

	def parse_rooms(self):
		rooms = list()
		while True:
			room_type = 'none'
			line = read_line()
			if '#' in line:
				continue
			elif '##start' in line:
				room_type = 'start'
			elif '##end' in line:
				room_type = 'end'
			elif '-' in line:
				break
			else:
				split = line.split(' ')
				room = Room(split[0], int(split[1]), int(split[2]), room_type)
				rooms.append(room)
		return line, rooms
	
	def parse_ants(self, line):
		edges = list()
		while line is not '':
			split = line.split('-')
			edges.append(Edge(split[0], split[1]))
			line = read_line()
		return edges