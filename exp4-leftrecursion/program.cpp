#include <bits/stdc++.h>
using namespace std;
 
vector<string> insertUniqueProd(string str){
      vector<string> tempstr;
      int i=0, j=0;
 
      while(str[j] != '>'){
        i++;
        j++;
      }
 
      i++,j++;
 
      while(j <= str.size()){
          if(j == str.size()){
            string temp = str.substr(i, j-i);
            tempstr.push_back(temp);
            j++;
            break;
          }
          else if(str[j] == '|'){
            string temp = str.substr(i, j-i);
            tempstr.push_back(temp);
            i = j+1;
            j++;
           
          }
          else
            j++;
      }
 
  return tempstr;
}
 
vector<string> EliminateLeft(vector<string>&production){
    vector<string> ans;
 
    for(auto i:production){
      bool isReduced = false;
      vector<string> temp = insertUniqueProd(i);
      char non_terminal = i[0];
      string temp1="", temp2="";
      string lastprod = temp[temp.size()-1];
      string newtempterminal = "";
      newtempterminal += non_terminal;
     
      for(auto j: temp){
        if(non_terminal == j[0]){
            isReduced = true;
            string x = j.substr(1, j.size()-1);
            temp1 += x + non_terminal +"\'" + "|";
        }else{
            if(j[0] != '#')
              temp2 += j;
 
            temp2 += newtempterminal + "\'";
            if(j != lastprod)
              temp2 += "|";
        }
      }
 
      temp1 = newtempterminal + "\'" + "->" + temp1 + "#";
      temp2 = newtempterminal + "->" + temp2;
     
      if(isReduced == true){
        ans.push_back(temp2);
        ans.push_back(temp1);
      }
      else
        ans.push_back(i);
    }
    return ans;
}
 
int main() {
  ifstream f1("input.txt");
  if(!f1.is_open()){
    cout<<"Error in File Opening";
    exit(0);
  }
  string temp;
  vector<string> production;
 
  cout<<"Before Left Recursion: \n";
  while(getline(f1, temp)){
    cout<<temp<<endl;
    production.push_back(temp);
  }
 
  vector<string> ans = EliminateLeft(production);
  cout<<"\nAfter Left Elimination"<<endl;
  for(auto i : ans)
    cout<<i<<endl;
}
