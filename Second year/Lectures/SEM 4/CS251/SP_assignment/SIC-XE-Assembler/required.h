#include<bits/stdc++.h>
using namespace std;
vector<string> split_into_3(string line)
{
  vector<string> v;
    line+=' ';
    string st="";
    if(line[0]==' ')
    {
      v.push_back(" ");
    }
    // Vector of string to save tokens
    for(int i=0;i<line.length();i++)
    {
      if(line[i]==' ' && st.length()!=0)
      {
        v.push_back(st);
        st="";
      }
      else if(line[i]!=' ')
      {
        st+=line[i];
      }
    }

    return v;
}

vector<string> split_into_4(string line)
{
  vector<string> v;
    line+=' ';
    string st="";
    if(line[0]==' ')
    {
      v.push_back(" ");
      v.push_back(" ");
    }
    // Vector of string to save tokens
    for(int i=0;i<line.length();i++)
    {
      if(line[i]==' ' && st.length()!=0)
      {
        v.push_back(st);
        st="";
      }
      else if(line[i]!=' ')
      {
        st+=line[i];
      }
    }
    if(v.size()==3)
    v.insert(v.begin()+1," ");
    return v;
}



int hex_to_deci(string hexnum){
	int result;
	stringstream ss("");
	ss.unsetf(std::ios::hex);
	ss << hex << hexnum;
	ss >> result;
	ss.clear();
	return result;
}


string deci_to_hex(int decnum){
	string result;
	stringstream ss("");
	ss << hex << decnum;
	ss >> result;
	ss.clear();

	//zfill(6)
	if (true){
		if (result.length() < 6) {
			for (int i=result.length();i<6;i++){
				result = "0" + result;
			}
		}
	} else {
		if (result.length() % 2 != 0){
			result = "0" + result;
		}
	}
	transform(result.begin(),result.end(),result.begin(),::toupper); //UPPER,needs include <algorithm>

	return result;
}

int decstring_to_dec(string decnum){
	int result;
	stringstream ss("");
	ss.unsetf(std::ios::dec);
	ss << decnum;
	ss >> result;
	ss.clear();
	return result;
}


int find_length(string s)
{
  int si=0,ei=0,c=0;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='\'')
    {
      si=i;
      break;
    }
  }
  return s.length()-si-2;
}


string add_space(int si,int num)
{
  int n=num-si;
  string s;
  for(int i=1;i<=n;i++)
  {
    s+=' ';
  }
  return s;
}

int str_to_deci(string s)
{
    stringstream geek(s);
    int x = 0;
    geek >> x;
    return x;
}

string hexstring_to_binstring(string s)
{
  stringstream ss;
  ss<<hex<<s;
  unsigned n;
  ss>>n;
  bitset<4> b(n);
  return b.to_string();
}

string binstring_to_hexstring(string s)
{
  bitset<32> set(s);
  stringstream res;
  res<<hex<<uppercase<<set.to_ulong();
  return(res.str());
}
string add_0(string a,int n)
{
  string stri="";
  if(n==a.length()){
    return a;
  }
  for(int i=1;i<=n-a.length();i++)
  {
    stri+="0";
  }
  return stri+a;
}

string addr_4(string add,string op)
{
  string n="1",i="1",x="0",b="0",p="0",e="1",final_;
  string opcode=hexstring_to_binstring(op);
  // string addbin=hexstring_to_binstring(add);
  // cout<<add_0(add,5)<<endl;
  // cout<<opcode.substr(0,2)+n+i+x+b+p+e<<endl;
  if(add.length()>=5)
  {
     final_=op.substr(0,1)+binstring_to_hexstring(opcode.substr(0,2)+n+i+x+b+p+e) + add.substr(add.length()-5,5);
  }
  else
  {
   final_=op.substr(0,1)+binstring_to_hexstring(opcode.substr(0,2)+n+i+x+b+p+e) + add_0(add,5);
  }
  return final_;
}
string displacement(string s,string e)
{
  return(deci_to_hex(hex_to_deci(s)-hex_to_deci(e)));
}

string addr_3(string stadd,string op,string n,string i,string x,string b,string p,string e,string endadd)
{
  string opcode=hexstring_to_binstring(op);
  string disp=displacement(stadd,endadd);
  if(disp.length()>=3)
  {
    disp=disp.substr(disp.length()-3,3);
  }
  else
  {
    disp=add_0(disp,3);
  }
  string final_=op.substr(0,1)+binstring_to_hexstring(opcode.substr(0,2)+n+i+x+b+p+e) + disp;
  return final_;
}
