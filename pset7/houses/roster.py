import cs50
from sys import argv, exit

if len(argv) != 2:
    print("missing command-line argument")
    exit(1)

# open database & query for student
db = cs50.SQL("sqlite:///students.db")
students = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last,first", argv[1])

# check if there is middle name of not
for i in range(len(students)):
    if students[i]['middle'] == None:
        print(f"{students[i]['first']} {students[i]['last']}, born {students[i]['birth']}")
    else:
        print(f"{students[i]['first']} {students[i]['middle']} {students[i]['last']}, born {students[i]['birth']}")