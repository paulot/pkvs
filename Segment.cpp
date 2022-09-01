#include "Segment.hpp"



bool Segment::write(const std::string& key, const std::string& value) {
    // TODO: Locking and unlocking for concurrency
    auto it = this->memtable_.find(key);

    if (it != this->memtable_.end()) {
        // Found the record, modify
        it->second.setData(value);
        return true;
    } else if (this->memtable_.size() < this->maxRows_) {
        // Record not found, but can be added
        this->memtable_.insert(std::make_pair(key, Record(value)));
        return true;
    } 

    return false;
}


bool Segment::remove(const std::string& key) {
    // TODO: Locking and unlocking for concurrency
    auto it = this->memtable_.find(key);

    if (it != this->memtable_.end()) {
        // Found the record, modify
        it->second.remove();
        return true;
    } else if (this->memtable_.size() < this->maxRows_) {
        // Record not found, but can be added
        this->memtable_.insert(std::make_pair(key, Record("", false)));
        return true;
    } 

    return false;
}


std::string Segment::get(const std::string& key) const {
    return "blaa";
}


