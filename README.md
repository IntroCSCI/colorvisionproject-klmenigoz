# Color Accessibility Checker

## Description

Pull the color values from the imported website code provided by the user. These color values will be hexadecimal from the html code, or simply stated like "mediumblue." Our end goal is to be able to analyze numerous colors at once and determine any possible combinations of colors that may be problematic for some people with colorblindness. We would then tell the user, probably a website developer checking if their website is generally color-accessable, if it was or wasn't. If not, we'd like to tell them more specificly what the problematic combination was. eg. red-green colorblindness

## Developer

Kent Menigoz

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp

w3schools.html [Enter]
```

Here is an example of the program running:

```
color:mediumblue}
color:brown}
color:red}
color:mediumblue}
color:green}
color:brown}
color:red}
color:mediumblue}
color:black}
color:red}  
color:black}
color:mediumblue}
color:brown}
color:red}
color:black}
color:black}
color:mediumblue}

//Future plans include further analysis output regarding 
//compatibility and general Accessibility
```

## C++ Guide

### Variables and Data Types

integers: for R, G, and B values, because these are represented by whole numbers 0 to 255. 
          also, int for the line number of the file opened, as well as .find output recording 
character: the choice (y/n) for repeated file analysis
fstream: for reading the file
string: for recording the input file name, and for "text" and "colorInfo" while searching           for the "hot" term


### Input and Output

There is input and output in main.cpp becase we first cout the main question, for the user to enter a filename to analyze. There is input in the following line where we gather that information. There is also some output if there is an error, as well as when deciding to repeat the loop and analyze another file, where we cout the question, and cin the decision right after (y/n). 

### Decisions

The program makes descisions when trying to find text with "color:" because it checks to see if the file opened before doing anything else. IF the file is open, it will go line by line searching for the "hot" search term variable assigned to "color:" as long as the reader has not reached the end of the file. In future versions we plan to use descisions to analyze color combinations for accessability purposes. 

### Iteration

In main.cpp we use a do-while loop to run the program multiple times if the user indicated that they want to analyze another file for color names and compatibility.

### File Input and Output

The user inputs a filename of a file (usually html for a website) to check the colors that it uses. That is the input. They would type something like chicoportal.html or w3schools.html. Next, the program searches for the "hot" word, this is the search term, on this case assigned to search for "color:". It will then output the colors in a list like
color:#fefefe or color:mediumblue}