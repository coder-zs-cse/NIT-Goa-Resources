<<<<<<< HEAD
OPTAB = {"ADD": "18", "COMP": "28", "DIV": "24", "J": "3C",
         "JEQ":"30", "JGT": "34", "JLT": "38", "JSUB": "48", 
         "LDA": "00", "LDCH": "50", "LDL": "08", "LDX": "04",
         "MUL": "20", "OR": "44", "RD": "D8", "RSUB": "4C", 
         "STA": "0C", "STCH": "54", "STL": "14", "STSW": "E8",
         "STX": "10", "SUB": "1C", "TD": "E0", "TIX": "2C", "WD": "DC"}

with open("input.txt", "r") as file:
    data = file.readlines()
=======
from OpTable import OPTAB

def TR_size(cur):
    return (len(cur)-7-cur.count("^"))//2

def init_current(addr):
    return "T^00"+addr+"^" 
>>>>>>> 4b8a6490ff3cdd1a70dca717cff81bcfff8fcc21
    
def final_current(curr):
    length = str.upper(str(hex(TR_size(curr))))[2:].zfill(2)
    return curr[:9] + length + curr[9:] + "\n"

def update_loc(loc, n, bytes):
    size = int(n)*bytes
    return str(hex(int(loc, 16) + size)[2:])

<<<<<<< HEAD
file = open("output.txt", "w+")

current = ""

for line in data:
    words = line.split()
    if(words[0] == "."):
        continue
    
    if len(words) > 1 and words[-2] not in ["RESW", "RESB"] and current == "":
        current = "T^00"+loc.upper()+"^" 
=======
def add_to_forRef(fR, key, addr):
    if key in fR:
        fR[key].append(str.upper(str(hex(int(addr,16)+1))[2:]))
    else:
        fR[key] = [str.upper(str(hex(int(addr,16)+1))[2:])]
    
    return fR
 
def write_to_file(curr, f):
    f.write(final_current(curr)) 

if __name__ == "__main__":
    
    with open('input.txt', 'r') as file:
        data = file.readlines()
>>>>>>> 4b8a6490ff3cdd1a70dca717cff81bcfff8fcc21
        
    loc = data[0].split()[-1]
    start  = loc
        
    labels = {}
    forRef = {}
    current = ""

    file = open("output.txt", 'w+')

    for line in data:
        words = line.split()
        if(words[0] == '.'):
            continue
        
        if len(words) > 1 and words[-2] not in ['RESW', 'RESB'] and current == "":
            current = init_current(loc.upper())
            
        if len(words) == 3: # add label and address
            
            if words[0] in forRef.keys():
                write_to_file(current, file)
                for objc in forRef[words[0]]:
                    current = init_current(objc) + "02^" + loc.upper()
                    file.write(current + "\n")
                    
                del forRef[words[0]]
                current = init_current(loc.upper())

            labels[words[0]] = loc.upper()
        
        if len(words) == 1: # for RSUB
            if TR_size(current) + 3 > 30:
                write_to_file(current, file)
                current = init_current(loc.upper())
                continue
                
            current += "^" + OPTAB[words[-1]] + '0000'
            loc = update_loc(loc, 1, 3)
            continue
        
        # Handle the case of buffer and array lengths
        if words[-2] == 'START' or words[-2] == 'END':
            
            if words[-2] == 'START':
                current = 'H^' + words[0][:6]
                if(len(words[0])<6):
                    current += (" ")*(6-len(words[0]))
                current += ("^00" + loc.upper())*2
                    
                file.write(current + "\n")
<<<<<<< HEAD
                
            del forRef[words[0]]
            current = "T^00"+loc.upper()+"^"

        labels[words[0]] = loc.upper()
    
    if len(words) == 1: # for RSUB
        objCode[loc.upper()] = OPTAB[words[-1]] + "0000"        
        current += "^" + objCode[loc.upper()]
        loc = str(hex(int(loc, 16) + 3)[2:])
        continue
    
    # Handle the case of buffer and array lengths
    if words[-2] == "START" or words[-2] == "END":
        
        if words[-2] == "START":
            current = "H^"
            if(len(words[0])<6):
                current += words[0] + (" ")*(6-len(words[0]))
                current += "^00" + loc.upper() + "^00" + loc.upper()
                
            file.write(current+"\n")
            current = ""
        
        if words[-2] == "END":
            labels[words[-2]] = loc.upper()
            length_TR = str.upper(str(hex((len(current)-7-current.count("^"))//2))[2:].zfill(2))
            current = current[:9] + length_TR + current[9:]
            file.write(current+"\n")
            current = "E^00" + labels[words[-1]] + "\n"
            file.write(current)
        continue
    
    if words[-2] in ["RESW", "RESB"] and current != "":
        length_TR = str.upper(str(hex((len(current)-7-current.count("^"))//2))[2:].zfill(2))
        current = current[:9] + length_TR + current[9:]
        file.write(current+ "\n")
        current = ""
    
    if words[-2] == "RESW":
        size = int(words[-1])*3
        loc = str(hex(int(loc, 16) + size)[2:]) 
    
    elif words[-2] == "RESB":
        size = int(words[-1])
        loc = str(hex(int(loc, 16) + size)[2:])
    
    elif words[-2] == "BYTE":
        if words[-1][0]=="C":
            objCode[loc.upper()] = "".join([hex(ord(x))[2:] for x in words[-1][2:-1]]).upper() 
            current += "^" + objCode[loc.upper()]    
            loc = str(hex(int(loc, 16) + 3)[2:])
        else:
            objCode[loc.upper()] = str.upper(words[-1][2:-1])
            current += "^" + objCode[loc.upper()]    
            loc = str(hex(int(loc, 16) + 1)[2:])
    
    elif words[-2] != "START":
        
        if words[-2] == "WORD":
            objCode[loc.upper()] = str(hex(int(words[-1])))[2:].zfill(6)
            current += "^" + objCode[loc.upper()]    
        else:
            if "," in words[-1]:
                if words[-1][:-2] in labels:
                    current += "^" + OPTAB[words[-2]] + str(int(labels[words[-1][:-2]][0]) | 8 ) + labels[words[-1][:-2]][1:]
                else:
                    if words[-1][:-2] in forRef:
                        forRef[words[-1][:-2]].append(str.upper(str(hex(int(loc,16)+1))[2:]))
                    else:
                        forRef[words[-1][:-2]] = [str.upper(str(hex(int(loc,16)+1))[2:])]
                    objCode[loc.upper()] = OPTAB[words[-2]] + "8000"
                    current += "^" + objCode[loc.upper()]   

            elif words[-1] in labels:
                current += "^" + OPTAB[words[-2]] + str(int(labels[words[-1]][0]) & 7 ) + labels[words[-1]][1:]
                
            else:
                if words[-1] in forRef:
                    forRef[words[-1]].append(str.upper(str(hex(int(loc,16)+1))[2:]))
                else:
                    forRef[words[-1]]= [str(hex(int(loc,16)+1))[2:].upper()]
                
                objCode[loc.upper()] = OPTAB[words[-2]] + "0000"
                current += "^" + objCode[loc.upper()]    
        
        loc = str(hex(int(loc, 16) + 3)[2:])
    
    # file.write(wline+"\n")
    # current += "^" + objCode[loc.upper()]
        
# print(labels)
# print("Object Code: ", objCode)
# print("Forward References: ", forRef)
=======
                current = ""
            
            if words[-2] == 'END':
                labels[words[-2]] = loc.upper()
                write_to_file(current, file)
                current = "E^00" + labels[words[-1]] + "\n"
                file.write(current)
            continue
        
        if words[-2] in ["RESW", "RESB"] and current != "":
            write_to_file(current, file)
            current = ""
        
        if words[-2] == 'RESW':
            loc = update_loc(loc, words[-1], 3)  
        
        elif words[-2] == 'RESB':
            loc = update_loc(loc, words[-1], 1)
            
        elif words[-2] == 'BYTE':
            if words[-1][0]=='C':
                if TR_size(current) + 3 > 30:
                    write_to_file(current, file)
                    current = init_current(loc.upper())
                        
                current += "^" + ''.join([hex(ord(x))[2:] for x in words[-1][2:-1]]).upper()    # generate Object code from the the ASCII equivalent of the character
                loc = update_loc(loc, 1, 3)  
                
            else:
                if TR_size(current) + 1 > 30:
                    write_to_file(current, file)
                    current = init_current(loc.upper())
                        
                current += "^" + str.upper(words[-1][2:-1])    
                loc = update_loc(loc, 1, 1)
        
        elif words[-2] != 'START':
            if TR_size(current) + 3 > 30:
                write_to_file(current, file)            
                current = init_current(loc.upper())
            
            if words[-2] == 'WORD':
                current += "^" + str(hex(int(words[-1])))[2:].zfill(6)    
            else:
                if ',' in words[-1]:
                    if words[-1][:-2] in labels:
                        current += '^' + OPTAB[words[-2]] + hex(int(labels[words[-1][:-2]],16) | int("8000",16))[2:].zfill(4).upper()
                    else:
                        forRef = add_to_forRef(forRef, words[-1][:-2], loc)
                        current += "^" + OPTAB[words[-2]] + "8000"   
>>>>>>> 4b8a6490ff3cdd1a70dca717cff81bcfff8fcc21

                elif words[-1] in labels:
                    current += '^' + OPTAB[words[-2]] + hex(int(labels[words[-1]],16) & int("7FFF",16))[2:].zfill(4).upper()    
                    
                else:
                    forRef = add_to_forRef(forRef, words[-1], loc)
                    current += "^" + OPTAB[words[-2]] + '0000'    
                
            loc = update_loc(loc, 1, 3)

<<<<<<< HEAD
file.write(current)
file.close()
=======
    end = loc
    file.seek(0)
    file.seek((file.readline()).rindex("^")+1)
    current = str(hex(int(end,16) - int(start,16)))[2:].upper().zfill(6)
>>>>>>> 4b8a6490ff3cdd1a70dca717cff81bcfff8fcc21

    file.write(current)
    file.close()
