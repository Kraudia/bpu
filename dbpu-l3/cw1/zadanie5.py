from sys import argv

script, filename = argv
text = "darek"

def search(line, text):
	contain = 0
	for i in range(0, len(line)-1):
		if (line[i] == text[0]):
			j = 1
			while (j < len(text)):
				if (line[i+j] != text[j]):
					j -= 1
					break	
				j += 1 
			if (j == len(text)):
				contain = 1
				break
	return contain

with open(filename, "r") as ins:
    for line in ins:
		if (search(line, text)):
			print line,
