//
//  queue_testing.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 15/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include "Priorety_Queue.h"
#include "gtest/gtest.h"
TEST(Methods_Pr_Queue,push_queue_pop_empty_timeline){
    Try_To_Be_Smart:: Priorety_Queue<int,int> q;
    q.push(5, 3);
    q.push(7,2);
    ASSERT_EQ(q.top(), 5);
    ASSERT_EQ(q.size(), 2);
    ASSERT_EQ(q.empty(), false);
    q.push(9,4);
    ASSERT_EQ(q.top(), 9);
    q.pop();
    ASSERT_EQ(q.top(), 5);
    q.pop();
    ASSERT_EQ(q.top(), 7);
    q.push(9, 3);
    q.push(10, 2);
    q.push(12, 3);
    q.push(11, 3);
    q.push(0, 4);
    ASSERT_EQ(q.top(), 9);
    q.pop();
    ASSERT_EQ(q.top(), 0);
}
int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
