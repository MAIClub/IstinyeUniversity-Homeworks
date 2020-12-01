"""
	breadthFirstSearch.py
	Breadth First Search algorithm implementation using adjacency list.

	Created by batuhanyenidunya on 13.03.2020.
	https://github.com/batuhanyndny
"""
class Node:

	def __init__(self,parent, child, label):
		self.parent = parent
		self.child = child
		self.label = label

	def __str__(self):
		return str(self.parent) + " " + str(self.child) + " " + str(self.label)


class Tree:

	def __init__(self, matrix):
		self.nodes = []
		for (label,node) in matrix.items():
			parent = -1
			child = []
			for value in node:
				if value == 2:
					parent = node.index(value)
				if value == 1:
					index = node.index(value)
					child.append(index)
					node[index] = 0

			self.nodes.append(Node(parent,child,label))

		self.fifo()
		# for i in self.nodes:
		# 	print(i)


	def fifo(self):
	    for i in range(len(self.nodes)):
	        for j in range(0, len(self.nodes)-i-1):
	            if self.nodes[j].parent > self.nodes[j+1].parent :
	                self.nodes[j], self.nodes[j+1] = self.nodes[j+1], self.nodes[j]


	def breadthFirstSearch(self,goalLabel):
		for node in self.nodes:
			if node.label == goalLabel:
				index = self.nodes.index(node)
				return self.solution(index)
			else:
				pass

	def solution(self,index):
		path = [index]
		solNode = self.nodes[index]
		for i in range(index):
			parentIndex = self.nodes[index].parent #parent index
			if (parentIndex == -1):
				break
			path.append(parentIndex)
			index = parentIndex
		path = path[::-1]
		print(path)
		return path

matrix = {  "8"  : [0,1,1,0,0,0,0,0,0],
			"3"  : [2,0,0,1,1,0,0,0,0],
			"1"  : [0,2,0,0,0,0,0,0,0],
			"10" : [2,0,0,0,0,1,0,0,0],
			"6"  : [0,2,0,0,0,0,1,1,0],
			"14" : [0,0,2,0,0,0,0,0,1],
			"4"  : [0,0,0,0,2,0,0,0,0],
			"7"  : [0,0,0,0,2,0,0,0,0],
			"13" : [0,0,0,0,0,2,0,0,0]
		}


tree = Tree(matrix)

tree.breadthFirstSearch("4")

