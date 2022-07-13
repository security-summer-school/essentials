import base64

text = flag = open("tommys_art_project.txt","r").read()
text = (base64.b64decode(text.encode('ascii'))).decode('ascii')

ascii_list = []
a = 0

for line in text:
    for x in line:
        if x.isdigit() == True:
            a = a * 10 + int(x)
        if x == ' ' or x == '#':
            if a != 0:
                ascii_list.append(a)
                a = 0

solution = []

for x in ascii_list:
    solution.append(chr(x))

for x in solution:
    print(x, end="")
