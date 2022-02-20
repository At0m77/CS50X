from cs50 import get_int

# prompt the user for positive number
while True:
    height = get_int("Height: ")
    if height > 0 and height <= 8:
        break


# bild pyramid of height "height"
# calling of function at line 30
def bild(h):

    # recursion conditon
    if (h == 0):
        return

    # calling the function again to cause recursion
    bild(h - 1)

    # print the pyramid
    print(" " * (height - h), end='')
    print("#" * h, end='')
    print("  ", end='')
    print("#" * h)


# calling the bild function

bild(height)