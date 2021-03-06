#ifndef LAB3_TREE_H
#define LAB3_TREE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define way cout << "Choose a detour :\n\t1) KLP\n\t2) KPL\n\t3) LPK\n\t4) LKP\n\t5) PLK\n\t6) PKL\n";

template <class T> class BinaryTree {
private:
    class TreeElement {
    public:
        T data;
        TreeElement* left;
        TreeElement* right;
        TreeElement(T val) {
            left = nullptr;
            right = nullptr;
            data = val;
        }
    };

    TreeElement* root;
    int size;

    void print_tree_KLP(TreeElement* curr) {
        if (curr) {
            std::cout << curr->data << " ";
            print_tree_KLP(curr->left);
            print_tree_KLP(curr->right);
        }
    }
    void print_tree_KPL(TreeElement* curr) {
        if (curr) {
            std::cout << curr->data << " ";
            print_tree_KPL(curr->right);
            print_tree_KPL(curr->left);
        }
    }
    void print_tree_LPK(TreeElement* curr) {
        if (curr) {
            print_tree_LPK(curr->left);
            print_tree_LPK(curr->right);
            std::cout << curr->data << " ";
        }
    }
    void print_tree_LKP(TreeElement* curr) {
        if (curr) {
            print_tree_LKP(curr->left);
            std::cout << curr->data << " ";
            print_tree_LKP(curr->right);
        }
    }
    void print_tree_PLK(TreeElement* curr) {
        if (curr) {
            print_tree_PLK(curr->right);
            print_tree_PLK(curr->left);
            std::cout << curr->data << " ";
        }
    }
    void print_tree_PKL(TreeElement* curr) {
        if (curr) {
            print_tree_PKL(curr->right);
            std::cout << curr->data << " ";
            print_tree_PKL(curr->left);
        }
    }

    void to_str_tree_KLP(TreeElement* curr, string* res) {
        if (curr) {
            *res+= to_string(curr->data) + " ";
            to_str_tree_KLP(curr->left, res);
            to_str_tree_KLP(curr->right, res);
        }
    }
    void to_str_tree_KPL(TreeElement* curr, string* res) {
        if (curr) {
            *res += to_string(curr->data) + " ";
            to_str_tree_KPL(curr->right, res);
            to_str_tree_KPL(curr->left, res);
        }
    }
    void to_str_tree_LPK(TreeElement* curr, string* res) {
        if (curr) {
            to_str_tree_LPK(curr->left, res);
            to_str_tree_LPK(curr->right, res);
            *res += to_string(curr->data) + " ";
        }
    }
    void to_str_tree_LKP(TreeElement* curr, string* res) {
        if (curr) {
            to_str_tree_LKP(curr->left, res);
            *res += to_string(curr->data) + " ";
            to_str_tree_LKP(curr->right, res);
        }
    }
    void to_str_tree_PLK(TreeElement* curr, string* res) {
        if (curr) {
            to_str_tree_PLK(curr->right, res);
            to_str_tree_PLK(curr->left, res);
            *res += to_string(curr->data) + " ";
        }
    }
    void to_str_tree_PKL(TreeElement* curr, string* res) {
        if (curr) {
            to_str_tree_PKL(curr->right, res);
            *res += to_string(curr->data) + " ";
            to_str_tree_PKL(curr->left, res);
        }
    }

    void delete_tree(TreeElement* curr) {
        if (curr && curr->left && curr->right) {
            delete_tree(curr->left);
            delete_tree(curr->right);
            delete curr;
        }
    }

    TreeElement* findValue(int target) {
        if (root->data == target)
            return root;
        return findValueHelper(root, target);
    }

    TreeElement* findValueHelper(TreeElement* ptr, T val) const {
        if (ptr == nullptr)
            return nullptr;
        if (val < ptr->data)
            return findValueHelper(ptr->left, val);
        else if (val > ptr->data)
            return findValueHelper(ptr->right, val);
        else
            return ptr;

    }

    void map(TreeElement* curr, int (*pt2Func1)(int)) {
        if (curr) {
            curr->data = (*pt2Func1)(curr->data);
            map(curr->left, pt2Func1);
            map(curr->right, pt2Func1);
        }
    }

    void where1(BinaryTree<T> tree, TreeElement* curr, bool (*pt2Func2)(int)) {
        if (curr) {
            if ((*pt2Func2)(curr->data))
                tree.insert(curr->data);
            where1(tree, curr->left, pt2Func2);
            where1(tree, curr->right, pt2Func2);
        }
    }
public:
    BinaryTree(T key) {
        root = new TreeElement(key);
        size = 1;
    }

    BinaryTree(string s) {
        s += '.';
        string tmp;
        vector <string> vs;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ' ' || s[i] == '.') {
                vs.push_back(tmp);
                tmp.clear();
            }
            else
                tmp += s[i];
        root = new TreeElement(stoi(vs[0]));
        size = 1;
        for (int i = 1; i < vs.size(); i++)
            insert(stoi(vs[i]));
    }

    ~BinaryTree() {
        delete_tree(root);
    }

    TreeElement* getRoot() {
        return root;
    }

    BinaryTree<T> getSubTree(T target) {
        TreeElement* node = findValue(target);

        BinaryTree<T> newTree(1);
        newTree.root = node;

        return newTree;
    }

    void map(int (*pt2Func1)(int)) {
        map(root, pt2Func1);
    }

    BinaryTree<T> where(BinaryTree<T> tree, bool (*pt2Func)(int)) {
        where1(tree, root, pt2Func);
        return tree;
    }

    void insert(T key) {
        TreeElement* curr = root;
        while (curr && curr->data != key) {
            if (curr->data > key && curr->left == nullptr) {
                curr->left = new TreeElement(key);
                ++size;
                return;
            }
            if (curr->data < key && curr->right == nullptr) {
                curr->right = new TreeElement(key);
                ++size;
                return;
            }
            if (curr->data > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void erase(T key) {
        TreeElement* curr = root;
        TreeElement* parent = nullptr;
        while (curr && curr->data != key) {
            parent = curr;
            if (curr->data > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (!curr)
            return;
        if (curr->left == nullptr) {
            if (parent && parent->left == curr)
                parent->left = curr->right;
            if (parent && parent->right == curr)
                parent->right = curr->right;
            --size;
            delete curr;
            return;
        }
        if (curr->right == nullptr) {
            if (parent && parent->left == curr)
                parent->left = curr->left;
            if (parent && parent->right == curr)
                parent->right = curr->left;
            --size;
            delete curr;
            return;
        }
        TreeElement* replace = curr->right;
        while (replace->left)
            replace = replace->left;
        T replace_value = replace->data;
        erase(replace_value);
        curr->data = replace_value;
    }

    int getSize() {
        return this->size;
    }

    string saveTreeToString() {
        std::cout << "1) KLP\n2) KPL\n3) LPK\n\t4) LKP\n\t5) PLK\n\t6)  PKL\n";
        int order1;
        std::cin >> order1;

        string result = "";

        switch (order1) {
            case 1:
                to_str_tree_KLP(root, &result);
                break;
            case 2:
                to_str_tree_KPL(root, &result);
                break;
            case 3:
                to_str_tree_LPK(root, &result);
                break;
            case 4:
                to_str_tree_LKP(root, &result);
                break;
            case 5:
                to_str_tree_PLK(root, &result);
                break;
            case 6:
                to_str_tree_PKL(root, &result);
                break;

        }

        return result;
    }

    string saveTreeToString(int i) {
        string result = "";
        to_str_tree_KLP(root, &result);
        return result;
    }

    bool isTreeEntry(BinaryTree<T> tree) {
        return saveTreeToString(1).find(tree.saveTreeToString(1)) != std::string::npos;
    }

    bool find(T key) {
        TreeElement* curr = root;
        while (curr && curr->data != key) {
            if (curr->data > key)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return curr != nullptr;
    }

    static bool equals(TreeElement* t1, TreeElement* t2) {
        if (t1 == t2)
            return true;
        if ((t1 == nullptr) || (t2 == nullptr))
            return false;
        return ((t1->data == t2->data) && equals(t1->left, t2->left) && equals(t1->right, t2->right));
    }

    void print() {
        way;
        int order;
        cin >> order;
        switch (order) {
            case 1:
                print_tree_KLP(root);
                break;
            case 2:
                print_tree_KPL(root);
                break;
            case 3:
                print_tree_LPK(root);
                break;
            case 4:
                print_tree_LKP(root);
                break;
            case 5:
                print_tree_PLK(root);
                break;
            case 6:
                print_tree_PKL(root);
                break;


        }
        cout << "\n";
    }

    void prettyPrint(TreeElement* node, string const& rpref = "", string const& cpref = "", string const& lpref = "") {
        if (!node)
            return;
        if (node->right)
            prettyPrint(node->right, rpref + "  ", rpref + "/-", rpref + "| ");
        cout << cpref << node->data << std::endl;
        if (node->left)
            prettyPrint(node->left, lpref + "| ", lpref + "\\-", lpref + "  ");
    }
};

#endif
