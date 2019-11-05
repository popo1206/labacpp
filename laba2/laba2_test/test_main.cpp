//
//  test_main.cpp
//  laba2
//
//  Created by Полина Подчуфарова on 02/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
#include <iostream>
#include "gtest/gtest.h"
#include "Cycloid.h"

TEST(dsdf, scsdf)
{
    EXPECT_EQ(5, 6-1);
}
TEST(CycloidConstuctor, defaultConstructor) {
    Prog2::Cycloid a1;
    ASSERT_EQ(0,a1.getP().x);
    ASSERT_EQ(0, a1.getP().y);
     ASSERT_EQ(1, a1.getR());
}

TEST(CycloidConstuctor, InitConstructor) {
    Prog2:: Cycloid a2(3);
    Prog2:: Point p(2,3);
    ASSERT_EQ(0,a2.getP().x);
    ASSERT_EQ(0, a2.getP().y);
    ASSERT_EQ(3, a2.getR());
    
    Prog2:: Cycloid a3(p,8);
    ASSERT_EQ(2,a3.getP().x);
    ASSERT_EQ(3, a3.getP().y);
    ASSERT_EQ(8, a3.getR());
    
    Prog2:: Cycloid a4(-4,-5,3);
    ASSERT_EQ(-4,a4.getP().x);
    ASSERT_EQ(-5, a4.getP().y);
    ASSERT_EQ(3, a4.getR());
}
TEST (CycloidConstructor, TestException){
    Prog2::Point p;
    ASSERT_ANY_THROW(Prog2::Cycloid (2,5,-5));
    ASSERT_ANY_THROW(Prog2::Cycloid (p,-1));
}
 TEST(CycloidMethods,Setters)
{
    Prog2::Cycloid a;
    Prog2::Point p1(3,2);
    a.setP(p1);
    ASSERT_EQ(3, a.getP().x);
    ASSERT_EQ(2, a.getP().y);
    Prog2::Point p2(-3, -2);
    a.setP(p2);
    ASSERT_EQ(-3, a.getP().x);
    ASSERT_EQ(-2, a.getP().y);
    a.setR(2);
    ASSERT_EQ(2, a.getR());
    ASSERT_ANY_THROW(a.setR(-1));
}
TEST(CycloidMethods, Parameters)
{
    Prog2::Cycloid a1(1,0,1);
    const double err = 0.00001;
    double t=0;
    ASSERT_NEAR(3*pi, a1.full_area(), err);
    ASSERT_NEAR(64/3*pi, a1.area_osn(), err);
    ASSERT_NEAR(0, a1.coordinate_x(t), err);
    ASSERT_NEAR(0, a1.coordinate_y(t), err);
    ASSERT_NEAR(2*pi, a1.create_agle(360), err);
    ASSERT_EQ(0, a1.length(t));
    ASSERT_NEAR(8*a1.getR(), a1.length(2*pi),err);
    ASSERT_NEAR(0,a1.radius_krivisna(0),err);
     ASSERT_NEAR(0,a1.radius_krivisna(2*pi),err);
    ASSERT_NEAR(4,a1.radius_krivisna(pi),err);
    ASSERT_NEAR(0,a1.radius_krivisna(8*pi),err);

    

}

int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
