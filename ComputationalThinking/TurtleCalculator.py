# Authors: Batuhan Yenidunya, Harun Selman Karakas  2019
# coding: utf-8

def add(num1,num2):
    return abs(num1+num2)

def subtract(num1,num2):
    return abs(num1 - num2)

def divide(num1,num2):
    if num2 == 0:
        print("division by 0 error")
        return None
    else:
        return abs(num1 // num2)

def multiply(num1,num2):
    return abs(num1*num2)

def draw_shape(gap, edgeSize, numOfEdges, x1, x2, turtle, dashed=False, persentage=0):
	from math import ceil
	turtle.penup()
	turtle.goto(x1, x2)
	turtle.pendown()
	pos1, pos2 = turtle.position()
	if dashed:
		for i in range(numOfEdges):
			for j in range(numOfEdges):
				turtle.forward(edgeSize*(persentage)/numOfEdges)
				turtle.penup()
				turtle.forward(edgeSize*(1-persentage)/numOfEdges)
				turtle.pendown()
			turtle.left(360/numOfEdges)
		turtle.penup()
		turtle.goto(0,0)
	else:
		for i in range(numOfEdges):
			turtle.forward(edgeSize)
			if(numOfEdges % 2 == 1):
				if(i == (ceil(numOfEdges/4))-1):
					pos1 , foo= turtle.position()
			else:
				if(i == (ceil(numOfEdges/4))-1):
					pos1 , foo= turtle.position()
			if(i == int(numOfEdges/2)):
				foo, pos2 = turtle.position()
			turtle.left(360 / numOfEdges)
	return pos1, pos2 
	
def turtle_calculator(num1, num2, operation, edgeSize, gap, numOfEdges):
	"""
	## Make sure you have python 3.xx and Turtle installed.
    Paramaters:
        num1: Integer for calculation
        num2: Integer for calculation
        operation: Indicates operation type. (add, subtract, multiply, divide)
        numOfEdges: Intiger that indicates the shape type. {Triange : 3, Square : 4, Line : 1, Hexagon: 6, or whatever you want}
        edgeSize: Intiger that indicates shape's edge size
        gap: Intiger that indicates gap size between shapes
    Output:
        Turtle Screen
    """
	try :
		import turtle
	except:
		raise Exception("Turtle Module couldn't found. Install and try again.")

	window = turtle.Screen()
	turtle = turtle.Turtle()
	x1 = -285
	x2 = 200
	try:
		result = operation(num1,num2)
		print(result)
		screen_size = edgeSize*numOfEdges
		from math import ceil, cos, modf
		canvas = ceil((result**(1/2)))
		pos1, pos2 = 0,0
		for shapeCount in range(int(result)):
			if ((shapeCount % canvas != 0) or shapeCount==0):
				pos1,pos2 = draw_shape(gap, edgeSize, numOfEdges, x1, x2, turtle)
				if (numOfEdges > 4):
					x1 += (abs(((pos1-x1)-edgeSize))*2)+edgeSize+gap
				else:
					x1 += edgeSize+gap
			else:
				x1 = -285
				if (numOfEdges > 4):
					x2 -= (abs(pos2-x2))+gap
					pos1,pos2 = draw_shape(gap, edgeSize, numOfEdges, x1, x2, turtle)
					x1 += (abs(((pos1-x1)-edgeSize))*2)+edgeSize+gap
				else:
					x2 -= edgeSize+gap
					pos1,pos2 = draw_shape(gap, edgeSize, numOfEdges, x1, x2, turtle)
					x1 += edgeSize+gap
		kalan = modf(result)[0]
		if kalan > 0.0:
			turtle.speed(0)
			draw_shape(gap, edgeSize, numOfEdges, x1, x2, turtle, True, kalan)
		window.exitonclick()
	except:
		print("Operation unsuccessful !")

if __name__ == '__main__':
	turtle_calculator(1,8,multiply,20,10,7)
















