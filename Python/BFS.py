import collections

class Node:
  value = None
  left = None
  right = None

  def __init__(self,value):
    self.value = value

  def getAdjecents(self):
    return [self.left, self.right]

  def addEdges(self,leftNode,rightNode):
    self.left = leftNode
    self.right = rightNode


n1 = Node(8)
n2 = Node(3)
n3 = Node(10)
n4 = Node(1)
n5 = Node(6)
n6 = Node(14)
n7 = Node(4)
n8 = Node(7)
n9 = Node(13)


n1.addEdges(n2,n3)
n2.addEdges(n4,n5)
n3.addEdges(None,n6)
n6.addEdges(n9,None)
n5.addEdges(n7,n8)



def bfs(root,target):
  visited = set()
  visited.add(root)
  queue = collections.deque([root]) 
  counter = 1

  while queue:
    vertex = queue.popleft()
    
      
    if vertex != None:
      if vertex.value == target:
        print("The target node was found in " + str(counter) + " steps.")
        return
      print(vertex.value)
      for neighbour in vertex.getAdjecents():
        if neighbour not in visited:
          visited.add(neighbour)
          queue.append(neighbour)
      counter += 1

  print("The target was not found in the list.")