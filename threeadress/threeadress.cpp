#include<bits/stdc++.h>
using namespace std;

void quadraples(vector<string> intermidate, unordered_set<char> s){
  cout<<"\n\nquadraples be\n"<<endl;
  cout<<"Loc\t op \t arg1 \t arg2 \t result \t"<<endl;

  for(int i=0;i<intermidate.size();i++){
    string temp = intermidate[i];
    string loc = "("+to_string(i)+")";
    
    string result = "";
    string op = "";
    string arg1 = "";
    string arg2 = "";
    
    int j=0;
    while(temp[j] != '='){
      result += temp[j];
      j++;
    }

    j++;


    while(j<temp.size() && s.find(temp[j])==s.end()){
      arg1 += temp[j];
      j++;
    }

    op += temp[j];
    j++;

    while(j<temp.size()){
      arg2 += temp[j];
      j++;
    }

    cout<<loc<<"\t\t"<<op<<"\t\t"<<arg1<<"\t\t"<<arg2<<"\t\t"<<result<<endl;
  }
}

void triples(vector<string> intermidate, unordered_set<char> s){
  cout<<"\n\nTriples be\n"<<endl;
  cout<<"Loc\t op \t arg1 \t arg2 \t"<<endl;

  for(int i=0;i<intermidate.size();i++){
    string temp = intermidate[i];
    string loc = "("+to_string(i)+")";
    
    string op = "";
    string arg1 = "";
    string arg2 = "";
    
    int j=0;
    while(temp[j] != '='){
      j++;
    }

    j++;


    while(j<temp.size() && s.find(temp[j])==s.end()){
      arg1 += temp[j];
      j++;
    }

    op += temp[j];
    j++;

    while(j<temp.size()){
      arg2 += temp[j];
      j++;
    }

    cout<<loc<<"\t\t"<<op<<"\t\t"<<arg1<<"\t\t"<<arg2<<endl;
  }
}

void indirecttriples(vector<string> intermidate, unordered_set<char> s){
  cout<<"\n\nIndirect Triples be\n"<<endl;

  cout<<"Addressign table be\n";
  cout<<"\n\tstatement\t\n";
  for(int i=0;i<intermidate.size();i++){
    cout<<"("<<i<<")\t"<<"4"<<i<<endl;
  }
  cout<<"\nLoc\t op \t arg1 \t arg2 \t"<<endl;

  for(int i=0;i<intermidate.size();i++){
    string temp = intermidate[i];
    string loc = "(4"+to_string(i)+")";
    
    string op = "";
    string arg1 = "";
    string arg2 = "";
    
    int j=0;
    while(temp[j] != '='){
      j++;
    }

    j++;


    while(j<temp.size() && s.find(temp[j])==s.end()){
      arg1 += temp[j];
      j++;
    }

    op += temp[j];
    j++;

    while(j<temp.size()){
      arg2 += temp[j];
      j++;
    }

    cout<<loc<<"\t\t"<<op<<"\t\t"<<arg1<<"\t\t"<<arg2<<endl;
  }
}

int main(){

  ifstream f1("input.txt");

  if(!f1.is_open()){
    cout<<"file doesnot open";
    exit(0);
  }

  vector<string> intermidate;
  string temp;

  cout<<"INTERMIDATE CODE BE : "<<endl;
  while(getline(f1, temp)){
    cout<<temp<<endl;
    intermidate.push_back(temp);
  }

  string op = "+*/-";
  unordered_set<char> s;

  for(auto i: op)
    s.insert(i);

 quadraples(intermidate, s);
 triples(intermidate, s);
 indirecttriples(intermidate, s);

}
