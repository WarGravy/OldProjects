-----------------------------------------------------------------
TEST 1
-----------------------------------------------------------------
Dependencies: Python 3.4.2

How to set up Python to be used in the command line on Windows 7
-----------------------------------------------------------------
1. Download Python 3 from here: https://www.python.org/downloads/
2. Run the Executable and follow the install steps.
3. Open up your start menu
4. Right click on Computer
5. Click on Advanced system settings
6. Click on Environment Variables
7. Select "Path" from the system variables
8. Click Edit
9. Append the end of the variable value with C:\Python34; 
(NOTE: the ';' acts as a delimeter, make sure before appending the
 value that there is a ';' to separate your value from the last 
 value.)
10. Click Ok, Ok again, and finally Apply

DONE! You can now use the Python interpreter from the cmd window by 
typing python.

Working with the Script
-----------------------------------------------------------------
*You don't need to know how to write python code to work with this 
script.

*Comments are denoted by #. In the Main function at the bottom of the 
script, you can change the if statements from True to False to disable
some of the tests.

*Line 93 and 94 are the base href values that the script uses to 
determine if you are testing on staging or production. Simply comment 
the appropriate line to swap between testing on staging and production.

*At the top of the script on line 8 I have saved the file location for 
easy access. To run the script type the following into the cmd window:

>python C:/YOUR_PATH/test1.py