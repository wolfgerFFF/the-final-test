#ifndef COUNTER_H
#define COUNTER_H

#include <stdexcept>
#include <iostream>

class Counter
{
    int count;
    bool resourceClosed;

public:
    Counter() : count(0), resourceClosed(false) {}

    int add()
    {
        if (resourceClosed)
        {
            throw std::runtime_error("Ресурс счетчика уже закрыт");
        }
        return ++count;
    }

    void close()
    {
        resourceClosed = true;
    }

    bool isResourceClosed() const
    {
        return resourceClosed;
    }

    ~Counter()
    {
        if (!resourceClosed)
        {
            std::cerr << "Warning: Counter was not properly closed" << std::endl;
        }
    }
};

#endif 
