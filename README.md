# Color Accessibility Checker

## Description

The purpous of this program is to pull the color values from an imported website code provided by the user. These color values will be hexadecimal from the html code, or simply stated like "mediumblue." Our goal is to be able to analyze a file and pull any desired amount of color data in found hexadecimal format. We can then store this data for later analysis for possible color accessability issues with said website or run tests for the user. The data is stored in three vectors called redVals, greenVals and blueVals, and with these we can print all the found colors in either hexadecimal or decimal number systems for ease of analysis. There also will be functions for configuring the search functionality like changing the search term, changing the length of the readout, and changing the number of lines to search through. 

# v0.2 Updates

In the v.0.2 update, I've added numerous functions, as well as converted old functionality that was coded in main() to be removed from there and instead be used in dedicated funcions. On top of adding functions, this deliverable's main goal was to be able to convert and store the hexadecimal color values from the .html files imported. This was achieved in two of the functions I added. The first was simply improving the readout for the color searching function to read out part of the line with the hex value, but also to convert the hex value and print it in 3 decimal values below that. Also, these indivual color values would be stored in their own vectors called redVals, greenVals, and blueVals. 

# v1.0 Updates

In the v1.0 update, I've added a couple more functions, a class analyzer (of most used object "probe") and its respective .h and .cpp files, various bug fixes and some QoL changes including some colors in the output stream. These colors are not necessarily the best in terms of preventing potential accessability conflicts, but they are good for adding contrast for certain pieces of information in the menu and in configuration functions. There were some unfinished functions like editReadoutLength in v.0.2, which are now all finished and working, as well as new functions like editLinesToSearch. 

The main purpose of this program remains to gather, convert, and store color information from any file. This is different than simply using ctrl+f to find something in a file, as we can store and convert the information to look at later and have it all in one place. 


## Developer

Kent L Menigoz

## Example

To run the program, give the following commands:

  1) FIRST: when the menu prompts, type 1 and press enter

  2) this will open the runSearchFunct function, so now enter a filename. try "w3schools.html"

  3) the function will now search and display lines that contain the search term (by default color:#), as well as display the color values in hex and underneith in decimal if possible, and store them in vectors for each RGB

  4) once the search function has been run at least once, we can read from the stored colors by typing 5 and pressing enter at the menu

  5) once running the readStoredHexOrDec function by entering 5 at the menu, we can enter h/H or d/D to read the stored color values in the desired number system. 

  6)To change what is shown by the runSearchFunct function, we can use the configuration functions (menu 2 through 4) to change the search term, the length of the found color readout, and the number of lines to search through. This allows us to use this program for searching and collecting data on any kind of file, without manually altering the program's code. 

## 

Here is an example of how to use the program:
  
``` 
EXAMPLE 1
 Menu
------
(1) Open a new file for analyzing
(2) Edit the search term
(3) Adjust the colorInfo readout length
(4) Adjust the number of lines to search
(5) Read from stored colors (open file first)

(6) Quit program

1  [Enter]

Enter a file name to check its colors:
For example, try entering w3schools.html

type "w3schools.html"  [Enter]


EXAMPLE 2
 Menu
------
(1) Open a new file for analyzing
(2) Edit the search term
(3) Adjust the colorInfo readout length
(4) Adjust the number of lines to search
(5) Read from stored colors (open file first)

(6) Quit program

5  [Enter]
Read Hex or Dec? (H/D)
d  [Enter]


EXAMPLE 3
 Menu
------
(1) Open a new file for analyzing
(2) Edit the search term
(3) Adjust the colorInfo readout length
(4) Adjust the number of lines to search
(5) Read from stored colors (open file first)

(6) Quit program

5  [Enter]
Read Hex or Dec? (H/D)
h  [Enter]
```

Here is an example of the program running:

```
EXAMPLE 1 (partial displayed line with search term and converted decimal value)
Line 16, found...
color:#4CAF50
76,175,80


Line 21, found...
color:#ffffff
255,255,255


Line 36, found...
color:#555555
85,85,85


Line 41, found...
color:#4CAF50
76,175,80


Line 43, found...
color:#fff;ba
 ^Bad....skipped!



EXAMPLE 2 (stored RGB decimal readout)
76,80,175
255,255,255
85,85,85
76,80,175
70,73,160
33,243,150
255,0,215
255,0,215



EXAMPLE 3 (stored RGB hexadecimal readout)
0x4c50af
0xffffff
0x555555
0x4c50af
0x4649a0
0x21f396
0xff0d7
0xff0d7
```


## C++ Guide

### Variables and Data Types

integers: for R, G, and B values, because these are represented by whole numbers 0 to 255. 
       ...also, int for the line number of the file opened, as well as .find output recording 
character: the choice (y/n) for repeated file analysis
fstream: for reading the file
string: for recording the input file name, and for "text" and "colorInfo" while searching
           for the "hot" term


### Input and Output

There is input and output in main.cpp becase we first cout the main question, for the user to enter a filename to analyze. There is input in the following line where we gather that information. There is also some output if there is an error, as well as when deciding to repeat the loop and analyze another file, where we cout the question, and cin the decision right after (y/n). 

### Decisions

The program makes descisions when trying to find text with "color:" because it checks to see if the file opened before doing anything else. IF the file is open, it will go line by line searching for the "hot" search term variable assigned to "color:" as long as the reader has not reached the end of the file. In future versions we plan to use descisions to analyze color combinations for accessability purposes. Furthermore, there's deciding happening after the user enters a number or character to navigate the menus and execute funtions etc.

### Iteration

In main.cpp we use a do-while loop to run the program multiple times if the user indicated that they want to run another function. In other words, the user will be prompted with functions to run WHILE their input is not 3 (or the highest number in the list, like 7 if there are 6 functions, in case I add more functions and forget to change this).

### File Input and Output

In the runSearchFunction function, the user inputs a filename of a file (usually html for a website) to check the colors that it uses. That is the input. They would type something like chicoportal.html or w3schools.html. Next, the program searches for the "hot" word, this is the search term, by default assigned to "color:#". It will then output the lines that contain that, and if possible the function will also convert each line to decimal and display it as well as store the RGB color codes. 

### Arrays/Vectors
Arrays and vectors have been used effectively in this program because they enable us to store the colors found in a given file in an easily convertable format. We then read from these vectors later (called redVals, greenVals, and blueVals) if we want to see what colors are stored, and we can convert them to either hex or decimal in the output stream as desired. 

### Functions
Functions have been added to my program, and in a pretty big way. The program gained a main navigation menu through the use of a function, in which it displays other available functions to run for finding and converting colors from files. There are currently 4 functions at the time of writing, with a 5th showing in the menu but currently not doing anything. The active functions so far are chooseMenu, runSearchFunct, editSearchTerm, and readStoredHexOrDec, with a 5th one showing as an option in the menu to be able to tweak the readout length from runSearchFunct to be longer or shorter. So far, adding these functions has greatly improved the overall organization and flow of my code, in my opinion. It's hard to picture this program without the use of functions now. 

### Classes
A class has been added for version 1.0 called analyzer. I think this class is helpful for one main reason, and that is for the ease of organization and programming. I did not need to prototype, define, or call functions with all the many previously required parameters  as many of these parameters have now been added to the analyzer class as member variables, as well as most of the program's functions (with the only exception being the chooseMenu function still being located inside of main.cpp, though main() is still extremely baren and only used to call the other functions). The reason I think that the class is only helful for organization and ease of programming because I am only using the class with one object, analyzer "probe". This object is used when calling all of the member functions because this achieves the organization and lack of the need to call the functions with the previosuly needed parameters as stated above. 

