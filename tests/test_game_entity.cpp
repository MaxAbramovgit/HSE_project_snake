
#include <gtest/gtest.h>
#include "../include/GameEntity.h"

TEST(GameEntityTest, ConstructorAndGetters) {
    GameEntity entity(5, 10);
    EXPECT_EQ(entity.getX(), 5);
    EXPECT_EQ(entity.getY(), 10);
}

TEST(GameEntityTest, SetPosition) {
    GameEntity entity(5, 10);
    entity.setPosition(7, 12);
    EXPECT_EQ(entity.getX(), 7);
    EXPECT_EQ(entity.getY(), 12);
}

TEST(GameEntityTest, DefaultSymbol) {
    GameEntity entity(1, 1);
    EXPECT_EQ(entity.getSymbol(), '?');
}

TEST(GameEntityTest, VirtualDestructor) {
    GameEntity* entity = new GameEntity(3, 4);
    EXPECT_EQ(entity->getX(), 3);
    EXPECT_EQ(entity->getY(), 4);
    delete entity;
}