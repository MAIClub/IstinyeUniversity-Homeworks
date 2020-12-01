"""
	simpleReflexAgent.py
	Simple Reflex Agent implementation. 
    
    THIS IMPLEMENTATION IS NOT COMPLETE! MIGHT NOT WORK
    FOR ANOTHER DATASET.

	Created by batuhanyenidunya on 19.02.2020.
	https://github.com/batuhanyndny
"""

ENV = {
	"point A" : {
		"is_dirty" : True,
		"distance" : 80
	},
	"point B" : {
		"is_dirty" : True,
		"distance" : 150
	},
	"point C" : {
		"is_dirty" : True,
		"distance" : 349
	},
	"point D" : {
		"is_dirty" : True,
		"distance" : 120
	},
	"point E" : {
		"is_dirty" : True,
		"distance" : 50
	},
	"point F" : {
		"is_dirty" : True,
		"distance" : 25
	}
}

def goto_nearest_dirt(point):
	pointName = list(point.keys())[0]
	print("Going to point {} with distance {}".format(pointName,point[pointName]["distance"]))
	point[pointName]["distance"] = 0
	return point

def clean_dirt(point):
	pointName = list(point.keys())[0]
	point[pointName]["is_dirty"] = False
	print("Dirt cleaned")
	return point

def search_for_optim(ENV):
	nearest_point = ""
	nearest_distance = 1000
	is_dirty = None
	for (point,detail) in ENV.items():
		if detail["is_dirty"]:
			if detail["distance"] < nearest_distance:
				nearest_distance = detail["distance"]
				nearest_point = point
	return {nearest_point:{
		"is_dirty" : is_dirty,
		"distance" : nearest_distance
		}
	}
	


def analyzeEnv(ENV):
	points_done = False
	for (point,detail) in ENV.items():
		if detail["is_dirty"]:
			point = RULES_ACTIONS["is_dirty"](ENV)
			if point:
				point = RULES_ACTIONS["travel"](point)
				point = RULES_ACTIONS["clean_dirt"](point)
				pointName = list(point.keys())[0]
				ENV[pointName] = point[pointName]




RULES_ACTIONS = {
	"dirt_cleaned" : search_for_optim,
	"is_dirty" : search_for_optim,
	"travel" : goto_nearest_dirt,
	"clean_dirt" : clean_dirt,
}


def simpleReflexAgent(ENV):
	br = True
	while br:
		br = False
		analyzeEnv(ENV)
		for detail in ENV.values():
			if detail["is_dirty"]:
				br = True
				break

if __name__ == '__main__':
	simpleReflexAgent(ENV)