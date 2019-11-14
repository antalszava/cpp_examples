// #include <bits/stdc++>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

struct Child {

  string val;
  int explored;
  Child(string val_) : val(val_), explored(0) {}
};


bool diff_char(std::string s1, std::string s2){

  return 1;
}


void bfs(map<string, vector<Child>> word_map, std::string start, std::string end){
  int found = 0;
  
  while (found){
    std::vector<Child> children = word_map.at(start);
    for (int i = 0; i < children.size(); i++) {
      if (children[i].val == end){
	found = 1;
	return size;
      }
    }
    for (auto c : children){
      bfs(word_map, c, end);
    }
    
  }
  return (found == 0) ? found : size;
}

int main(int argc, char *argv[])
{
  
  string start = "cat";
  string end = "ned";

  map<string, vector<Child>> word_map;

  vector<string>  words{"bat", "war", "wat", "wet",
                                 "car", "ted", "tet"};

  words.push_back(start);
  words.push_back(end);
  
  for (auto w : words){
    std::vector<Child> neighbours;
    for (auto w2 : words){
      if (w != w2 && diff_char(w,w2)){
	neighbours.push_back(Child(w2));
      }
    }
    word_map.insert(make_pair(w,neighbours));
  }


  
  return 0;
}
