from util import *
from room import Room, Edge, Move

class Parser:
	def __init__(self):
		pass

	def parse_input(self):
		ants_count = int(read_line())
		line, rooms = self.parse_rooms()
		edges = self.parse_edges(line)
		moves = self.parse_moves()
		return rooms, edges, moves

	def parse_rooms(self):
		rooms = list()
		room_type = 'none'
		while True:
			line = read_line()
			if '##start' in line:
				room_type = 'start'
			elif '##end' in line:
				room_type = 'end'
			elif '#' in line:
				continue
			elif '-' in line:
				break
			else:
				split = line.strip().split(' ')
				print(split)
				room = Room(split[0], int(split[1]), int(split[2]), room_type)
				rooms.append(room)
				room_type = 'none'
		return line, rooms

	def parse_edges(self, line):
		edges = list()
		while line.strip():
			split = line.strip().split('-')
			print(split)
			edges.append(Edge(split[0], split[1]))
			line = read_line()
		return edges

	def parse_moves(self):
		moves = list()
		line = read_line()
		while line:
			line = line.split(" ")
			for item in line:
				item = item.strip("L").strip().split("-")
				moves.append(Move(item[0], item[1]))
			line = read_line()
		return moves
