from cs50 import get_string
import re


# prompt the youser for some text
text = get_string("Text: ")

# calculate the number of letter, words and sentences
lettercount = len(re.findall(r'\w', text))

wordcount = len(re.findall(r"\s+", text)) + 1

# this is anothe way to calculate the number of word
# but i think it's slower ---
# --> "wordcount = len(re.findall(r"\w+('\w+|-\w+)?", text))" 
sentcount = len(re.findall(r'[?.!]', text))

# calculating the average
l = lettercount / wordcount * 100
s = sentcount / wordcount * 100

# calculating the Coleman-Liau index.
index = round(0.0588 * l - 0.296 * s - 15.8)

# print Grade
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
