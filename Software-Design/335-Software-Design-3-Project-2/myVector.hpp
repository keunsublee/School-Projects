#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>



void vectorMedian (const std::vector<int> * instructions);


/*

  //loop though source vector
  for (auto it = source.begin(); it != source.end();) {
      //find keywords in book using find and move to dest vector if found
      if (std::find(it->getKeywords().begin(), it->getKeywords().end(), keyword) != it->getKeywords().end()) {
          dest.push_back(std::move(*it));     //move book to dest vector
          books_moved++;                      //count++
    
      it = source.erase(it);  //clear book from source vector and iterator becomes the return value at the erased position to continue loop
  }
  else {it++;}} //continue loop if keyword not found
  */

//operators
//move or copy assignment?
//variables

