#pragma once

#include <iostream>
#include <map>


class Record {
 public:
    Record(const std::string& data, bool isDeleted = false) : data_(data), isDeleted_(isDeleted) {}

    /**
     * Marks this record as deleted.
     */
    void remove() { isDeleted_ = true; }

    /**
     * Sets the data for the Record.
     */
    void setData(const std::string& data) { data_ = data; }

 private:
    // Underlying data for this record.
    std::string data_;
    // Flag indicating if the record is deleted or not.
    bool isDeleted_;
};

/**
 * A Segment is part of a table that can be written. A segment will first write to
 * a memtable and a segment can be flushed into disk to an SSTable.
 */

// TODO: needs to support different comparison functions for ordering.
class Segment {
 public:
    Segment(int32_t maxRows, const std::string& fileName) : maxRows_(maxRows), fileName_(fileName) {}

    //~Segment();

    /**
     * Writes a new value to this segment. Returns true if the write
     * was successful, false otherwise.
     */
    bool write(const std::string& key, const std::string& value);

    /**
     * Removes a value from this segment. Returns true if the removal
     * was successful, false otherwise.
     */
    bool remove(const std::string& key);

    // Gets a value from this segment
    std::string get(const std::string& key) const;
 private:
    int32_t maxRows_;
    std::string fileName_;
    std::map<std::string, Record> memtable_;
    
    /**
     * Flushes the values for the memtable to disk.
     */
    void flush() const;
};
