# How to use
- **load** can be used to load in a text file of commands or load in a file as a puzzle object following this syntax: load {NAMEOFFILE}.txt as {PUZZLENAME}
- **new** creates a new empty puzzle if one with name doesn't already exist
- **display** displays all puzzles if no other argument given, if puzzle name given displays contents of puzzle i.e. the card objects in the puzzle
- **remove** deletes the puzzle specified like: remove {PUZZLENAME}
- **add** adds a card to a specifed puzzle following this syntax: add {1GOO} to puzzle1
- **test** tests two given cards to find the card that will make a set with it and prints it out
- **sovle** solves a puzzle: solve {PUZZLENAME}
- **exit** closes the CLI program
# Card Formatting 
Cards are formatted in the program following this sequence
{Number of shapes}{Color of the shape}{Fill style of the shape}{The actual shape name}
# Attributes 
Each of these attributes besides the number are represented by the first letter of the attribute
- There are three possible different numbers: 1,2 or 3 of a shape
- There are three possible different colors: red, purple, or green
- There are three possible different fill styles: open, filled, or striped
- There are three possible different shapes: diamond, oval, or squiggle
# Example Cards 
1GOO = 1 Green Open Oval 
3RFD = 3 Red Filled Diamonds
2PSS = 2 Purple Striped Squiggles
# Setting up a puzzle.txt file
To set up a puzzle.txt all you need to do is go to the https://www.setgame.com/set/puzzle  and using the formatting up above enter all the cards shown into a text file seperating them by a single space and saving the 
.txt in the same directory as the executable. Additonally you can also do four in a line and go to the next line 
to make the text representations of the cards match with the layout on the webiste.
Then load the puzzle.txt as a puzzle of a specified name and use the solve command to solve the puzzle.
