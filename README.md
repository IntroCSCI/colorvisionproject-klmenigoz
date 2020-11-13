# Color Accessibility Checker

## Description

Pull the color values from the imported website code provided by the user. These color values will be hexadecimal from the html code, or simply stated like "mediumblue." Our end goal is to be able to analyze numerous colors at once and determine any possible combinations of colors that may be problematic for some people with colorblindness. We would then tell the user, probably a website developer checking if their website is generally color-accessable, if it was or wasn't. If not, we'd like to tell them more specificly what the problematic combination was. eg. red-green colorblindness. Other members of the group are designing tests using inputted colors like the ones obtained from websites in this program's code to determine possible color accessability issues the user might have with the website. 

# v0.2 Updates

In the v.0.2 update, I've added numerous functions, as well as converted old functionality that was coded in main() to be removed from there and instead be used in dedicated funcions. On top of adding functions, this deliverable's main goal was to be able to convert and store the hexadecimal color values from the .html files imported. This was achieved in two of the functions I added. The first was simply improving the readout for the color searching function to read out part of the line with the hex value, but also to convert the hex value and print it in 3 decimal values below. Also, these indivual color values would be stored in vectors called redVals, greenVals, and blueVals. 


## Developer

Kent Menigoz

## Example

To run the program, give the following commands:
  1)FIRST: when the menu prompts, type 1 and press enter,
  2) doing (1) will open the file search function, so now enter a filename. try "w3schools.html"
  3) the function will now search and display lines that contain the search term, as well as display the color values in hex and underneith in decimal if possible, and store them in vectors for each RGB
  4) once the search function has been run (at elast) once, we can read from the stored colors by typing 4 and pressing eter at the menu
  5) once running the readStoredHexOrDec function by entering 4 at the menu, we can enter h/H or d/D to read the stored color values in either hex or decimal. 
  
``` 
EXAMPLE 1
 Menu
------
(1) Open a new file
(2) Edit search term
(3) Adjust colorInfo readout length
(4) Read some stored hex or decimal colors (run once first)
(5) Quit program
1  [Enter]

Enter a file name to check its colors
w3schools.html  [Enter]


EXAMPLE 2
 Menu
------
(1) Open a new file
(2) Edit search term
(3) Adjust colorInfo readout length
(4) Read some stored hex or decimal colors (run once first)
(5) Quit program
4  [Enter]
Read Hex or Dec? (H/D)
d  [Enter]


EXAMPLE 3
 Menu
------
(1) Open a new file
(2) Edit search term
(3) Adjust colorInfo readout length
(4) Read some stored hex or decimal colors (run once first)
(5) Quit program
4  [Enter]
Read Hex or Dec? (H/D)
h  [Enter]
```

Here is an example of the program running:

```
EXAMPLE 1 (partial displayed line with search term and converted decimal value)
line 16, found...
color:#4CAF50
76,175,80


line 23, found...
color:#ffffff
255,255,255


line 24, found...
color:#555555
85,85,85


line 31, found...
color:#fff}
 ^Bad....skipped!



EXAMPLE 2 (stored RGB decimal readout)
76,175,80

255,255,255

85,85,85



EXAMPLE 3 (stored RGB hex readout)
0x4caf50

0xffffff

0x555555

0x4caf50
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