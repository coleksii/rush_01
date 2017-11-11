//
// Created by Chechuha Oleksii on 11/11/17.
//

#ifndef DAY07_RAMMEMORY_HPP
#define DAY07_RAMMEMORY_HPP


class RamMemory {
private:
    long freeMemory;
    long usedMemory;
public:
    ~RamMemory();
    RamMemory();

    void reload();

    long getFreeMemory() const;

    long getUsedMemore() const;

};


#endif //DAY07_RAMMEMORY_HPP
