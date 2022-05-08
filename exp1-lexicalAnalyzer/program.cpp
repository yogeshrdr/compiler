#include <bits/stdc++.h>
using namespace std;
 
void placeMapElement(unordered_map<char, string> &m1,
                     unordered_map<string, string> &m2) {
 
  // m1
  string op = "+-*/=><";
  string other = ",;\(){}[]'':.";
  for (auto i : op)
    m1[i] = "op";
  for (auto i : other)
    m1[i] = "ot";
 
  // m2
  string numer = "0123456789";
 
  string keywords[] = {
  "return",
  "int","float","char","string","double","short","long","auto","const","void"
  "if","else","switch","case","default","break","continue",
  "for","while","do",
  "enum","goto","register","signed","sizeof","static","typedef","union","unsigned","volatile"
  };
 
  for (auto i : numer) {
    string temp = "";
    temp += i;
    m2[temp] = "num";
  }
 
  for (auto i : keywords)
    m2[i] = "key";
}
 
void printData(unordered_set<string> &s1, string str) {
  cout <<"\n"<< str << ": ";
 
  for (auto dt : s1)
    cout<<dt<<" ";
  cout <<"\n";
 
  return;
}
 
void isCommentFinder(char x, bool& isPrevSingleSlash, bool& isComment){
  if(x == '/' && isPrevSingleSlash == false)
      isPrevSingleSlash = true;
   
    if(isPrevSingleSlash == true){
      if(x == '/')
        isComment = true;
      else
        isPrevSingleSlash= false;
    }
 
    if(x=='\n'){
      isComment = false;
      isPrevSingleSlash = false;
    }
}
 
 
int main() {
  ifstream f1("input.txt");
 
  if (!f1.is_open()) {
    cout << "Error while opening file";
    exit(0);
  }
 
  unordered_set<string> Identifier;
  unordered_set<string> Keywords;
  unordered_set<string> Numercal;
  unordered_set<string> op;
  unordered_set<string> other;
 
  unordered_map<char, string> m1;
  unordered_map<string, string> m2;
  placeMapElement(m1, m2);
 
  string temp;
  bool isComment = false;
  bool isPrevSingleSlash = false;
 
  while (!f1.eof()) {
    char x = f1.get();
    isCommentFinder(x, isPrevSingleSlash, isComment);
   
    if(isComment)
      continue;
 
    auto it = m1.find(x);
 
    if (it == m1.end() && x!=' ') {
      temp += x;
    } else {
     
      string newTemp = "";
      newTemp += temp[0];
     
      if(m2[newTemp] == "num")
        Numercal.insert(temp);
      else if(m2[temp] == "key")
        Keywords.insert(temp);
      else
        Identifier.insert(temp);
     
      newTemp = "";
      newTemp += x;
 
      if(m1[x] == "op")
        op.insert(newTemp);
      else if(m1[x] == "ot")
        other.insert(newTemp);
     
      temp="";
    }
  }
 
  printData(Identifier, "Identifier");
  printData(Keywords, "Keywords");
  printData(Numercal, "Numercal");
  printData(op, "operator");
  printData(other, "other");
 
  return 0;
}
