-------------------------------------------------
Developer: Zachary Ty Carlson
Last update: 5/20/13 version 0.7
Designed to run on Ubuntu
-------------------------------------------------
Preparation Steps
-------------------------------------------------
1. Add all documents folders into the documents folder, images in the images folder or add the documents asset folder and rename it to documents and do the same for images after deleting the previous documents/images folder(s).
2. Add all the xml files into the XML folder, make sure all folders added do not have a space in the name.

-------------------------------------------------
Compiling and Run Steps
-------------------------------------------------
1. cd to the proper directory 
2. type "make" into the terminal to compile
3. type "./prog.out" into terminal to run program
*note before you run the program make sure you have all the documents you wish to search in the document folder*
4. After the program has finished, open up the report folder and open up the index.html page in a web browser.
-------------------------------------------------
Version Updates
-------------------------------------------------
Version 0.1 is currently only designed to output to report.txt with results for the documents folder
Version 0.1 includes optimized code, and readability, as well as a new function which reads allows the program to search through the first level one folder in the documents, and all of its sub folders and their contents, and then it continues to the next level one folder. This allows for better utilization of space. There is a global variable that forces the program to only search the first 50 level one folders under documents.
----------------------------------------------------
Version 0.2
outputs to an HTML file based off of an 1990s design
Bugs:
**function: std::vector<std::string> read(std::string path = "."); is currently showing a seg fault when operating at 3000 filed. This is due to the actual vector being too large shortening lifetime.

**doesn't close the last xml file after reading the first directory

**time is not accurate.

All Fixed in version 0.3
----------------------------------------------------
Version 0.3
Fixed previous bugs in version 0.2 as well as added capability to designate where the html report will be and the name of the file by adding a string parameter in the constructor for htmlzack.

htmlzack class added new function: insertRow(string, int) which just attaches an int at the end of a string separated by a colon.

Reading the xml file names without needing to create an input.txt file.

Eliminated preparation steps to run program.

The program can run up to 10,000 files at once. It can have up to 50 files/folders under the documents folder. This means idealy, there would be 0 files and up to 50 level one folders.

The resource folder now has a .txt file with a list of the order the program searches the level 1 folders.

Bugs:

Summary is currently inaccurate and unreliable. Calculations need to be adjusted appropriately and further investigation of errors and possible full proofing the program to prevent errors. -counting may have been fixed. 

If a file has an unknown file size, or no extension, or an unknown extension the program will crash.
----------------------------------------------------
Version 0.4
Added a safety check in the beginning to see if all XML files are readable and outputs the name of the file before it reads it, so if there is an unexpected crash it is outputed to terminal what file it has crashed on.

Added a safety check to see if there are no files with unknown extensions within the folders. The program will output what folder is it checking before it crashes due to an unknown file or extension.

Added functions and a queue class so if the file has a bad name, the search term is modified appropriately and replaces spaces with "%20" and & with "amp;" Note* if the program finds the filename and doesn't need to replace space and & with the html characters, it won't. This will increase speed of the program. Also if it can't find either version of the name, it outputs the name to the html file that has spaces and & and not the version of the name with "&20" and "amp;".

Bugs:

Summary is currently inaccurate and unreliable. Calculations need to be adjusted appropriately and further investigation of errors and possible full proofing the program to prevent errors. Counting the number of files found and with badnames is now accurate. 

----------------------------------------------------
Version 0.5

*Time was removed from the summary.

*Each level1 folder has it's own html page generated in the report folder with the summary located at the top.

*Design of the HTML page output was changes to resemble the colors of the University of Nevada, Reno.

*All the files are sorted Alphabetically, where Capitals have higher priority than lowercases.

*If a file has a bad name but was not found as well, it is highlighted in red on the html page.

*The functions non related to the actual program, but are being used in the program have been moved to their own header and .cpp file. The Code has been cut down to be easier to read, and filenames are no longer just strings, but structures with two boolean variables attached to them that resemble if a file is found or has a bad name.

*The summary now contains the percentage of what files are not being used and the percentage of files with bad names.

*Outputs a main report.html page with links to all other html pages (with notes to the number of files not in use, and the number of bad names under that folder), as well as the top logo links back to the report.html on ever page. The Main report.html page should have a total summary output at the top as well.

*Added a list of all the X-ID's the badnames where found on under their name, as well as active links to the cms embeded on in the lists.

*Added a css sheet to reset styles so it displays on all browsers properly and restructured the html pages into their own folder within the report.

*Added functionality so that is handles XML pages in folders under the XML folder, and outputs that these are considered "checked out: "

*Prompts the user for the date to display in the summary

*The XML file directory was modified to handle up to 300 sub folders within it, which are all considered "checked in"

The current limitations of the program are that you can only have 300 subfolders within the XML directory and 30 level 1 folders within the documents folder.

BUGS:
If a file has a bad name that contains a strange character that could possibly be changed in the xml files for html reasons, and that character is not a space or an & it is possible for it to appear as not in use.
----------------------------------------------------
Version 0.6

*The output was changed with the most recent updates:
**Files not in use that have bad names are shown in red
**files with badnames have been changed to files with bad names that are in use
**The links for Xid's open up in a new window/tab while the report still stays in the same window/tab.

*Handles Images just like files.

*The program now handles images and documents simultaneously. 

*The index page was changed to link to a documents report and images report. Clicking the logo at the top of any html page will bring you back to index.html with links to both reports.

*fixed a bug where the badnames XID list is now including files with spaces and badnames

*fixed a bug where if you entered a number less than 4 there would be an infinite loop

*The program writes a blank.txt file under the documents and images folder so there is no crashes when the folders are empty.

*Added prototype descriptions for all functions in the code

*Fixed a bug where the directories where never closing while reading files.

Unknown Possibilities:
If a file has a bad name that contains a strange character that could possibly be changed in the xml files for html reasons, and that character is not a space or an & it is possible for it to appear as not in use.
----------------------------------------------------
Version 0.7

*The Program now runs on average 20-40minutes instead of 4-6 hours. 

*The Program is now case insensitive and creates duplicate versions of the xml files in the resources/xml folder that are all lowercase. These files need to be deleted periodically. (This is done everytime the program is started)

*Deletes all files in the following folders at the beginning of the program:
**resources/xml
**report/dpages
**report/ipages

*Fixed a small bug where if a folder had badnames but none of them were in use it wouldn't output "none" in red under "files with bad names in use". 

Unknown Possibilities:
If a file has a bad name that contains a strange character that could possibly be changed in the xml files for html reasons, and that character is not a space or an & it is possible for it to appear as not in use.
----------------------------------------------------
Future Updates
----------------------------------------------------
*Link the documents and images not in use (this will be different depending on what folder they are in)

*Add function to summary to see how many files have specific extensions

*Optimization of code
**Change the terminal output
**Adding a .exe file

*Running on Windows

*Future interface?

*Possible download off the network the xml files, image files, and document files
