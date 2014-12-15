#!/usr/bin/python

#Zachary Carlson
#University of Nevada, Reno
#Project Samurai Test 1
import webbrowser

def detail(baseHref):
	webbrowser.get().open(baseHref)
	pass
def displayData(baseHref):
	pass
def general(baseHref):
	pass
def topLevel(baseHref):
	pass
def dupDegree(baseHref):
	pass
def degrees(baseHref):
	pass
def sectionFronts(baseHref):
	pass
def nvToday(baseHref):
	pass
	
	
	
def main():
	baseHref = "http://staging.unr.edu"
	if True:
		print("Opening Detail List Pages")
		print("-----------------------------------------------")
		detail(baseHref)
	if True:
		print("Opening Display Data Pages")
		print("-----------------------------------------------")
		displayData(baseHref)
	if True:
		print("Opening General Pages")
		print("-----------------------------------------------")
		general(baseHref)
	if True:
		print("Opening Top Level Pages")
		print("-----------------------------------------------")
		topLevel(baseHref)
	if True:
		print("Opening Duplicate Degree Pages")
		print("-----------------------------------------------")
		dupDegree(baseHref)
	if True:
		print("Opening Degree Pages")
		print("-----------------------------------------------")
		degrees(baseHref)
	if True:
		print("Opening Section Fronts")
		print("-----------------------------------------------")
		sectionFronts(baseHref)
	if True:
		print("Opening Nevada Today Pages")
		print("-----------------------------------------------")
		nvToday(baseHref)

if __name__ == "__main__": main()
