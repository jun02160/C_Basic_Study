#pragma once
#ifndef __RING_H_
#define __RING_H_

#include <iostream>
#include "Circle.h"

class Ring
{
private:
    Circle inner;
    Circle outer;
public:
    bool InitMembers(const Circle& in, const Circle& out);
    void ShowTotalInfo() const;
};

#endif