#include "BloomFilter.h"

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  BloomFilter bloom_filter;
  std::cout << std::endl << "Hello " << std::endl;

  vector<string> good_urls;
  good_urls.push_back("www.google.com");
  good_urls.push_back("www.apple.com");
  
  for (int i = 0; i < good_urls.size(); ++i) {
    bloom_filter.Add(good_urls.at(i));
  }
  vector<string> urls_to_test;
  urls_to_test.push_back("www.google.com");
  urls_to_test.push_back("badgoogle.com");
  urls_to_test.push_back("www.apple.com");
  urls_to_test.push_back("badapple.com");
  urls_to_test.push_back("anotherbadapple.com");
  for(int i = 0; i < urls_to_test.size(); ++i) {
    cout << "Testing url " << urls_to_test.at(i) << " : " 
         << bloom_filter.Exists(urls_to_test.at(i)) << endl;
  }
  return 0;
}
