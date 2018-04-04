################################################################################
#							LIBRARIES
################################################################################

from parser import Parser

import matplotlib
matplotlib.use('TkAgg')
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt

import networkx as nx

from tkinter import *

################################################################################
#							COMMANDS
################################################################################

# Parse input
# rooms, edges, moves = Parser().parse_input()

# root = Tk()
# root.wm_title("Lemin: Animated Graph embedded in TK")

# Matplotlib: create figure
f = plt.figure(figsize=(5,4))
a = f.add_subplot(111)
plt.axis('off')

G = nx.Graph()
# Add vertexes to graph
for i, room in enumerate(rooms):
	G.add_node(i, type=room.type)

print(G.nodes())

for edge in edges:
	G.add_edge(edge.r1, edge.r2)

nx.draw_networkx(G,ax=a)

# tk.drawingArea
canvas = FigureCanvasTkAgg(f, master=root)
canvas.show()
canvas.get_tk_widget().pack(side=TOP, fill=BOTH, expand=1)

root.mainloop()
