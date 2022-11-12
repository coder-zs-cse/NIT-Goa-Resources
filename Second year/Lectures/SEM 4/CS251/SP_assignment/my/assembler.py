OPTAB = {'ADD': '18', 'COMP': '28', 'DIV': '24', 'J': '30',
         'JEQ':'30', 'JGT': '34', 'JLT': '38', 'JSUB': '48', 
         'LDA': '00', 'LDCH': '50', 'LDL': '08', 'LDX': '04',
         'MUL': '20', 'OR': '44', 'RD': 'D8', 'RSUB': '4C', 
         'STA': '0C', 'STCH': '54', 'STL': '14', 'STSW': 'E8',
         'STX': '10', 'SUB': '1C', 'TD': 'E0', 'TIX': '2C', 'WD': 'DC'}

with open('input.txt', 'r') as file:
    data = file.readlines()

if data[0].split()[-2] == "START":
    starting_address = data[0].split()[-1]
    LOCCTR = starting_address
else:
    LOCCTR = "".zfill(4)
    

program_name = data[0].split()[0]
while len(program_name)<6:
    program_name += " "
objCode = {}
labels = {}
backRef = {}
obj_prog = []
program_length = ""
obj_prog.append("H^" + program_name + "^" + starting_address)
for line in data:
    current = line.split()
    if current[0]=='.':
        continue
    if len(current)==3:
        labels[current[0]] = LOCCTR

    if len(current)==1: # handling edge case for RSUB
        objCode[LOCCTR] = OPTAB[current[0]] + "0000"
        LOCCTR = str(hex(int(LOCCTR,16) + 3)[2:]).upper()
    elif current[-2] == "RESB":
        LOCCTR = str(hex(int(LOCCTR,16) + int(current[2]))[2:])
    elif current[-2] == "RESW":
        LOCCTR = str(hex(int(LOCCTR,16) + 3*int(current[2]))[2:])
    elif current[-2] == "BYTE":
        if current[-1][0] == 'C':
            objCode[LOCCTR] =  ''.join(map(lambda c : str(hex(ord(c))[2:]).upper(), current[-1][2:-1]))
            LOCCTR = str(hex(int(LOCCTR,16)+ 3)[2:])
        elif current[-1][0] == 'X':
            objCode[LOCCTR] = current[-1][2:-1]
            LOCCTR = str(hex(int(LOCCTR,16)+ 1)[2:])
    elif current[-2]=="START" or current[-2]=="END":
        if current[-2] == "END":
            program_length = str(hex(int(LOCCTR,16) - int(starting_address,16))[2:].upper())
    elif current[-2]=="WORD":
        objCode[LOCCTR] = hex(int(current[-1]))[2:].zfill(6)  #adds leading zeroes 
        LOCCTR = str(hex(int(LOCCTR,16) + 3)[2:])
    else:
        operand = ""
        if ",X" in current[-1]:
            operand = current[-1][:-2]
        else:
            operand = current[-1]

        if operand in labels.keys():
            objCode[LOCCTR] = OPTAB[current[-2]] + labels[operand]
        else:
            if operand in backRef.keys():
                backRef[operand].append(hex(int(LOCCTR,16)+1)[2:].upper())
            else:
                backRef[operand] = [hex(int(LOCCTR,16)+1)[2:].upper()]
            objCode[LOCCTR] = OPTAB[current[-2]] + "0000"

        if ',X' in current[-1]:
            objCode[LOCCTR]= objCode[LOCCTR][:2] + str(int(objCode[LOCCTR][2]) | 8) + objCode[LOCCTR][3:]
        else:
            objCode[LOCCTR]= objCode[LOCCTR][:2] + str(int(objCode[LOCCTR][2]) & 7) + objCode[LOCCTR][3:]
            
        LOCCTR = str(hex(int(LOCCTR,16) + 3)[2:])
    

for key, value in labels.items():
    print(value.upper(), key.upper())
print()
for key, value in objCode.items():
    print(key.upper(),value.upper())
print()
for key, value in backRef.items():
    print(key.upper(),value)

print(program_length)


            