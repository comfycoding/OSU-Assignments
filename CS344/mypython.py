# mypython.py uses python3 !!!
# CS344 Winter 2017
# Darlene Zouras

import string
import random

# This function is used to create each of the files,
# generate 10 random lowercase letters,
# and then close the files.
def writeFile(fileName):
    writeThis = open(fileName, "w+")
    randString=""
    # The following for loop generates 10 lowercase characters.
    for i in range(10):
        randString+=random.choice(string.ascii_lowercase)
    randString+="\n"
    writeThis.write(randString)
    writeThis.close()

# Run the function for each of the three files.
writeFile("pyfile1")
writeFile("pyfile2")
writeFile("pyfile3")

# And then open them to read!
def readFile(fileName):
    readThis = open(fileName, "r")
    print(readThis.read(), end="")
    readThis.close()

readFile("pyfile1")
readFile("pyfile2")
readFile("pyfile3")

# After the files are created, generate two random integers
randInt1 = random.randint(1,42)
randInt2 = random.randint(1,42)
# Then print them as well as their product.
print(randInt1)
print(randInt2)
print(randInt1*randInt2)
