from sqlite3 import ProgrammingError


obj_prog = []
program_name = "hello"
starting_address = "there"
obj_prog.append("H^" + program_name + starting_address)
obj_prog[0] = obj_prog[0] + "^1001"
obj_prog.append("H^" + program_name + starting_address)
print(obj_prog)
