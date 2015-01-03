#!/usr/bin/python

#Zachary Carlson
#University of Nevada, Reno
#Project Samurai Test 2
#Checks for all unused documents

#Path to file
#C:\Users\zcarlson\Documents\GitHub\OldProjects\Python\unr-testing\test2.py
import webbrowser
import os
import time
from multiprocessing import Process
start_time = time.time()

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
		self.originalPath = path
		self.path = path.replace('\\','/')
		self.altPath = path.replace('\\','/')
		self.name = os.path.basename(path)
		self.containsSpaces = False
		if ' ' in path:
			self.containsSpaces = True
			self.altPath = self.altPath.replace(' ', '%20')
class FolderData():
	def __init__(self, name, total):
		self.name = name
		self.total = total
		self.unusedFiles = []
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

def getAssets(directoryName, isImages):
	onlyAssets = [ Asset(os.path.join(directoryName, f),  isImages) for f in os.listdir(directoryName) if os.path.isfile(os.path.join(directoryName,f)) ]
	folders = [ os.path.join(directoryName, f) for f in os.listdir(directoryName) if not os.path.isfile(os.path.join(directoryName,f)) ]
	if folders:
		for folder in folders:
			onlyAssets.extend(getAssets(folder, isImages))
	return onlyAssets

def outputResults(results, warningXML, title):
	index = cwd + '\\test2-'+title.lower().replace(' ', '-')+'.html'
	f = open(index, 'w+')
	#HTML START
	f.write('<html>\n')
	f.write('<head>\n')
	f.write('<meta charset="utf-8">\n')
	f.write('<meta http-equiv="X-UA-Compatible" content="IE=edge">\n')
	f.write('<link href="./test2-assets/css/bootstrap.min.css" rel="stylesheet"/>\n')
	f.write('<title>')
	f.write(str(title))
	f.write('</title>\n') 
	f.write('</head>\n')
	f.write('<body>\n')
	f.write('<div class="container">\n')
	#WRITE DATA
	#Time
	f.write('<p id="time"><strong>Runtime: </strong>')
	f.write( str((time.time() - start_time) / 60 ))#time provided in seconds converted to minutes
	f.write(' minutes')
	f.write('</p>')
	if warningXML:
		#Warning
		f.write('<p id="warning"><strong>Warning:</strong> Some files were detected during the scan that may have changed:</p>\n')
		f.write('<ul>\n')
		for warning in warningXML:
			f.write('<li>'+ warning +'</li>\n')
		f.write('</ul>\n')
	#Documents/Images
	if results:
		f.write('<div role="tabpanel"><ul class="nav nav-tabs" role="tablist">\n')
		#Tabs
		for key in results:
			f.write('<li role="presentation" class="active"><a href="#'+ results[key].name.replace(' ', '-') +'" aria-controls="'+ results[key].name.replace(' ', '-') +'" role="tab" data-toggle="tab">'+ results[key].name +'</a></li>\n')
		
		#Tab content
		f.write('</ul><div class="tab-content">\n')
		for key in results:
			f.write('<div role="tabpanel" class="tab-pane active" id="'+ results[key].name.replace(' ', '-') +'">')
			f.write('<p class="unused-count"><strong>Unused Files: </strong>')
			f.write( str(len(results[key].unusedFiles)))
			f.write('</p>')
			f.write('<p class="total-count"><strong>Total Files Searched: </strong>')
			f.write( str(results[key].total))
			f.write('</p>')
			f.write('<ul>\n')
			for unusedFile in results[key].unusedFiles:
				f.write('<li>' + unusedFile.path + '</li>' +'\n')
			f.write('</ul></div>\n')

	#END WRITE DATA
	f.write('</div></div></div>\n')
	f.write('<!-- jQuery (necessary for Bootstrap\'s JavaScript plugins) -->\n')
	f.write('<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>\n')
	f.write('<!-- Include all compiled plugins (below), or include individual files as needed -->\n')
	f.write('<script src="./test2-assets/js/bootstrap.min.js" type="javascript"></script>\n')
	f.write('</body></html>\n')
	f.close()
	#HTML END
	print ('outputting process with id: ', os.getpid())
	#open html file with browser
	webbrowser.get().open(index)

def search(xml, isImages = False):
	#variables
	if isImages:
		assetsName = 'images'
		outputName = 'Unused Images'
	else:
		assetsName = 'documents'
		outputName = 'Unused Documents'
	warningXML = []#list of detected changes
	results = {}#dictionary of results

	#Read all level 1 folders for Documents/Images
	print("Getting level one folders...")
	folders = getLevelOneFolderNames(cms + '\\xml\\' + assetsName)
	if not folders:
		print('FAILURE to find the ' + assetsName + ' folders. Aborting.')
		exit()

	#Foreach primary folder
	for primaryFolder in folders:
		print('Searching '+primaryFolder+' ...')
		print('\n')
		#read all files names
		assets = getAssets(primaryFolder, isImages)
		results[primaryFolder] = FolderData(os.path.basename(primaryFolder), len(assets))
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
				if xFile not in warningXML:
					print("\tFile no longer exists:", xFile)
					warningXML.append(xFile)
			f.close()
		#extend unused files to the list of results
		results[primaryFolder].unusedFiles.extend(assets)#update the dictionary for the folder
	#Output results to an html file
	outputResults(results, warningXML, outputName)

#Global
cwd = os.path.dirname(os.path.realpath(__file__))
cms = getCMSPath()

#MAIN SCRIPT DRIVER
def main():
	#check cms connection
	if cms == '':
		print('FAILURE to Read cms.unr.edu. Please connect to the network drive.')
		exit()
	else:
		print('Successfully read the cms.unr.edu directory.')
		print('Scan Running...')

	#Read all XML files and filter the files into relevant files for searching
	print("Getting list of all XML files to search...")
	xml = getXML(cms + '\\xml', cms + '\\xml\\users')
	if not xml:
		print('FAILURE to find relevant XML files. Aborting.')
		exit()

	#fork the current process:- parent is images, child is documents
	p = Process(target=search, args=(xml, False))
	p.start()
	search(xml, True)
	p.join()
	print('Scan finished.')
	exit()
	
if __name__ == "__main__": main()