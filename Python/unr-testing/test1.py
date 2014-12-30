#!/usr/bin/python

#Zachary Carlson
#University of Nevada, Reno
#Project Samurai Test 1

#Path to file
#C:\Users\zcarlson\Documents\GitHub\OldProjects\Python\unr-testing\test1.py
import webbrowser

def detail(baseHref):
	webbrowser.get().open(baseHref + '/cse/about')#basic detail page
	webbrowser.get().open(baseHref + '/commencement/ceremony')#video component
	webbrowser.get().open(baseHref + '/marcom/style-guide')#A-Z Listing
	webbrowser.get().open(baseHref + '/cse/contact')#Contact Us Tables
	webbrowser.get().open(baseHref + '/ehs/upcoming-events')#Events Embed
	pass
def displayData(baseHref):
	webbrowser.get().open(baseHref + '/ehs/search?q=lab')#Google CSE Code
	webbrowser.get().open(baseHref + '/oiss/forms')#Forms
	webbrowser.get().open(baseHref + '/ehs/forms-and-applications')#Forms with Search and Filter
	webbrowser.get().open(baseHref + '/liberal-arts/student-resources/academic-advising/advising-faqs')#FAQ without search and filter
	webbrowser.get().open(baseHref + '/housing/faq')#FAQ w/ Search and Categories
	webbrowser.get().open(baseHref + '/site-map')#Site Map
	webbrowser.get().open(baseHref + '/cse/people/faculty')#Faculty List
	webbrowser.get().open(baseHref + '/biology/people/patricia-berninsone')#Person Page
	webbrowser.get().open(baseHref + '/engineering/student-resources/careers-and-internships/for-employers/submit-a-job-posting')#FormStack Form
	webbrowser.get().open(baseHref + '/grad/forms/exit-survey')#Google Forms
	webbrowser.get().open(baseHref + '/liberal-arts/about/news')#News
	webbrowser.get().open(baseHref + '/gsa/living-in-reno')#Media Include
	webbrowser.get().open(baseHref + '/cse/resources/fellowships')#RSS
	#List of POI
	webbrowser.get().open(baseHref + '/housing/dining/locations/downunder')#POI Detail
	webbrowser.get().open(baseHref + '/housing/tool-kit/rates-2015-2016')#Yearly Cost Component
	webbrowser.get().open(baseHref + '/housing/dining/locations/downunder/daily-menu')#Food Menu Data
	webbrowser.get().open(baseHref + '/grad/about/graduate-faculty')#Graduate Faculty Members
	webbrowser.get().open(baseHref + '/grad/tuition-and-fees')#Rate Summaries
	#Things To Do
	webbrowser.get().open(baseHref + '/tutoring-center/types-of-tutoring/supplemental-instruction/si-schedule')#Excel Embed
	webbrowser.get().open(baseHref + '/research-integrity/research-integrity')#Content Blocks
	webbrowser.get().open(baseHref + '/hr/compensation-and-evaluation/pdqs')#PDQ
	webbrowser.get().open(baseHref + '/liberal-arts/degrees')#List of Degrees
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
	webbrowser.get().open(baseHref)#Home
	webbrowser.get().open(baseHref + '/about')#About
	webbrowser.get().open(baseHref + '/admissions')#admissions
	webbrowser.get().open(baseHref + '/academics')#academics
	webbrowser.get().open(baseHref + '/student-life')#student life
	webbrowser.get().open(baseHref + '/research')#research
	webbrowser.get().open(baseHref + '/impact')#impact
	pass
def dupDegree(baseHref):
	webbrowser.get().open(baseHref + '/liberal-arts/degrees/criminal-justice/ba')
	webbrowser.get().open(baseHref + '/liberalarts/degrees/criminial-justice/ba-law-justice')
	webbrowser.get().open(baseHref + '/liberal-arts/degrees/criminal-justice/ma')
	pass
def degrees(baseHref):
	webbrowser.get().open(baseHref + '/degrees')#degrees homepage
	webbrowser.get().open(baseHref + '/degrees/search?p=level')#view by level
	webbrowser.get().open(baseHref + '/degrees/search?p=college')#view by college
	webbrowser.get().open(baseHref + '/search?p=interest')#view by interest
	webbrowser.get().open(baseHref + '/degrees/search')#view all
	webbrowser.get().open(baseHref + '/degrees/computer-science-and-engineering/bs#Overview')#Sample
	pass
def sectionFronts(baseHref):
	webbrowser.get().open(baseHref + '/me')
	webbrowser.get().open(baseHref + '/cse')
	webbrowser.get().open(baseHref + '/cla')
	webbrowser.get().open(baseHref + '/sponsored-projects')
	webbrowser.get().open(baseHref + '/research-integrity')
	webbrowser.get().open(baseHref + '/math')
	pass
def nvToday(baseHref):
	webbrowser.get().open(baseHref + '/nevada-today')#Homepage
	webbrowser.get().open(baseHref + '/nevada-today/news')#News
	webbrowser.get().open(baseHref + '/nevada-today/news/about')#About
	webbrowser.get().open(baseHref + '/nevada-today/news/2014/ezekiel-is-november-employee-of-month')#News Story
	pass
	
	
	
def main():
	#baseHref = "http://staging.unr.edu"
	baseHref = "http://www.unr.edu"
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
