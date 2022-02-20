import cs50
import csv
from sys import argv, exit
import re


if len(argv) != 2:
    print("missing command-line argument")
    exit(1)

db = cs50.SQL("sqlite:///students.db")

# open file 
with open(argv[1], "r") as csvfile:
    # read file
    reader = csv.DictReader(csvfile) 
    for row in reader:
        # check if there is middle name
        splitname = re.split(" ", row["name"])
        if len(splitname) == 2:
            db.execute("INSERT INTO students(first, last, house, birth) VALUES (?, ?, ?, ?)",
                       splitname[0], splitname[1], row["house"], row["birth"])
        else:
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       splitname[0], splitname[1], splitname[2], row["house"], row["birth"])
