#ifndef IDGENERATOR_H
#define IDGENERATOR_H

template <typename T>
class IDGenerator {
    static int counter;
public:
    static int next() { return counter++; }
};

template <typename T>
int IDGenerator<T>::counter = 0;

#endif