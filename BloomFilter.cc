#include "BloomFilter.h"

#include <iostream>
#include <string>

using std::string;

BloomFilter::BloomFilter() {
  std::cout << "Initializing BloomFilter" << std::endl;
  n_elements_ = 20; 
  k_hash_functions_ = 3;
  bit_array_.resize(n_elements_);
  for (int i = 0; i < bit_array_.size(); ++i) {
//    std::cout << "bit_array at " << i
//              << " initialized to " << bit_array_.at(i)
//              << std::endl;
  }
}

void BloomFilter::Add(const string& element) {
  for(int i = 0; i < k_hash_functions_; ++i) {
    int hash_index = Hash(element, i);
    //std::cout << "For word " << element
    //          << " hash " << i << " is " 
    //          << hash_index << std::endl;
    bit_array_[hash_index] = true;
  }
}

bool BloomFilter::Exists(const string& element) {
  for (int i = 0; i < k_hash_functions_; ++i) {
    if (!bit_array_[Hash(element, i)]) {
      return false;
    }
  }
  return true;
}

int BloomFilter::Hash(const string& element, int n) {
  int hash = 1;
  for (int i = 0; i < element.size(); ++i) {
    hash += element.at(i) * (n + 1);
  }
  //std::cout << "Hash for " << element << " for n " << n
  //          << " is " << hash << std::endl;
  return hash % bit_array_.size();
}
