def labelDict(data):
    labels = {}
    
    for line in data:
        words = line.split()
        if(words[0] == '.'):
            continue
        
        if len(words) == 3: # add label and address
            labels[words[0]] = str.upper(loc)
        
        if len(words) == 1: # for RSUB
            loc = str(hex(int(loc, 16) + 3)[2:])
            continue
        
        # Handle the case of buffer and array lengths
        if words[-2] == 'RESW':
            size = int(words[-1])*3
            loc = str(hex(int(loc, 16) + size)[2:]) 
        
        elif words[-2] == 'RESB':
            size = int(words[-1])
            loc = str(hex(int(loc, 16) + size)[2:])
        
        elif words[-2] != 'START' and words[-2] != 'BYTE':
            loc = str(hex(int(loc, 16) + 3)[2:])
        
        elif words[-2] == 'START':
            continue
        
        elif words[-2] == 'BYTE':
            if words[-3] == 'EOF':
                loc = str(hex(int(loc, 16) + 3)[2:])
            else:
                loc = str(hex(int(loc, 16) + 1)[2:])

    print(labels)  

