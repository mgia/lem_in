from parser import Parser

rooms, edges, moves = Parser().parse_input()

# for move in moves:
# 	for item in move:
# 		print(item.room, end='')
# 	print()

matrix = [0 for x in range(4)]

for i, val in enumerate(matrix):
	print(val)
