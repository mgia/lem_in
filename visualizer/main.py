import sys
from parser import Parser
from tkinter import *

debug = True
box_w = 250
box_h = 250

def close(event):
	sys.exit()

class Map:
	def __init__(self, rooms, moves):
		self.set_size(len(rooms))
		self.state = -1
		self.boards = []
		self.board = self.init_board(rooms)
		self.create_boards(moves)

	def init_board(self, rooms):
		board = []
		for room in rooms:
			board.append({
				'start': 2,
				'end': 3,
				'none': 0
			}[room.type])
		self.boards.append(board)
		return board

	def create_boards(self, moves):
		for move in moves:
			self.read(move)
		self.set_current(0)

	def read(self, move):
		self.state += 1
		board = self.board[:]
		for item in move:
			board[int(item.room)] = 1
		self.boards.append(board)


	def set_size(self, x):
		self.size_x = x
		self.board = [0 for x in range(self.size_x)]

	def get_board(self):
		return self.boards[self.__current]

	def get_current(self):
		return self.__current

	def set_current(self, value):
		if value <= self.state + 1 and value >= 0:
			self.__current = value

class Game:
	def __init__(self, rooms, moves):
		self.map = Map(rooms, moves)
		self.finished = False
		self.init_root()
		self.matrix = [[0 for x in range(self.size_x)] for y in range(self.size_y)]
		self.label = Label(self.root, text='Lemin', foreground='black')
		self.canvas = Canvas(self.root, width=self.map.size_x * box_w + 3, height=self.map.size_y * box_h + 3)
		self.label.pack()
		self.canvas.pack()
		self.init_window()
		self.bind_events()

	def bind_events(self):
		self.root.bind('<space>', self.toggle)
		self.root.bind('<Left>', self.back)
		self.root.bind('<Right>', self.forward)

	def init_root(self):
		self.root = Tk()
		self.root.bind('<Escape>', close)

	def init_window(self):
		for i, val in enumerate(self.matrix):
			x0 = i * box_w + 3
			y0 = 0
			x1 = x0 + box_w
			y1 = y0 + box_h
			self.matrix[i] = self.canvas.create_rectangle(x0, y0, x1, y1,
								fill='beige', outline='black', width=1)

	def set_window_colors(self):
		board = self.map.get_board()
		for (i, visited) in enumerate(board):
				fill = 'black'
				fill = {
					0: 'grey',
					1: 'red',
					2: 'yellow',
					3: 'green'
				}[visited]
				self.canvas.itemconfig(self.matrix[i], fill=fill)

	def toggle(self, event):
		if self.running:
			self.stop()
		else:
			self.start()

	def start(self):
		self.running = True
		self.draw()
		# self.root.after(100, self.routine)
		self.root.mainloop()

	def stop(self):
		self.running = False

	def draw(self):
		self.set_window_colors()
		self.canvas.update()

	def forward(self, event):
		self.map.set_current(self.map.get_current() + 1)
		self.draw()

	def back(self, event):
		self.map.set_current(self.map.get_current() - 1)
		self.draw()

# Parse input
rooms, edges, moves = Parser().parse_input()
# Play game
Game(rooms, moves).start()
