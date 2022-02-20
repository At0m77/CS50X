from cs50 import get_string, get_int
import re

# prompt the user for a code
number = get_string("Number: ")
numberlen = len(number)
check = 0

# add the digit from second-to-last digit increase steps bn 2
# number[satrt:end:steps]
for i in number[numberlen - 2::-2]:
    i = int(i) * 2
    for x in str(i):
        check += int(x)

# add the remaning digits for check
for n in number[::-2]:
    check += int(n)

# check if card is valid or not
if check % 10 == 0:
    if re.search("^4", number) and numberlen == (16 or 13):
        print("VISA")
    elif re.search("^((5)[12345])", number) and numberlen == 16:
        print("MASTERCARD")
    elif re.search("^((3)(4|7))", number) and numberlen == 15:
        print("AMEX")
    else:
        print("INVALID")

else:
    print("INVALID")
