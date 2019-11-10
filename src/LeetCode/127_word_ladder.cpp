#include <bits/stdc++.h>

using namespace std;

// public int ladderLength(String beginWord, String endWord, List<String> wordList) {

//     // Since all words are of same length.
//     int L = beginWord.length();

//     // Dictionary to hold combination of words that can be formed,
//     // from any given word. By changing one letter at a time.
//     HashMap<String, ArrayList<String>> allComboDict = new HashMap<String, ArrayList<String>>();

//     wordList.forEach(
//         word -> {
//           for (int i = 0; i < L; i++) {
//             // Key is the generic word
//             // Value is a list of words which have the same intermediate generic word.
//             String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);
//             ArrayList<String> transformations =
//                 allComboDict.getOrDefault(newWord, new ArrayList<String>());
//             transformations.add(word);
//             allComboDict.put(newWord, transformations);
//           }
//         });

//     // Queue for BFS
//     Queue<Pair<String, Integer>> Q = new LinkedList<Pair<String, Integer>>();
//     Q.add(new Pair(beginWord, 1));

//     // Visited to make sure we don't repeat processing same word.
//     HashMap<String, Boolean> visited = new HashMap<String, Boolean>();
//     visited.put(beginWord, true);

//     while (!Q.isEmpty()) {
//       Pair<String, Integer> node = Q.remove();
//       String word = node.getKey();
//       int level = node.getValue();
//       for (int i = 0; i < L; i++) {

//         // Intermediate words for current word
//         String newWord = word.substring(0, i) + '*' + word.substring(i + 1, L);

//         // Next states are all the words which share the same intermediate state.
//         for (String adjacentWord : allComboDict.getOrDefault(newWord, new ArrayList<String>())) {
//           // If at any point if we find what we are looking for
//           // i.e. the end word - we can return with the answer.
//           if (adjacentWord.equals(endWord)) {
//             return level + 1;
//           }
//           // Otherwise, add it to the BFS Queue. Also mark it visited
//           if (!visited.containsKey(adjacentWord)) {
//             visited.put(adjacentWord, true);
//             Q.add(new Pair(adjacentWord, level + 1));
//           }
//         }
//       }
//     }

//     return 0;
//   }

struct WordNode
{
  string str;
  bool marked;
  std::vector<string> children;
  int queue_depth;
  WordNode(string str_) : str(str_), marked(0){};
};

bool diff_by_one_char(string s1, string s2)
{
  
  // std::cout << "diff_by_one_char = " << std::endl;
  int diff = 0;
  for (int i = 0; i < s1.size(); i++){
    if (s1[i] != s2[i]) diff++;
    if (diff > 1) return 0;
  }
  // std::cout << s1 << " " << s2 << " diff = " << diff << std::endl;
  return (diff == 1);
}

int breadth_first_search
(
 string start,
 unordered_map<string, WordNode> & word_map,
 const vector<string> & word_list,
 string end
)
{
  // "hit" -> "hot" -> "dot" -> "dog" -> "cog"
  queue<string> word_queue;
  word_map.at(start).marked = true;
  word_queue.push(start);
  word_map.at(start).queue_depth = 1;
  while (!word_queue.empty()){
    string r = word_queue.front();
    // std::cout << "path_length = " << word_map.at(r).queue_depth << " , front = " << r << std::endl;
    word_queue.pop();
    if (r == end){
      return word_map.at(r).queue_depth;//path_length;
    }
    
    WordNode & parent = word_map.at(r);
    for (int i = 0; i < parent.children.size(); i++){

      WordNode &child = word_map.at(parent.children[i]);

      if(child.str == end){
	return parent.queue_depth + 1;
      }
      
      if (child.marked == false){
	child.marked = true;
	child.queue_depth =  parent.queue_depth + 1;
	word_queue.push(parent.children[i]);
	// children_size++;
      }
    }

  }
  return 0;
}


int ladderLength(string start, string end, vector<string>& word_list)
{
  std::unordered_map<string, WordNode> word_map;  
  int i = -1;
  int found = 0;
  for (int i = 0; i < word_list.size(); i++){
    if (word_list[i] == end){
      found = 1;
      break;
    }
  }
  if (found == 0) return found;
  
  while (i < (int)word_list.size()){
    string word1 = (i == -1) ? start : word_list[i];
    if ( !(i >= 0 && word1 == start)){
    WordNode w1(word1);
    std::cout << "word1 = " << word1 << std::endl;
    
    for (int j = 0; j < word_list.size(); j++) {
      if (diff_by_one_char(word1, word_list[j]) ){
	std::cout << " word_list[j] = " << word_list[j] << std::endl;
	w1.children.push_back(word_list[j]);
      }
    }
    if (diff_by_one_char(word1, end)) {
      w1.children.push_back(end);
      // std::cout << " word_list[j] = " << end << std::endl;
    }
    if (!(i >= 0 && word1 == start))
      word_map.insert(make_pair(word1, w1));
    }
    i++;
  }

  // word_map.insert(make_pair(end,WordNode(end)));

  // for (auto i : word_map){

  //   std::cout << i.first << std::endl;
  //   std::cout << "children = ";
  //   for (int j = 0; j < i.second.children.size(); j++){
  //     std::cout << i.second.children[j];
  //   }
  //   std::cout << std::endl;
    
  // }

  // return 1;
  // std::cout << "done making map" <<std::endl;
  return breadth_first_search(start, word_map, word_list, end);
}

int main(int argc, char *argv[])
{
  string start = "hit";
  string end = "cog";
  // "hit"
  // "cog"
  // ["hot","dot","dog","lot","log"]  
  vector<string> word_list = {"hot","dot","dog","lot","log","cog"};

  // string start = "a";
  // string end = "c";
  // vector<string> word_list = {"a", "b", "c"};

  // vector<string> word_list = {"hot","dot","dog","lot","log"};
  // ladder_length(start,end,word_list);




  
  std::cout << ladderLength(start, end, word_list) << std::endl;
  
  return 0;
}

