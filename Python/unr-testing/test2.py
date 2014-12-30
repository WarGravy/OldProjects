#!/usr/bin/python

#Zachary Carlson
#University of Nevada, Reno
#Project Samurai Test 2
#Checks for all unused documents

#Path to file
#C:\Users\zcarlson\Documents\GitHub\OldProjects\Python\unr-testing\test2.py
import webbrowser
import os

#CLASSES
class Asset():
	def __init__(self, path, isImage = False):
		self.path = path
		self.altPath = path
		self.name = os.path.basename(path)
		self.found = False
		self.type = "Document"
		self.containsSpaces = False
		if isImage:
			self.type = "Image"
		if ' ' in path:
			self.containsSpaces = True
			self.altPath = self.altPath.replace(' ', '%20')
#FUNCTIONS
def getCMSPath():
	try:
		onlyfiles = os.listdir('\\'+'\cms.unr.edu\wwwroot\cms')
		if onlyfiles:
			return '\\'+'\cms.unr.edu\wwwroot\cms'
	except:
		return ''
	return ''

def getLevelOneFolderNames(directoryName):
	pass

def getXML(directoryName, usersDirectory):
	pass

def getFileNames(directoryName):
	pass

def writeResults(resultsList):
	f = open('test2-results.html', 'w+')
	f.close()
	#write data
	#index = 'G:\(Zack Carlson)\site-related\TotalValidatorTool Criminal Justice\TotalValidator.html'
	#open html file with browser
	webbrowser.get().open('test2-results.html')

#MAIN SCRIPT DRIVER
def main():
	#Find the cms.unr.edu directory
	cms = getCMSPath()
	if cms == '':
		print('FAILURE to Read cms.unr.edu. Please connect to the network drive.')
		exit()
	else:
		print('Successfully read the cms.unr.edu directory.')
		print('Scan Running...')
	#Read all level 1 folders for Documents

	#Read all XML files and filter the files into relevant files for searching

	#Foreach primary folder

		#read all files names

		#Foreach XML file
			#Foreach file 
				#if found remove from list and increment the index
			#Filter out the found
		#Append unused files to the list of results

	#writeResults()
	print('Scan finished.')
	exit()
	
if __name__ == "__main__": main()
