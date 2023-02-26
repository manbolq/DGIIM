//
// Created by fluque1995 on 8/9/21.
//

#include <string>
#include <vector>
#include <utility>
#include <set>
#include "dictionary.h"

///////////////////////////////////////////////////////////////////////////////
//                             Private functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::node Dictionary::findLowerBoundChildNode(char character, Dictionary::node current) {
  node prev_child, curr_child = current.left_child();

  for (; !curr_child.is_null() && (*curr_child).character <= character; curr_child = curr_child.right_sibling()){
    prev_child = curr_child;
    if ((*curr_child).character == character) {
      return curr_child;
    }
  }
  if (!prev_child.is_null()) {
    return prev_child;
  }
  return current;
}

Dictionary::node Dictionary::insertCharacter(char character, Dictionary::node current) {
  node insertion_position = findLowerBoundChildNode(character, current);
  if (insertion_position == current){
    this->words.insert_left_child(current, char_info(character));
    return insertion_position.left_child();
  } else if ((*insertion_position).character != character){
    this->words.insert_right_sibling(insertion_position, char_info(character));
    return insertion_position.right_sibling();
  } else {
    return insertion_position;
  }
}

std::list<std::string>
Dictionary::wordsByDepth(int remaining_levels, Dictionary::node current_node, std::string current_word) {
  std::list<std::string> result;

  if (current_node.is_null()){
    return result;
  }
  if (remaining_levels == 0 && (*current_node).valid_word) {
    result.push_back(current_word);

  } else if (remaining_levels > 0) {
    current_node = current_node.left_child();

    while (!current_node.is_null()){
      std::list<std::string> current_result = this->wordsByDepth(remaining_levels - 1,
								 current_node,
								 current_word + (*current_node).character);
      // This method appends a list at the end of another one
      result.splice(result.end(), current_result);
      current_node = current_node.right_sibling();
    }
  }

  return result;
}

std::list<std::string> Dictionary::getCoincidentWords(std::multiset<char> &characters,
						      Dictionary::node current_node,
                                                      std::string current_word) {
  std::list <std::string> result;

  if (current_node.is_null()){
    return result;
  }
  if ((*current_node).valid_word){
    result.push_back(current_word);
  }
  current_node = current_node.left_child();

  while (!current_node.is_null()){
    std::multiset<char>::iterator curr_char_it = characters.find((*current_node).character);
    if (curr_char_it != characters.end()){
      char curr_char = *curr_char_it;
      characters.erase(curr_char_it);
      std::list<std::string> current_result = this->getCoincidentWords(
								       characters,
								       current_node,
								       current_word + curr_char);
      result.splice(result.end(), current_result);
      characters.insert(curr_char);
    }
    current_node = current_node.right_sibling();
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////
//                              Public functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::Dictionary() {
  this->words.set_root(char_info());
}

Dictionary::Dictionary(const Dictionary &other) {
  this->words = other.words;
}

Dictionary::~Dictionary() {
  this->words.clear();
}

std::vector<std::string> Dictionary::wordsOfLength(int length) {
  std::list<std::string> words = this->wordsByDepth(
						    length,
						    this->words.get_root(),
						    std::string());
  return std::vector<std::string>(words.begin(), words.end());
}

bool Dictionary::exists(const std::string & word) {
  node current = this->words.get_root();
  for (int i = 0; i < word.size(); ++i){
    current = this->findLowerBoundChildNode(word[i], current);
    if ((*current).character != word[i]) {
      return false;
    }
  }

  return (*current).valid_word;
}

bool Dictionary::erase(const std::string & val){
  node current = this->words.get_root();
  for (int i = 0; i < val.size(); ++i){
    current = this->findLowerBoundChildNode(val[i], current);
    if ((*current).character != val[i]) {
      return false;
    }
  }
  if ((*current).valid_word){
    (*current).valid_word = false;
    return true;
  }
  return false;
}

bool Dictionary::insert(const std::string &word) {
  node current = this->words.get_root();
  for (int i = 0; i < word.size(); ++i){
    current = this->insertCharacter(word[i], current);
  }
  (*current).valid_word = true;

  return true;
}

Dictionary &Dictionary::operator=(const Dictionary &dic){
  if (this != &dic){
    this->words.clear();
    this->words = dic.words;
  }
  return *this;
}

std::vector <std::string> Dictionary::getPossibleWords(std::vector<char> available_characters){
  std::multiset<char> chars;
  for (auto letter: available_characters){
    chars.insert(tolower(letter));
  }
  std::list<std::string> words = getCoincidentWords(chars,
						    this->words.get_root(),
						    std::string());
  return std::vector<std::string> {words.begin(), words.end()};
}


///////////////////////////////////////////////////////////////////////////////
//                               I/O overload                                //
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream &os, const Dictionary &dict){
  for(Dictionary::iterator it = dict.begin();it != dict.end(); ++it){
    os << *it << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream &is, Dictionary &dict){
  std::string curr_word;
  while (getline(is, curr_word)){
    dict.insert(curr_word);
  }
  return is;
}

///////////////////////////////////////////////////////////////////////////////
//                      Letters Occurrences and usages                       //
///////////////////////////////////////////////////////////////////////////////

int Dictionary::getOccurrences(const char c){
    int num = 0;
    for (tree<char_info>::preorder_iterator it = words.begin_preorder(); it != words.end_preorder(); ++it){
        if ((*it).character == c)
            num++;
    }
    return num;
}

int Dictionary::getTotalUsages(const char c){
    return getTotalUsages(words.get_root(), c).first;
}

std::pair<int, int> Dictionary::getTotalUsages(node curr_node, char c){
    pair<int, int> out;
    pair<int, int> left, right;

    out.first = out.second = left.first = left.second = right.first = right.second = 0;

    if (!curr_node.left_child().is_null()){
        left = getTotalUsages(curr_node.left_child(), c);
    }
    if (!curr_node.right_sibling().is_null()){
        right = getTotalUsages(curr_node.right_sibling(), c);
    }

    out.first = left.first + right.first;
    out.second = left.second + right.second;

    if (curr_node.operator*() == c){
        out.first += left.second;
    }
    bool go_on = true;
    for (tree<char_info>::preorder_iterator it = words.begin_preorder(); it != words.end_preorder() && go_on; ++it){
        if (it == curr_node && (*it).valid_word){
            out.first++;
            out.second++;
            go_on = false;
        }
    }

    return out;
}

int Dictionary::getTotalLetters(){return this->words.size();}


///////////////////////////////////////////////////////////////////////////////
//                                 Iterator                                  //
///////////////////////////////////////////////////////////////////////////////

void Dictionary::iterator::nextWord(){
    bool valid_word=false;
    int level=iter.get_level();

    while(!valid_word){
        ++iter;
        if(iter.get_level()==level+1){
            level++;
            curr_word.push_back((*iter).character);
        }
        else if (iter.get_level()==level){
            curr_word.pop_back();
            curr_word.push_back((*iter).character);
        }
        else curr_word.pop_back();//iter.get_level()==level-1
        valid_word=(*iter).valid_word;
    }
}

Dictionary::iterator::iterator() :iter(){
    curr_word="";
}

Dictionary::iterator::iterator(tree<char_info>::const_preorder_iterator iter) {
    this->iter=iter;
}

std::string Dictionary::iterator::operator*() {
    return curr_word;
}

Dictionary::iterator &Dictionary::iterator::operator++() {
    nextWord();
    return *this;
}

bool Dictionary::iterator::operator==(const iterator &other) {
    return iter==other.iter;
}

bool Dictionary::iterator::operator!=(const iterator &other) {
    return iter!=other.iter;
}

Dictionary::iterator Dictionary::begin() const {
    Dictionary::iterator it(words.cbegin_preorder());
    return it;
}

Dictionary::iterator Dictionary::end() const {
    Dictionary::iterator it(words.cend_preorder());
    return it;
}

