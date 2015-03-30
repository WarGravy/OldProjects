#!/usr/bin/python

#Zachary Carlson
#CS 381 assignment 1
import urllib
import sys
import shutil

def writeNewPage(buttercup):
	f = urllib.urlopen('http://www1.cse.unr.edu/~zcarlson/')
	line = f.read()
	start = line.find('<!--Comic Strip -->')
	end = line.find('<!--Comic Strip END -->')
	#first half
	htmlContents = line[:start]
	#attach image 
	htmlContents += "<!--Comic Strip --><p><img src=\"" + buttercup + "\" class=\"img-responsive img-thumbnail\" /></p>"
	#second half
	htmlContents += line[end:]
	return htmlContents

def getButterCupStrip():
	f = urllib.urlopen('http://www.buttercupfestival.com/')
	line = f.read()
	#trim to the first image
	start = line.find('src=')
	line = line[start:]
	#trim to the actual url
	start = line.find('http')
	line = line[start:]
	#trim the end
	end = line.find('>')
	line = line[:end]
	if '\"' in line:
		end = line.find('\"')
		line = line[:end]
	return line

def main():
	#back up the file
	shutil.copyfile("index.html", "index-backup.html")
	buttercup = getButterCupStrip()
	htmlContent = writeNewPage(buttercup)
	f = open("index.html", 'w')
	f.write(htmlContent)
	f.close()
	pass

if __name__ == "__main__": main()
