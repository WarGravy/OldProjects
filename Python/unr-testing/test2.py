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
	def __init__(self, pathGiven, isImage = False):
		#Clean path
		path = pathGiven[pathGiven.index(cms + '\\xml\\') + len(cms + '\\xml\\'):]
		if isImage:
			path = path[path.index('images\\') + len('images\\'):]
			self.type = "Image"
		else:
			path = path[path.index('documents\\') + len('documents\\'):]
			self.type = "Document"
		#set members
		path = path.lower()
		self.path = path.replace('\\','/')
		self.altPath = path.replace('\\','/')
		self.name = os.path.basename(path)
		self.containsSpaces = False
		if ' ' in path:
			self.containsSpaces = True
			self.altPath = self.altPath.replace(' ', '%20')
#FUNCTIONS
def getCMSPath():
	try:
		files = os.listdir('\\'+'\cms.unr.edu\wwwroot\cms')
		if files:
			return '\\' + '\cms.unr.edu\wwwroot\cms'
	except:
		return ''
	return ''

def getLevelOneFolderNames(directoryName):
	folders = [ os.path.join(directoryName,f) for f in os.listdir(directoryName) if not os.path.isfile(os.path.join(directoryName,f)) ]
	return folders

def getXML(directoryName, usersDirectory):
	#Read all xml files in the directory
	onlyFiles = [ os.path.join(directoryName, f) for f in os.listdir(directoryName) if f.startswith('x') and os.path.isfile(os.path.join(directoryName,f)) ]
	#Read all checked out xml files in the users directory
	userFolders = [ os.path.join(usersDirectory, f) for f in os.listdir(usersDirectory) if not os.path.isfile(os.path.join(usersDirectory,f)) ]
	for folder in userFolders:
		uPath = folder + '\\xml'
		onlyFiles.extend([ os.path.join(uPath, f) for f in os.listdir(uPath) if f.startswith('x') and os.path.isfile(os.path.join(uPath,f)) ])
	#return
	i = 0
	while i < len(onlyFiles):
		try:
			f = open(onlyFiles[i], 'r', encoding="utf8")
			dataRead = f.read()
			if 'doc' not in dataRead.lower() and 'img' not in dataRead.lower(): 
				#useless
				onlyFiles.pop(i)#Filter out the irrevalent
				i-=1
		except:
			onlyFiles.pop(i)#Filter out unreadable files
			i-=1
		i+=1
		f.close()
	return onlyFiles

def getAssets(directoryName):
	onlyAssets = [ Asset(os.path.join(directoryName, f),  False) for f in os.listdir(directoryName) if os.path.isfile(os.path.join(directoryName,f)) ]
	folders = [ os.path.join(directoryName, f) for f in os.listdir(directoryName) if not os.path.isfile(os.path.join(directoryName,f)) ]
	if folders:
		for folder in folders:
			onlyAssets.extend(getAssets(folder))
	return onlyAssets

def outputResults(resultsList):
	index = cwd + '\\test2-results.html'
	f = open(index, 'w+')
	#HTML START
	f.write('<html>\n')
	f.write('<head></head>\n')
	f.write('<body><ul>\n')
	#WRITE DATA
	if resultsList:
		for result in resultsList:
			f.write('<li>' + result.path + '</li>' +'\n')
	#END WRITE DATA
	f.write('<ul></body></html>\n')
	f.close()
	#HTML END
	#open html file with browser
	webbrowser.get().open(index)

#Global
cwd = os.path.dirname(os.path.realpath(__file__))
cms = getCMSPath()

#MAIN SCRIPT DRIVER
def main():
	unusedAssets = []
	if cms == '':
		print('FAILURE to Read cms.unr.edu. Please connect to the network drive.')
		exit()
	else:
		print('Successfully read the cms.unr.edu directory.')
		print('Scan Running...')
	#Read all level 1 folders for Documents
	print("Getting level one folders...")
	folders = getLevelOneFolderNames(cms + '\\xml\\documents')
	if not folders:
		print('FAILURE to find the Documents folders. Aborting.')
		exit()
	#Read all XML files and filter the files into relevant files for searching
	print("Getting list of all XML files to search...")
	xml = getXML(cms + '\\xml', cms + '\\xml\\users')
	if not xml:
		print('FAILURE to find relevant XML files. Aborting.')
		exit()
	#Foreach primary folder
	for primaryFolder in folders:
		print('Searching '+primaryFolder+' ...')
		print('\n')
		#read all files names
		assets = getAssets(primaryFolder)
		#Foreach XML file
		for xFile in xml:
			try:
				f = open(xFile, 'r', encoding="utf8")
				dataRead = f.read()
				#Foreach file
				i = 0
				while i < len(assets):
					dataRead = dataRead.lower()
					if (assets[i].path in dataRead) or (assets[i].containsSpaces and assets[i].altPath in dataRead): 
					#found 
						assets.pop(i)#Filter out the found
						i-=1
					i+=1
			except:
				#Someone checked in a page that was originally checked out in their folder and so the file cannot be found.
				print("\tFile no longer exists:", xFile)
			f.close()
		#extend unused files to the list of results
		unusedAssets.extend(assets)
	outputResults(unusedAssets)
	print('Scan finished.')
	exit()
	
if __name__ == "__main__": main()