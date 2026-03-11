//
// Created by Anastasia on 12.03.2026.
//

#include <gtest/gtest.h>
#include "../include/Segment.h"
#include "../include/GameEntity.h"

TEST(SegmentTest, ConstructorAndGetters) {
    Segment seg(5, 10);
    EXPECT_EQ(seg.getX(), 5);
    EXPECT_EQ(seg.getY(), 10);
}

TEST(SegmentTest, SetPosition) {
    Segment seg(5, 10);
    seg.setPosition(7, 12);
    EXPECT_EQ(seg.getX(), 7);
    EXPECT_EQ(seg.getY(), 12);
}

TEST(SegmentTest, Symbol) {
    Segment seg(1, 1);
    EXPECT_EQ(seg.getSymbol(), 'O');
}

TEST(SegmentTest, Polymorphism) {
    Segment seg(2, 3);
    GameEntity* ptr = &seg;
    EXPECT_EQ(ptr->getSymbol(), 'O');
}
