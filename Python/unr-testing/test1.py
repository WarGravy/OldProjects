#!/usr/bin/python

#Zachary Carlson
#University of Nevada, Reno
#Project Samurai Test 1
import webbrowser

def detail(baseHref):
	webbrowser.get().open(baseHref + '/cse/about')#basic detail page
	webbrowser.get().open(baseHref + '/commencement/ceremony')#video component
	webbrowser.get().open(baseHref + '/marcom/style-guide')#A-Z Listing
	webbrowser.get().open(baseHref + '/cse/contact')#Contact Us Tables
	pass
def displayData(baseHref):
	pass
def general(baseHref):
	webbrowser.get().open(baseHref + '/search')#Search
	webbrowser.get().open(baseHref + '/site-map')#site-map code
	webbrowser.get().open(baseHref + '/accessibility')
	webbrowser.get().open(baseHref + '/contact-us')
	webbrowser.get().open(baseHref + '/copyright/dmca')#second level
	webbrowser.get().open(baseHref + '/emergency/alerts/faq')#FAQ functionality
	webbrowser.get().open(baseHref + '/faculty-staff-forms')#Forms functionality
	pass
def topLevel(baseHref):
	pass
def dupDegree(baseHref):
	pass
def degrees(baseHref):
	pass
def sectionFronts(baseHref):
	webbrowser.get().open(baseHref + '/me')
	webbrowser.get().open(baseHref + '/cse')
	webbrowser.get().open(baseHref + '/cla')
	webbrowser.get().open(baseHref + '/sponsored-projects')
	webbrowser.get().open(baseHref + '/research-integrity')
	pass
def nvToday(baseHref):
	webbrowser.get().open(baseHref + '/nevada-today')#Homepage
	webbrowser.get().open(baseHref + '/nevada-today/news')#News
	webbrowser.get().open(baseHref + '/nevada-today/news/about')#About
	webbrowser.get().open(baseHref + '/nevada-today/news/2014/ezekiel-is-november-employee-of-month')#News Story
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
