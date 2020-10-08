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

!!!Replace with a summary and examples of how input and output have been used effectively and appropriately!!!

### Decisions

!!!Replace with a summary and examples of how multiple decision constructs have been used effectively and appropriately!!!

### Iteration

ex: a do while loop for gathering input that is within bounds

### File Input and Output

!!!Replace with a summary and examples of how input and/or output of files have been used effectively and appropriately!!!