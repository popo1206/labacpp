//
//  main.cpp
//  test_laba3a
//
//  Created by Полина Подчуфарова on 26/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <Binary.h>
#include <gtest/gtest.h>

laba3::Item * Get_Item(char *buf){
    laba3::Item head = {true, NULL };
    laba3::Item *last = &head;
    char* str;
            for(str = buf; *str != '\0'; ++str){
                last->next = new laba3::Item;
                last = last->next;
                if (static_cast<int>(*str)-48==1){
                    last->c=true;
                    last->next = nullptr;
                }
                else {
                    if (static_cast<int>(*str)-48==0){
                        last->c=false;
                        last->next = nullptr;
                    }
                }
                
            }
    return head.next;
}
TEST(dsdf, scsdf)
{
    EXPECT_EQ(5, 6-1);
}
TEST(SignalConstuctor, defaultConstructor) {
    int k1=0;
    laba3::Signal a1(k1);
    bool k2=true;
    laba3::Signal a2(k2);
    laba3::Item *c;
    c=Get_Item("11000001111");
    laba3:: Signal a3(c);
    ASSERT_EQ(0,a1.getn());
    ASSERT_EQ(1, a2.getn());
    ASSERT_EQ(true, a2.getBSignal(0).level);
    ASSERT_EQ(255, a2.getBSignal(0).duration);
    ASSERT_EQ(1, a2.getn());
   ASSERT_EQ(2, a3.getBSignal(0).duration);
    ASSERT_EQ(true, a3.getBSignal(0).level);
    ASSERT_EQ(5, a3.getBSignal(1).duration);
    ASSERT_EQ(false, a3.getBSignal(1).level);
    ASSERT_EQ(3, a3.getn());
}
TEST (SignalMethod, TestException){
    int k=0;
    laba3:: Signal signal(k);
    signal.input_signal(false, 255);
    laba3:: Item *c;
    c=Get_Item("000101010101");
    laba3:: Signal signal_c(c);
   ASSERT_ANY_THROW(signal.adding_another_signal(0,signal_c));
    ASSERT_ANY_THROW(signal.adding_another_signal(177,signal_c));
     ASSERT_ANY_THROW(signal.add_signal(signal_c));
    laba3:: Signal sig;
    laba3:: Signal sig1;
    sig.input_signal(true, 250);
    sig1.input_signal(true, 250);
    ASSERT_ANY_THROW(sig.add_signal(sig1));
    ASSERT_ANY_THROW(sig.copy(15));
    ASSERT_ANY_THROW(sig.delete_fragment(290, 1));
    ASSERT_ANY_THROW(sig.delete_fragment(1, 290));
}
TEST(BinaryMethods,input)
{
    int k=0;
    laba3:: Signal signal(k);
    signal.input_signal(false,25);
    signal.input_signal(true,67);
    ASSERT_EQ(signal.getBSignal(0).level,false);
     ASSERT_EQ(signal.getBSignal(0).duration,25);
    ASSERT_EQ(signal.getBSignal(1).level,true);
    ASSERT_EQ(signal.getBSignal(1).duration,67);
    ASSERT_EQ(signal.getn(), 2);
}
TEST(BinaryMethods,invert)
{
    laba3:: Item *c;
    c=Get_Item("11111100000011111100000011111100");
    laba3:: Signal signal(c);
    ASSERT_EQ(signal.getBSignal(0).level,true);
    ASSERT_EQ(signal.getBSignal(0).duration,6);
    signal.invert();
    ASSERT_EQ(signal.getBSignal(0).level,false);
    ASSERT_EQ(signal.getBSignal(0).duration,2);
}
TEST(BinaryMethods,add_signal)
{
    laba3:: Item *c;
    c=Get_Item("11111100000011111100000011111100");
    laba3:: Signal signal(c);
    laba3:: Item *c1;
    c1=Get_Item("0111111000");
    laba3:: Signal signal_1(c1);
    signal.add_signal(signal_1);
    ASSERT_EQ(signal.getBSignal(5).level,false);
    ASSERT_EQ(signal.getBSignal(5).duration,3);
     ASSERT_EQ(signal.getn(),8);
    //без слияния
}
TEST(BinaryMethods,adding_another_signal_in_the_middle_1)
{
    laba3:: Item *c;
    c=Get_Item("11111100000011111100000011111100");
    laba3:: Signal signal(c);
    laba3:: Item *c1;
    c1=Get_Item("0111111000");
    laba3:: Signal signal_1(c1);
    signal.adding_another_signal(19,signal_1);
    ASSERT_EQ(signal.getBSignal(3).level,false);
    ASSERT_EQ(signal.getBSignal(3).duration,2);
    ASSERT_EQ(signal.getBSignal(4).level,true);
    ASSERT_EQ(signal.getBSignal(4).duration,6);
    ASSERT_EQ(signal.getBSignal(5).level,false);
    ASSERT_EQ(signal.getBSignal(5).duration,8);
    ASSERT_EQ(signal.getn(),8);
}
TEST(BinaryMethods,adding_another_signalin_the_middle_2)
{
    laba3:: Item *c;
    c=Get_Item("11111100000011111100000011111100");
    laba3:: Signal signal(c);
    laba3:: Item *c1;
    c1=Get_Item("111111000");
    laba3:: Signal signal_1(c1);
    signal.adding_another_signal(12,signal_1);
    ASSERT_EQ(signal.getBSignal(2).level,true);
    ASSERT_EQ(signal.getBSignal(2).duration,6);
    ASSERT_EQ(signal.getBSignal(3).level,false);
    ASSERT_EQ(signal.getBSignal(3).duration,3);
    ASSERT_EQ(signal.getn(), 8);
    //без слияние
}
TEST(BinaryMethods,adding_another_signal_in_begin)
{
    laba3:: Item *c;
    c=Get_Item("11111100000011111100000011111100");
    laba3:: Signal signal(c);
    laba3:: Item *c1;
    c1=Get_Item("111111000");
    laba3:: Signal signal_1(c1);
    signal.adding_another_signal(0,signal_1);
    ASSERT_EQ(signal.getBSignal(0).level,true);
    ASSERT_EQ(signal.getBSignal(0).duration,6);
    ASSERT_EQ(signal.getBSignal(1).level,false);
    ASSERT_EQ(signal.getBSignal(1).duration,3);
    ASSERT_EQ(signal.getn(), 8);
    //со слиянием
}
TEST(BinaryMethods,adding_another_signal_in_end)
{
    laba3:: Item *c;
    c=Get_Item("11111100000011111100000011111100");
    laba3:: Signal signal(c);
    laba3:: Item *c1;
    c1=Get_Item("111111000");
    laba3:: Signal signal_1(c1);
    signal.adding_another_signal(32,signal_1);
    ASSERT_EQ(signal.getBSignal(6).level,true);
    ASSERT_EQ(signal.getBSignal(6).duration,6);
    ASSERT_EQ(signal.getBSignal(7).level,false);
    ASSERT_EQ(signal.getBSignal(7).duration,3);
    ASSERT_EQ(signal.getn(), 8);
    //со слиянием
}
TEST(BinaryMethods,copy)
{
    laba3:: Item *c1;
    c1=Get_Item("0111111000");
    laba3:: Signal signal(c1);
    signal.copy(2);
    ASSERT_EQ(4, signal.getBSignal(2).duration);
    ASSERT_EQ(false, signal.getBSignal(2).level);
    ASSERT_EQ(3, signal.getBSignal(6).duration);
    ASSERT_EQ(false, signal.getBSignal(6).level);
    ASSERT_EQ(7, signal.getn());
    //без слияния
}
TEST(BinaryMethods,delete_signal_in_the_begin)
{
    laba3:: Item *c1;
    c1=Get_Item("0111111000");
    laba3:: Signal signal(c1);
    signal.delete_fragment(0, 4);
    ASSERT_EQ(signal.getBSignal(0).level, true);
    ASSERT_EQ(signal.getBSignal(0).duration,3);
    ASSERT_EQ(signal.getn(),2);
}
TEST(BinaryMethods,delete_signal_in_the_middle)
{
    laba3:: Item *c1;
    c1=Get_Item("011111100001111100000001");
    laba3:: Signal signal(c1);
    signal.delete_fragment(5,4);
    ASSERT_EQ(signal.getBSignal(0).level, false);
    ASSERT_EQ(signal.getBSignal(0).duration,1);
    ASSERT_EQ(signal.getBSignal(1).level, true);//что то ссчетом
    ASSERT_EQ(signal.getBSignal(1).duration,4);
    ASSERT_EQ(signal.getn(),6);
    //слиение
}
TEST(BinaryMethods,delete_signal_in_the_mid)
{
    laba3:: Item *c1;
    c1=Get_Item("0111111000001111100000001");
    laba3:: Signal signal(c1);
    signal.delete_fragment(1, 11);
    ASSERT_EQ(signal.getBSignal(1).level, true);//что то ссчетом
    ASSERT_EQ(signal.getBSignal(1).duration,5);
    ASSERT_EQ(signal.getn(),4);
    //еще случай
}
int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
