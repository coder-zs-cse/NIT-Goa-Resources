/*//_______________________________________________________
                                                                            
System Programming Assignment Group Number : 15

Group Members,
        Mandar Manohar Patade - 19CSE1018
        Atharva Vijay Khade   - 19CSE1007
        
Group Topic,
        One Pass Assembler that generates object program

*///_______________________________________________________


#include<bits/stdc++.h>
using namespace std;


//__________________________________OPTAB declaration___________________________

fstream optab;
unordered_map<string,string> umpOPTAB;

//______________________________________________________________________________


//________________________________Conversion Functions__________________________

char convert9thbit(char ch)
{
  char res;    
  if(ch=='0')return '8';
  else if(ch=='1')return '9';
  else 
    return ch+15 ;
}

string intTOhex1(string str)
{
    
    int num = stoi(str);
    int i = num;
    stringstream ss;
    ss << hex << i;
    string res = ss.str();
  
    int val = 6-res.length();
    string temp = "";
    while(val>0)
    {
      temp+="0";
      val--;
    }
    res=temp+res;
  
    for(int i=0;i<res.length();i++)
      if(res[i]<='z'&&res[i]>='a')
          res[i]-=32;
    return res;
    
}
string intTOhex2(string str)
{
    
    int num = stoi(str);
    int i = num;
    stringstream ss;
    ss << hex << i;
    string res = ss.str();
    return res;
    
}
string stohex(string str)
{
  if('0'<=str[0]&&str[0]<='9')
  {
    
    return intTOhex1(str);
      
  }
  else
  {
    string res = "";
    for(int i=0;i<str.length();i++)
    {
        int ascii = str[i];
        string ints = to_string(ascii);
        res = res + intTOhex2(ints);
    }
    int val = 6-res.length();
    string temp = "";
    while(val>0)
    {
      temp+="0";
      val--;
    }
    res=temp+res;
  
    for(int i=0;i<res.length();i++)
      if(res[i]<='z'&&res[i]>='a')
          res[i]-=32;
    return res;
  }
}

string hexADD(string hex_string, string int_string)
{
  
  int number1 = stoi(hex_string, 0, 16);
  int number2 = stoi(int_string);
  int number3 = number1 + number2;
  int i = number3;
  stringstream ss;
  ss << hex << i;
  string res = ss.str();
  
    int val = 4-res.length();
    string temp = "";
    while(val>0)
    {
      temp+="0";
      val--;
    }
    res=temp+res;
  
  for(int i=0;i<res.length();i++)
    if(res[i]<='z'&&res[i]>='a')
        res[i]-=32;
  
  return res;
  
}

//________________________________________________________________________________



//________initializing the OPTAB hash map using the opcode table from the text file

void initOPTAB()
{
  
  optab.open("optab.txt",ios::in);
  
  string line;
  int len = 0;  
  
  while(getline(optab, line))
  {  
    
    string opCode = "";
    string opCodeValue = "";
    
    if(line[0]=='\n')
      return;
    
    len = line.length();

    int i = 0;
    
    // Selecting the Opcode field
    while(line[i]!=' ')
    {  
      if((line[i]>='A' && line[i]<='Z') || (line[i]>='0' && line[i]<='9'))
      {
        opCode = opCode + line[i];
      }
      
      i++;
      
    }
  
    while(line[i]==' ')
        i++;
    
    // Selecting the Opcode Value field
    while(i<len)
    {
      if((line[i]>='A' && line[i]<='Z') || (line[i]>='0' && line[i]<='9'))
      {
        opCodeValue = opCodeValue + line[i];
      }
      
      i++;
    }
    
    // Inserting {opcode : opcode value} in the hash map 
    umpOPTAB.insert({opCode,opCodeValue});
    
  }
  
  optab.close();
  
  return;
  
}

//____________________________________________________________________________________



//_________________________________________Split Line Function__________________________

vector<string> splitLine(string line)
{
  
  vector<string> splittedlines;
  string element="";
  
  int i=0, len = line.length();
  
  while(i<len&&line[i]==' ')
      i++;
      
  while(i<len&&line[i]!=' ')
  {
    element+=line[i];
    i++;
  }  
  
  splittedlines.push_back(element);
  
  while(i<len&&line[i]==' ')
      i++;
      
  if(i==len)
      return splittedlines;
      
  element = "";
  
  while(i<len&&line[i]!=' ')
  {
    element+=line[i];
    i++;
  }  
  
  splittedlines.push_back(element);
  
  if(i==len)
      return splittedlines;
  
  while(i<len&&line[i]==' ')
      i++;
      
  element = "";
  
  while(i<len&&line[i]!=' ')
  {
    element+=line[i];
    i++;
  }  

  splittedlines.push_back(element);
  
  return splittedlines;
  
}

//_______________________________________OnePass Assembler Class_________________________________________________________



class onePassAssembler
{
  
  fstream input;
  fstream output;
  fstream symtab;
  string LOCCTR;
  vector<pair<string,string>> current_line_opcode;
  string program_name;
  string starting_addr; 
  string ProgramStartingAddress;
  string size;
  string E = "E";
  unordered_map< string,pair< string,vector<string> > > umpSYMTAB;
  
  public:
  onePassAssembler(char *filePath);
  ~onePassAssembler();
  void CreateObjectCode();
  void GenerateOutputFile();
  void PrintOutpurFile();
  
};


// opening required files

onePassAssembler::onePassAssembler(char *filePath)
{
  input.open(filePath,ios::in);
  output.open("output.txt");
}

//closing opened files

onePassAssembler::~onePassAssembler()
{
  input.close();
  output.close();
}

// Creating Object Program

void onePassAssembler::CreateObjectCode()
{
  
  bool firstLine = true;
  string Opcode;
  string ObjectCode = "";
  string line;
  
  int count = 1;
  
  while(getline(input, line))
  {
    
    if(line=="\n")
      break;
      
    vector<string> current_line = splitLine(line);
    
    
    // comment line 
    if(current_line[0][0]=='.'){
      count++;
      continue;
    }
    
    if(firstLine)
    {
      // handling first line                                       
      program_name = current_line[0];
      Opcode = current_line[1];
      starting_addr = current_line[2];
      
      program_name = program_name.substr(0,6);
      
      LOCCTR = starting_addr;
      
      firstLine = false;
      
    }
    else if(current_line[0]=="END")
    {
      // handling END line 
      if(umpSYMTAB.find(current_line[1])!=umpSYMTAB.end())
      {
        ProgramStartingAddress = umpSYMTAB[current_line[1]].first;
      }
              
    }
    else
    {
        
            
            
        if(current_line.size()>=2 && current_line[1]=="WORD")
        {
          
          string label = current_line[0];
          string loc = LOCCTR;
          umpSYMTAB.insert({label,pair<string,vector<string>>(loc, {}) });                      
          string three = "3";
                                                    
          string word = current_line[2];
          word = stohex(word);                                                     
          current_line_opcode.push_back(pair<string,string>(word,LOCCTR));    
          
          LOCCTR = hexADD(LOCCTR,three);      
          
        }
        else if(current_line.size()>=2&&current_line[1]=="RESB")
        {
          
          string label = current_line[0];
          string loc = LOCCTR;
          umpSYMTAB.insert({label,pair<string,vector<string>>(loc, {}) });
                                         
          current_line_opcode.push_back(pair<string,string>("",LOCCTR));
          
          LOCCTR = hexADD(LOCCTR,current_line[2]);  
          
        }
        else if(current_line.size()>=2&&current_line[1]=="RESW")
        {
          
          string label = current_line[0];
          string loc = LOCCTR;
          umpSYMTAB.insert({label,pair<string,vector<string>>(loc, {}) });
          int val = stoi(current_line[2]);
          val*=3;
                    
          current_line_opcode.push_back( (pair<string,string>("",LOCCTR) ) );
          
          LOCCTR = hexADD(LOCCTR,to_string(val));   
        }
        else if(current_line.size()>=2&&current_line[1]=="BYTE")
        {
          
          string label = current_line[0];
          string loc = LOCCTR;
          umpSYMTAB.insert({label,pair<string,vector<string>>(loc, {}) });
          string operand = current_line[2];
          
          string byte = current_line[2];
          if(byte[0]=='X')
          {
            current_line_opcode.push_back(pair<string,string>(byte.substr(2,byte.length()-3),LOCCTR)); 
          }
          else 
          {
            byte = stohex(byte.substr(2,byte.length()-3));                     
            current_line_opcode.push_back(pair<string,string>(byte,LOCCTR));
          }
          
          if(operand[0]=='X')
            LOCCTR = hexADD(LOCCTR,"1");              
          else if(operand[0]=='C')                       
          {
            int val = operand.length() - 3;
            LOCCTR = hexADD(LOCCTR,to_string(val));           
          }
          
        }
        else
        {
          int size = current_line.size();
          if(size==3)
          {
            
            string label = current_line[0];
            string opcode = current_line[1];
            string operand = current_line[2];
            string opcode_val = umpOPTAB[opcode];
            string res = opcode_val;
            bool index = false;
            
            if(operand.substr(operand.size()-2,operand.size())== ",X"){
                operand = operand.substr(0,operand.size()-2);
                index = true;
            }
            
              if(umpSYMTAB.find(label)==umpSYMTAB.end())
              {
                umpSYMTAB.insert({label,pair<string,vector<string>>(LOCCTR,{})});
              }
              else
              {
                current_line_opcode.push_back(pair<string,string>("put_new_record",""));
                umpSYMTAB[label].first = LOCCTR;
                for(auto x : umpSYMTAB[label].second)
                {
                  string put = "00"+x+"^"+"02"+"^"+LOCCTR;
                  current_line_opcode.push_back(pair<string,string>(put,LOCCTR));
                }
                current_line_opcode.push_back(pair<string,string>("end_of_new_records",""));
                
                
              }
              
              
                
              if(umpSYMTAB.find(operand)==umpSYMTAB.end())
              {
                //fwd reference
                res+="0000";
                string nul = "";
                umpSYMTAB.insert({operand,pair<string,vector<string>>(nul,{})});
                umpSYMTAB[operand].second.push_back(hexADD(LOCCTR,"1"));
                
              }
              else if(umpSYMTAB[operand].first.length()==0)
              {
                //fwd reference
                res+="0000";
                umpSYMTAB[operand].second.push_back(hexADD(LOCCTR,"1"));
              }
              else
              {
                //no fwd ref
                if(!index)  // no indexed addressing 
                {
                  res+=umpSYMTAB[operand].first;
                }
                else // indexed addressing
                {
                  res+=umpSYMTAB[operand].first;              
                  res[2] = convert9thbit(res[2]);  
                }
              }
            
            current_line_opcode.push_back(pair<string,string>(res,LOCCTR));
            
          }
          else if(size==2)
          {
            string opcode = current_line[0];
            string operand = current_line[1];
            string opcode_val = umpOPTAB[opcode];
            string res = opcode_val;
            bool index = false;
            
            if(operand.substr(operand.size()-2,operand.size())== ",X"){
                operand = operand.substr(0,operand.size()-2);
                index = true;
            }
                
            if(umpSYMTAB.find(operand)==umpSYMTAB.end())
              {
                //fwd reference
                res+="0000";
                string nul = "";
                umpSYMTAB.insert({operand,pair<string,vector<string>>(nul,{})});
                umpSYMTAB[operand].second.push_back(hexADD(LOCCTR,"1"));
                
              }
              else if(umpSYMTAB[operand].first.length()==0)
              {
                //fwd reference
                res+="0000";
                umpSYMTAB[operand].second.push_back(hexADD(LOCCTR,"1"));
              }
              else
              {
                //no fwd ref
                if(!index)  // no indexed addressing 
                {
                  res+=umpSYMTAB[operand].first;
                }
                else // indexed addressing
                {
                  res+=umpSYMTAB[operand].first;              
                  res[2] = convert9thbit(res[2]);      
                }
              }
            
            current_line_opcode.push_back(pair<string,string>(res,LOCCTR));
            
          }
          else 
          {
            current_line_opcode.push_back(pair<string,string>(umpOPTAB[current_line[0]]+"0000",LOCCTR));
          }
          string three = "3";
          LOCCTR = hexADD(LOCCTR,three);  
        }
        

    }
    count++;
    
  }
  cout<<"\n";
    
  int start = stoi(starting_addr,0,16);
  int end = stoi(LOCCTR,0,16);
  int SIZE = end - start;
  string programSize = to_string(SIZE);
  programSize = stohex(programSize);
  size = programSize;
  
  return;
  
}

// Generating the Output 

void onePassAssembler::GenerateOutputFile()
{
  
  string H = "H";
  string T = "T";
  string br = "^";  

  while(program_name.length()<6)
    program_name = program_name + " ";
    
  string headerRecord = H + br + program_name + br + "00" + starting_addr + br + size;
  string endRecord = E + br + "00" + ProgramStartingAddress;

  auto objcode = current_line_opcode.begin(); 
  
  
  output<<headerRecord+"\n";
  
  while(objcode != current_line_opcode.end())
  {
    
    if(objcode->first == "")
    {
      // start new text record 
      while(objcode->first == "")
        objcode++;
        
    }
    
    if(objcode->first == "put_new_record")
    {
      //start new text record 
      // take records until new text record ends
      
      objcode++;
      
      while(objcode->first!="end_of_new_records")
      {
        output<<T+br+objcode->first+"\n";
        objcode++;
      }
      
      objcode++;
      
    }
    
    string strt = "T^00";
    string start_record = strt+objcode->second+br;
    string size;
    string cur_end_record = "";
    int count = 0;
    bool take_last_record = true;
    
    while(count<30)
    {
      
      if(objcode->first.length()==6)
        count+=3;
      else if(objcode->first.length()==4)
        count+=2;  
      else
        count+=1;
        
        
      
      if(count<=30)
        cur_end_record +=(objcode->first + br);
      else 
        break;
    
      objcode++;
      
      
      if(objcode->first=="" || objcode->first=="put_new_record")
      {
        take_last_record = false;
        stringstream stream;
        stream << hex << count;
        string result( stream.str() );
        size = result;
        
        for(int i=0;i<size.length();i++)
          if(size[i]>='a'&&size[i]<='z')
            size[i]-=32;
      
        if(size.length()>2)
           size = size.substr(size.length()-2,size.length());
      
         if(size.length()==1)
          size = "0"+size;
          //Put record in file 
          string final_record = start_record+size+br+cur_end_record;
          final_record = final_record.substr(0,final_record.length()-1);
          output<<final_record+"\n";
          break;
          
      }
      
    }
    
    if(take_last_record)
      {
        count-=3;
        stringstream stream;
        stream << hex << count;
        string result( stream.str() );
        size = result;
        
        for(int i=0;i<size.length();i++)
          if(size[i]>='a'&&size[i]<='z')
            size[i]-=32;
            
        if(size.length()>2)
           size = size.substr(size.length()-2,size.length());
      
         if(size.length()==1)
          size = "0"+size;
          //Put record in file 
          string final_record = start_record+size+br+cur_end_record;
          final_record = final_record.substr(0,final_record.length()-1);
          output<<final_record+"\n";
          
      }
    
  }
  
  output<<endRecord+"\n";
  
  return;
  
}

//Printing the output file generated

void onePassAssembler::PrintOutpurFile()
{
  
  cout<<"____________________________________________________________________________________________________________________\n\n";
  output.close();
  output.open("output.txt");
  string line;
  while(getline(output,line))
  {
    if(line=="\n")
      break;
    cout<<line<<"\n";
  }
  cout<<"____________________________________________________________________________________________________________________\n";
  
  return;
  
}

// Main function

int main(int argc,char *argv[])
{
  
  if(argc!=2)
  {
    // error check in giving file path and name
    printf("Please Enter Valid file path as input\n");
  }
  else
  {
    
    // initializing the optab
    initOPTAB();

    // creating onepass assembler to convert assembly level code into object program
    onePassAssembler Assembler(argv[1]);
    
    // creating the object code program
    Assembler.CreateObjectCode();
    
    // generating the output file as well as printing on terminal/console
    Assembler.GenerateOutputFile();
    
    Assembler.PrintOutpurFile();
    
  }
  
  return 0;
  
}

