
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include "Book.hpp"

void moveAll (const std::string, std::vector<Book> &, std::vector<Book> &);

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  /////////

  //loop though source vector
  
  for (auto it = source.begin(); it != source.end();) {
      //find keywords in book using find and move to dest vector if found
      if (std::find(it->getKeywords().begin(), it->getKeywords().end(), keyword) != it->getKeywords().end()) {
          dest.push_back(std::move(*it));     //move book to dest vector
          books_moved++;                      //count++
    
      it = source.erase(it);  //clear book from source vector and iterator becomes the return value at the erased position to continue loop
  }
  else {it++;}} //continue loop if keyword not found


  //////
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}

