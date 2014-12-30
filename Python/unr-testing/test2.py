#!/usr/bin/python

#Zachary Carlson
#University of Nevada, Reno
#Project Samurai Test 2
#Checks for all unused documents

#Path to file
#C:\Users\zcarlson\Documents\GitHub\OldProjects\Python\unr-testing\test2.py

import webbrowser
import os

def cmsPath():
	try:
		onlyfiles = os.listdir('\\'+'\cms.unr.edu\wwwroot\cms')
		if onlyfiles:
			return '\\'+'\cms.unr.edu\wwwroot\cms'
	except:
		return ''
	return ''

def storeFileNames(directoryName):
	pass

def writeResults(resultsList):
	f = open('test2-results.html', 'w+')
	f.close()
	#get file path
	#open html file with browser
	#index = 'G:\(Zack Carlson)\site-related\TotalValidatorTool Criminal Justice\TotalValidator.html'
	#webbrowser.get().open(index)

def main():
	#Find the cms.unr.edu directory
	cms = cmsPath()
	if cms == '':
		print('FAILURE to Read cms.unr.edu. Please connect to the network drive.')
		exit()
	else:
		print('Successfully read the cms.unr.edu directory. Script Running...')
	#Read all files and filter the files into relevant files for searching

	#Foreach primary folder, read all files names and mark as found
		#Foreach XML file
			#Foreach file 
				#if found remove from list and increment the index
			#Filter out the found
		#Append unused files to the list of results

	#writeResults()
	print('Script finished.')
	exit()
	
if __name__ == "__main__": main()
