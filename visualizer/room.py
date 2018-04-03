class Room:
	def __init__(self, name, x, y, _type):
		self.name = name
		self.x = x
		self.y = y
		self.type = _type

class Edge:
	def __init__(self, r1, r2):
		self.r1 = r1
		self.r2 = r2

class Move:
	def __init__(self, ant, room):
		self.ant = ant
		self.room = room
