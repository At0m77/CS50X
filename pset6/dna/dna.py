from sys import exit, argv
import csv
import re


if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)
else:
    # stor all possible STRs
    STRs = {"AGATC": 0, "TTTTTTCT": 0, "AATG": 0, "TCTAG": 0, "GATA": 0, "TATC": 0, "GAAA": 0, "TCTG": 0}

    # open database
    with open(argv[1], "r") as datafile:
        datareader = csv.DictReader(datafile)

        # open sequanes file, read it and store its information
        with open(argv[2], "r") as seqfile:
            for STR in STRs:
                lonseq = max(re.findall(rf"(?:{STR}(?:(?:{STR})+)?)*", seqfile.read()))  # find the longest sequence
                STRs[STR] = (int(len(f"{lonseq}") / len(f"{STR}")))  # store its value in dictionary
                seqfile.seek(0)  # return to the start of the file

        # check if the dna matches database
        for data in datareader:  # itirate over database
            common = STRs.keys() & data.keys()  # find the commen "STR" in both sequence and database
            check = len({STR: data[STR] for STR in common if int(data[STR]) == int(STRs[STR])})  # find count of matching STRs
            if check == len(common):
                print(data["name"]) 
                exit(0)  # exit if the name is found 
    print("No match")  # print if the name was not found 
                