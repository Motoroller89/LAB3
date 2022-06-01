#include <iostream>

using namespace std;





#include <string>
#include <vector>
#include "Student.h"
#include "tree.h"
#include "test.h"

#define menu cout<< "1) Map\n" \
"2) Where\n" \
"3) Merge\n" \
"4) Extracting a subtree\n" \
"5) Search for an entry subtree\n" \
"6) Student\n" \
"7) Teachers\n" \
"8) Insert new elenmt\n"\
"9) Test" << endl;

/* 6 и 7 - Структруа студентов и учителей(Имя фамлиия отечество возраст) */


int multi(int a) {
    return a * 5;
}

int main()
{

    menu;
    while (1) {
        int function_selection;
        cin >> function_selection;


        string s = "5 9 10 4 2 6 8 5 4 2 619 51 40 10 13 16";

        BinaryTree<int> tree(s);
        switch (function_selection) {
            ///Функия map умножает все числа на 5///
            case 1:{
                int (*func)(int);
                func = &multi;
                tree.map(func);
                cout << "sucess!\n";
                tree.prettyPrint(tree.getRoot());
                break;
            }

            case 2:{
                ///Функия where берет те числа, которые деляется на  5 только///
                BinaryTree<int> treeRes(15);

                bool (*pt2Func2)(int) = nullptr;

                pt2Func2 = &isNotDivisibleByFive;

                tree.where(treeRes, pt2Func2);

                treeRes.prettyPrint(treeRes.getRoot());
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                cout << "Enter element: ";
                int newRoot;
                cin >> newRoot;
                tree.getSubTree(newRoot).print();
                break;
            }

            case 5:{
                tree.print();
            }

            case 6:{
                Student st1(15, "Jhon", "Igor", "Krapov");
                Student st2(22, "Chelkov", "Karina", "Loger");
                Student st3(1, "Gromov", "Kurov", "Petriv");
                Student st4(9, "Volkov", "Volkov", "Ikovlevich");
                Student st5(7, "Cmochnik", "Merin", "Demid");
                Student st6(22, "Tripov", "KArl", "Petrov");

                BinaryTree<Student> tree_bin(st1);
                tree_bin.insert(st2);
                tree_bin.insert(st3);
                tree_bin.insert(st4);
                tree_bin.insert(st5);
                tree_bin.insert(st6);

                tree_bin.prettyPrint(tree_bin.getRoot());
                break;
            }

            case 7:{
                Student st1(100, "Sidorov", "Igor", "Lover");
                Student st2(99, "Chelkov", "Susanna", "Loger");
                Student st3(90, "Aduskina", "Semen", "Lidlov");
                Student st4(98, "Matemativ", "Artur", "CMoniv");


                BinaryTree<Student> tree_bin(st1);
                tree_bin.insert(st2);
                tree_bin.insert(st3);
                tree_bin.insert(st4);


                tree_bin.prettyPrint(tree_bin.getRoot());
                break;
            }
            case 8:{
                cout << "New elemnt: ";
                int newElem;
                cin >> newElem;
                tree.insert(newElem);
                cout << "Good job!\n";
                tree.prettyPrint(tree.getRoot());
                break;
            }

            case 9:{
                ///Один тест проверяет время другой просто правильность работы функции///
                time();
                wood_test();

            }
        }



        return 0;
    }

}
