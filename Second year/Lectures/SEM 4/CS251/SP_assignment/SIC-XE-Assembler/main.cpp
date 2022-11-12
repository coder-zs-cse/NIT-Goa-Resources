#include<iostream>
#include "r.h"
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
class Assembler
{
public:
  unordered_map<string,string> OPTAB;
  unordered_map<string,string> SYMTAB;
  unordered_map<string,string>REGISTER;
  unordered_map<string,string>SYMDEF;
  string LOCCTR,PROG_NAME,start_add;
  vector<string> INTER_FILE;
  string base;
  int adct;
  unordered_map<char,int> hexequi;
  vector<string> ADDRESS;
  vector<string> TEXTREC;
  vector<string> MREC;
  Assembler()
  {
    adct=0;
    LOCCTR="";
    REGISTER["A"]="0";
    REGISTER["X"]="1";
    REGISTER["L"]="2";
    REGISTER["PC"]="8";
    REGISTER["SW"]="9";
    REGISTER["B"]="3";
    REGISTER["S"]="4";
    REGISTER["T"]="5";
    REGISTER["F"]="6";

  }
  void hexequi_generate();
  void pass_one();
  void display_inter_file();
  void display_symbol_table();
  void generate_OPTAB();
  void pass_two();
};
void Assembler::display_symbol_table()
{
  for(auto t:SYMTAB)
  {
    cout<<t.first<<"        "<<t.second<<endl;
  }
}
void Assembler::generate_OPTAB()	//create_OPTAB()
{
  //Mnemonic hash table
      OPTAB[(string)"ADD"]=(string)"18";
  OPTAB[(string)"ADDR"]=(string)"58";
  OPTAB[(string)"CLEAR"]=(string)"B4";
  OPTAB[(string)"COMP"]=(string)"28";
  OPTAB[(string)"COMPR"]=(string)"A0";
  OPTAB[(string)"J"]=(string)"3C";
  OPTAB[(string)"JEQ"]=(string)"30";
  OPTAB[(string)"JLT"]=(string)"38";
  OPTAB[(string)"JSUB"]=(string)"48";
  OPTAB[(string)"LDA"]=(string)"00";
  OPTAB[(string)"LDB"]=(string)"68";
  OPTAB[(string)"LDCH"]=(string)"50";
  OPTAB[(string)"LDT"]=(string)"74";
  OPTAB[(string)"RD"]=(string)"D8";
  OPTAB[(string)"RSUB"]=(string)"4C";
  OPTAB[(string)"STA"]=(string)"0C";
  OPTAB[(string)"STCH"]=(string)"54";
  OPTAB[(string)"STL"]=(string)"14";
  OPTAB[(string)"STX"]=(string)"10";
  OPTAB[(string)"TD"]=(string)"E0";
  OPTAB[(string)"TIXR"]=(string)"B8";
  OPTAB[(string)"WD"]=(string)"DC";

}
void Assembler::hexequi_generate()
{
  hexequi['0']=0;
  hexequi['1']=1;
  hexequi['2']=2;
  hexequi['3']=3;
  hexequi['4']=4;
  hexequi['5']=5;
  hexequi['6']=6;
  hexequi['7']=7;
  hexequi['8']=8;
  hexequi['9']=9;
  hexequi['A']=10;
  hexequi['B']=11;
  hexequi['C']=12;
  hexequi['D']=13;
  hexequi['E']=14;
  hexequi['F']=15;
}
void Assembler::pass_one()
{
  vector<string> tokens;
  string s="";
  ifstream fp("Input.txt",ios::in|ios::binary);
  ofstream interf("INTERMEDIATE_FILE.txt",ios::out);
  ofstream sym("SYMDEF.txt",ios::out);
  ofstream opf("SYMTAB.txt",ios::out);
  // for(auto sttt:SYMTAB)
  // cout<<sttt.first<<sttt.second<<endl;
  while(!fp.eof())
  {

    s="";
    string st;
    getline(fp,s,'\n');
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    tokens=split_into_3(s);
    // cout<<s;
    // cout<<endl;
    if(tokens.size()!=1 && tokens[1]=="RSUB")
    {
      st="";
      st=LOCCTR+add_space(LOCCTR.length(),10)+s;
      interf<<st;
      interf<<"\n";
      ADDRESS.push_back(LOCCTR);
      LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+3);
      continue;
    }
    if(tokens.size()==3 && tokens[1]=="BASE")
    {
      st="";
      base=tokens[2];
      st=add_space(0,10)+s;
      interf<<st;
      interf<<"\n";
      ADDRESS.push_back(" ");
      continue;
    }
    if(tokens.size()==3 && tokens[1]=="END")
    {
      st="";
      st=LOCCTR+add_space(LOCCTR.length(),10)+s;
      interf<<st;
      interf<<"\n";
      ADDRESS.push_back(LOCCTR);
      break;
    }
    if(tokens.size()==3 && tokens[1]=="START")
    {
      PROG_NAME=tokens[0];
      start_add=tokens[2];
      LOCCTR=tokens[2];

      st="";
      st=LOCCTR+add_space(LOCCTR.length(),10)+s;
      interf<<st;
      interf<<"\n";
      ADDRESS.push_back(LOCCTR);
      continue;
    }







    if(tokens[0]!=".")
    {
      //CREATING INTERMEDIATE FILE
      string st="";
      string st1="";
      st=LOCCTR+add_space(LOCCTR.length(),10)+s;
      interf<<st;
      interf<<"\n";
      ADDRESS.push_back(LOCCTR);
      if(tokens[0]!=" ")
      {

        if(tokens[1]=="EQU")
        {
          if(SYMDEF.find(tokens[0])==SYMDEF.end())
          {
            SYMDEF[tokens[0]]=tokens[2];
            st=tokens[0]+add_space(tokens[2].length(),10)+tokens[2];
            sym<<st;
          }
          else
          {
            cout<<"ERROR !! already in symdef\n";
            exit(0);
          }
        }
        else if(SYMTAB.find(tokens[0])==SYMTAB.end())
        {
        SYMTAB[tokens[0]]=LOCCTR;
        string str="";
        str=LOCCTR+add_space(LOCCTR.length(),10)+tokens[0];
        opf<<str;
        opf<<"\n";
        }
        else
        {
          cout<<"Error!! defined twice||\n";
          exit(0);
        }
      }




      if(tokens.size()==3)
      {
        //cout<<tokens[0]<<"|"<<tokens[1]<<"|"<<tokens[2]<<"|"<<endl;
          if(OPTAB.find(tokens[1])!=OPTAB.end() && REGISTER.find(tokens[2])==REGISTER.end() && tokens[2][1]!=',')
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+3);
          else if(tokens[1]=="EQU")
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+3);
          else if(tokens[1].compare("WORD")==0)
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+3);
          else if(tokens[1].compare("RESW")==0)
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+3*str_to_deci(tokens[2]));
          else if(tokens[1].compare("RESB")==0)
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+decstring_to_dec(tokens[2]));
          else if(tokens[1].compare("BYTE")==0)
          {
            int l=find_length(tokens[2]);
            if(tokens[2][0]=='C')
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+l);
            else if(tokens[2][0]=='X' && tokens[2].length()!=1)
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+l/2);
          }
          else if(tokens[1][0]=='+')//format 4
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+4);
          else if(REGISTER.find(tokens[2])!=REGISTER.end() || (REGISTER.find(to_string(tokens[2][0]))!=REGISTER.end() && tokens[2][1]==',') || tokens[1]=="COMPR")//format 2
          {
            LOCCTR=deci_to_hex(hex_to_deci(LOCCTR)+2);
          }

          else
          {
            cout<<"Error||||||\n";
            exit(0);
          }

        }

      }
      else if(tokens[0][0]=='.')
      {
        interf<<s;
        interf<<'\n';
      }

    }
    // for(string s:ADDRESS)
    // cout<<s<<endl;
  }


void Assembler::pass_two()
{
  ifstream intr("INTERMEDIATE_FILE.txt",ios::in|ios::binary);
  ofstream objc("OBJECT_PROGRAM.txt",ios::out);
  ofstream asli("ASSEMBLER_LISTING.txt",ios::out);
  vector<string> v;

  string s,aslil="",obj="",op_ad="";
  adct=0;
  int cou=-1;
  while(!intr.eof())
  {
    //adct++;

      s="";
      string t="",m="",n="",i="",x="",b="",p="",e="";
      getline(intr,s,'\n');

      cou++;
      v=split_into_4(s);
      if(v[0][0]=='.')
      {
        asli<<s;
        asli<<'\n';
        continue;
      }
      if( v.size()==4 && v[2]=="START")
      {
        //cout<<"HI\n";
        obj+="H.";
        obj+=PROG_NAME+add_space(PROG_NAME.length(),6)+".";
        obj+=start_add+".";
        obj+=LOCCTR;
        objc<<obj;
        objc<<'\n';
        aslil=s+add_space(s.length(),40);
        asli<<aslil;
        asli<<'\n';
      }
      if(v[2]=="START")
      {
        adct++;
        continue;
      }
      else if(ADDRESS[adct]==" ")
      {
        // cout<<ADDRESS[adct]<<"{{{{}}}}"<<endl;
        adct++;
        // adct++;
      }
      else if(v[2]=="BASE")
      {
        adct--;
        aslil=s+add_space(s.length(),40)+t;
        asli<<aslil;
        asli<<'\n';
      }
      else
      {
        adct++;
      }

      // cout<<s<<"--------"<<ADDRESS[adct]<<endl;
      // for(string s:v)
      // cout<<s<<" ";
      // cout<<endl;
      if(v[2]=="END")
      {
        break;
      }

      if(v.size()==3 && v[2]=="RSUB")
      {
        t="4F0000";
        TEXTREC.push_back(t);
        aslil=s+add_space(s.length(),40)+t;
        asli<<aslil;
        asli<<'\n';
        continue;
      }
      else
      {
        //getline(intr,s,'\n');
        //v=split_into_4(s);
        //cout<<"HI jb\n";

        if(OPTAB.find(v[2])!=OPTAB.end() && v[2][0]!='+')
        {

          if(REGISTER.find(v[3])==REGISTER.end() && SYMTAB.find(v[3])!=SYMTAB.end())
          {
            op_ad=SYMTAB[v[3]];
            n="1",i="1",x="0",b="0",p="1",e="0";
            //cout<<ADDRESS[adct]<<" "<<"|||||"<<endl;
            // cout<<op_ad<<"  "<<ADDRESS[adct]<<endl;
            t=addr_3(op_ad,OPTAB[v[2]],n,i,x,b,p,e,ADDRESS[adct]);
            TEXTREC.push_back(t);
            aslil=s+add_space(s.length(),40)+t;
            asli<<aslil;
            asli<<'\n';
          }
          else if(REGISTER.find(v[3])!=REGISTER.end() )
          {
            // cout<<v[3]<<".";
            // cout<<endl;
            op_ad=REGISTER[v[3]];
            t=OPTAB[v[2]]+op_ad+"0";
            TEXTREC.push_back(t);
            aslil=s+add_space(s.length(),40)+t;
            asli<<aslil;
            asli<<'\n';
          }
          else if(v[3].length()==3 && (v[3][0]=='A'||v[3][0]=='X'||v[3][0]=='L'||v[3][0]=='B'||v[3][0]=='S'||v[3][0]=='T'||
          v[3][0]=='F') && v[3][1]==',')
          {
            aslil=s+add_space(s.length(),40);
            string s(1,v[3][0]);
            string s1(1,v[3][2]);
            string r1=s;
            string r2=s1;
            op_ad=REGISTER[r1];
            t=OPTAB[v[2]]+REGISTER[r1]+REGISTER[r2];
            TEXTREC.push_back(t);
            aslil+=t;
            asli<<aslil;
            asli<<'\n';
          }
          else if(v[3][0]=='#')
          {
            n="0",i="1",x="0",b="0",p="0",e="0";
            if(SYMDEF.find(v[3].substr(1,v[3].length()-1))==SYMDEF.end())
            {
              op_ad=v[3].substr(1,v[3].length()-1);
              t=addr_3(op_ad,OPTAB[v[2]],n,i,x,b,p,e,"000000");
              TEXTREC.push_back(t);
              aslil=s+add_space(s.length(),40)+t;
              asli<<aslil;
              asli<<'\n';
            }
            else
            {
              op_ad=SYMDEF[v[3].substr(1,v[3].length()-1)];
              t=addr_3(op_ad,OPTAB[v[2]],n,i,x,b,p,e,"000000");
              TEXTREC.push_back(t);
              aslil=s+add_space(s.length(),40)+t;
              asli<<aslil;
              asli<<'\n';
            }

          }
          else if(v[3][0]=='@')
          {
            n="1",i="0",x="0",b="0",p="1",e="0";
            op_ad=SYMTAB[v[3].substr(1,v[3].length()-1)];
            t=addr_3(op_ad,OPTAB[v[2]],n,i,x,b,p,e,ADDRESS[adct]);
            TEXTREC.push_back(t);
            aslil=s+add_space(s.length(),40)+t;
            asli<<aslil;
            asli<<'\n';
          }
          else if(v[3][v[3].length()-1]=='X' && v[3][0]!='@' && v[3][1]!=',')
          {
            n="1",i="1",x="1",b="1",p="0",e="0";
            op_ad=SYMTAB[v[3].substr(0,v[3].length()-2)];

            t=addr_3(op_ad,OPTAB[v[2]],n,i,x,b,p,e,SYMTAB[base]);
            //cout<<SYMTAB[base]<<"___"<<op_ad<<endl;
            TEXTREC.push_back(t);
            aslil=s+add_space(s.length(),40)+t;
            asli<<aslil;
            asli<<'\n';
          }
          else
          {
            op_ad="000000";
            cout<<"Error!! Symbol not defined!!\n";
            exit(0);
          }
// cout<<op_ad;
          /*string t="",m="";
          t=addr_4(op_ad,OPTAB[v[2]]);
          cout<<"1\n";
          TEXTREC.push_back(t);
          m="M."+deci_to_hex(hex_to_deci(v[0])+hex_to_deci("1"))+"."+"05";
          MREC.push_back(m);*/
          //nixbpe
                    //cout<<v[2];

        }
        //cout<<v[2]<<endl;
        else if(v[2][0]=='+')
        {

          string sub="";
          sub=v[2].substr(1,v[2].length()-1);
          // cout<<sub<<endl;
          if(OPTAB.find(sub)!=OPTAB.end())
          {
            if(v[3][0]=='#')
            {
              n="0",i="1",x="0",b="0",p="0",e="0";
              op_ad=v[3].substr(1,v[3].length()-1);
              t=addr_4(deci_to_hex(decstring_to_dec(op_ad)),OPTAB[sub]);
              TEXTREC.push_back(t);
              aslil=s+add_space(s.length(),40)+t;
              asli<<aslil;
              asli<<'\n';
              if(v[2].substr(1,v[2].length()-1)=="JSUB")
              {
                m="M."+deci_to_hex(hex_to_deci(v[0])+hex_to_deci("1"))+"."+"05";
                MREC.push_back(m);
              }

            }
            // cout<<sub<<" ";
            else
            {
              op_ad=SYMTAB[v[3]];
              // cout<<v[3];
              // cout<<op_ad<<endl;
              // exit(0);
              t=addr_4(op_ad,OPTAB[sub]);
              // cout<<"1\n";
              TEXTREC.push_back(t);
              aslil=s+add_space(s.length(),40)+t;
              asli<<aslil;
              asli<<'\n';
              if(v[2].substr(1,v[2].length()-1)=="JSUB")
              {
                m="M."+deci_to_hex(hex_to_deci(v[0])+hex_to_deci("1"))+"."+"05";
                MREC.push_back(m);
              }

            }


          }

          else
          {
            op_ad="000000";
            cout<<"Error!! Symbol not defined\n";
            exit(0);
          }



        }

        else if(v[2]=="WORD")
        {
          string wrd=deci_to_hex(decstring_to_dec(v[3]));
          if(wrd.length()>=6)
          wrd=wrd.substr(wrd.length()-6,6);
          else
          {
            wrd=add_0(wrd,6);
          }
          TEXTREC.push_back(wrd);
          aslil=s+add_space(s.length(),40)+wrd;
          asli<<aslil;
          asli<<'\n';
        }
        else if(v[2]=="BYTE")
        {
          string x;
          if(v[3][0]=='X')
          {
            x=v[3].substr(2,v[3].length()-3);
            int l=x.length();

            TEXTREC.push_back(x);
            aslil=s+add_space(s.length(),40)+x;
            asli<<aslil;
            asli<<'\n';
          }
          else if(v[3][0]=='C')
          {
            string f,k;
            x=v[3].substr(2,v[3].length()-3);
            for(int i=0;i<x.length();i++)
            {
              //cout<<int(x[i])<<endl;
              k=deci_to_hex(int(x[i]));
              f+=k.substr(k.length()-2,2);
            }
            f=add_0(f,6);
            TEXTREC.push_back(f);
            aslil=s+add_space(s.length(),40)+f;
            asli<<aslil;
            asli<<'\n';
          }
        }
        else if(v[2]=="RESW" || v[2]=="RESB" || v[2]=="EQU" || v[2]=="END")
        {
          TEXTREC.push_back("");
          aslil=s+add_space(s.length(),40);
          asli<<aslil;
          asli<<'\n';
        }
      }


      // adct++;
  }

// for(string a:TEXTREC)
// cout<<a<<endl;

string inad=ADDRESS[1],fad;
string t,len;
int length=30;
int l=1,b=0;
//fad=deci_to_hex(hex_to_deci(ADDR)+30);
int lenop=0;
// cout<<TEXTREC.size()<<"+"<<ADDRESS.size()<<endl;
while(l<=TEXTREC.size())
{
  length=30;
  fad=deci_to_hex(hex_to_deci(inad)+length);

  if(inad.length()<6)
  {
    inad=add_0(inad,6);
  }
  if(find(ADDRESS.begin(),ADDRESS.end(),fad)!=ADDRESS.end())
  {
    len=deci_to_hex(30);
    t+="T."+fad+"."+len.substr(len.length()-2,2)+".";

    while(ADDRESS[l]!=fad)
    {
      if(ADDRESS[l]==" ")
      {
        l++;
        continue;
      }
      if(TEXTREC[b]=="")
      {
        l++;
        b++;
        continue;
      }
      t+=TEXTREC[b]+".";
      l++;
      b++;
      lenop++;
    }

    inad=ADDRESS[l+1];
    // inad=fad;
    // b=l;
    // l=l+1;


    //cout<<t<<endl;
    objc<<t;
    objc<<'\n';
     // l++;
    t="";
  }
  else
  {

    while(find(ADDRESS.begin(),ADDRESS.end(),fad)==ADDRESS.end())
    {
      length--;
      fad=deci_to_hex(hex_to_deci(inad)+length);
    }
    len=deci_to_hex(length);
    t+="T."+fad+"."+len.substr(len.length()-2,2)+".";
    while(ADDRESS[l]!=fad)
    {
      if(ADDRESS[l]==" ")
      {
        l++;
        // b++;
        continue;
      }
      if(TEXTREC[b]=="")
      {
        l++;
        b++;
        continue;
      }
      t+=TEXTREC[b]+".";
      l++;
      b++;
      // b++;
      lenop++;
    }
    inad=ADDRESS[l+1];
    // inad=fad;
    // b=l;
    // l=l+1;

    //cout<<t<<endl;
    objc<<t;
    objc<<'\n';
     // l++;
    t="";
  }
  // cout<<"---"<<fad<<"---"<<inad<<endl;
}

for(string strr:MREC)
{
  objc<<strr;
  objc<<'\n';
}
string tr="",i=ADDRESS[0];
if(i.length()<6)
{
  i=add_0(i,6);
}
tr+="E."+i;
objc<<tr;

}

int main()
{
  Assembler a;
  a.hexequi_generate();
  a.generate_OPTAB();
  a.pass_one();
  a.pass_two();

}
