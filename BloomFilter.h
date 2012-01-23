// Simple implementation of the Bloom Filter.
// 
#ifndef BLOOM_FILTER_H_
#define BLOOM_FILTER_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

// Simple implementation of a Bloom filter as described in
// http://en.wikipedia.org/wiki/Bloom_filter.
// This one uses pseudo hash functions just as an example of the functionality
// of the Bloom filter.
class BloomFilter {
 public:
  BloomFilter();
    
  void Add(const string& element);
  bool Exists(const string& element);
 private:
  // Pseudo hash function. Generates different hashes based on the given n 
  // parameter. This is used to emulate k different hashes.
  int Hash(const string& element, int k);

  // The bit set holding the flags for existence.
  vector<bool> bit_array_;
  
  // Number of elements in the bit set.
  int n_elements_;
  // Number of hash functions used.
  int k_hash_functions_;
};

#endif

