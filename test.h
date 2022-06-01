

#ifndef LAB3_TEST_H
#define LAB3_TEST_H

#include "Student.h"
#include "tree.h"

#include <iostream>

#include <assert.h>
#include <ctime>
#include <cstdio>

#include <chrono>

using namespace std;

bool isNotDivisibleByFive(int a) {
    return !(a % 5);
}



void wood_test(){
    string s = "1 80 10 2 6 14 72 9" ;
    BinaryTree<int> wood(s);
    assert(wood.getSize() == 8);
    wood.insert(5);
    assert(wood.getSize() ==  9);

    BinaryTree<int> treeRes(15);

    bool (*pt2Func2)(int) = nullptr;

    pt2Func2 = &isNotDivisibleByFive;

    wood.where(treeRes, pt2Func2);

    assert(treeRes.getSize() == 1);

}

void time(){
    auto start_time = chrono::high_resolution_clock ::now();

    string s = "1 80 10 2 6 14 72 9 60 50 40 4 6 94 50" ;
    BinaryTree<int> wood(s);

    wood.find(9032156);

    auto end_time = chrono::high_resolution_clock::now();

    chrono::duration<float> duration = end_time - start_time;
    cout << "Time: "<< duration.count() << endl;



}

#endif //LAB3_TEST_H
