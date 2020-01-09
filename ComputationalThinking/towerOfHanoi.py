# Author: Batuhan Yenidunya 2019
# coding: utf-8

def move(base, target):
	print('Move one disc from {} to {}!'.format(base,target))

def hanoi(numOfDisks, base, helper, target):
	if numOfDisks == 0:
		pass
	else:
		hanoi(numOfDisks-1,base,target,helper)
		move(base, target)
		hanoi(numOfDisks-1,helper, base, target)

if __name__ == '__main__':
	hanoi(4,"A","B","C")
