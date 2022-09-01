#include <iostream>

#include "Segment.hpp"

// Writing 
//  
// Writing should first be done to a memtable (C0), then
// upon flushing this should go to an SSTable that gets
// written in disk. SSTables are written to disk through
// a process called flushing. SSTables are also compacted
// through a process called compaction.
//
// Whenever we write we should do the following
//  1. Create a segment number for the write
//  2. Write the row to a given in-memory memtable
//
// Flushing
// For flushing in memory data to an SSTable do the following
//  1. Iterate through the in-memory data structure and write to a file in order
//  2. Create a bloomfilter of all the keys in the file
//  3. Save the bloomfilter as well in the file
//
// Compacting
// For compacting, meaning merging 2 SSTables together
//  1. Read all records for the smaller SSTable and write them to the larger SSTable
//     while keeping the sorted order
//  2. When faced with a duplicate, pick the one with the latest timestamp number..
//  3. Remove items marked as deleted.




// TODO:
//  Handle writing/reading from disk
//  Handle failures
//  Handle some kind of caching for key retrieval
//
int main(int argc, char** argv) {
    // std::cout << "hello" << std::endl;
    Segment s(32, "bla");
    s.write("foo", "bar");
    std::cout << "results: " << std::endl;
    std::cout << s.get("foo") << std::endl;
    return 0;
}
