#include <iostream>
#include <string>

template <typename T>

struct ListNode {
    T val_;
    ListNode *next_;
    ListNode(T val) : val_(val), next_(nullptr) {} 
    void dump(std::ostream& os) const {
        os << val_;
        ListNode *next = next_;
        while (next) {
            os << " " << next->val_;
            next = next->next_;
        }
        return;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const ListNode<T>& top){
    top.dump(os);
    return os;
}

ListNode<int>* even_odd_list() {
    ListNode<int>* even_list = nullptr;
    ListNode<int>* odd_list = nullptr;

    int x;
    while (std::cin >> x) {
        ListNode<int>* node = new ListNode(x);
        if(x % 2 == 0) { node->next_ = odd_list; odd_list = node;} else{node->next_ = even_list; even_list = node;}
    }
    if(even_list){
        ListNode<int>* current = even_list;
        while(current->next_)
            current = current->next_;
        current->next_ = odd_list;
        return even_list;
    } else return odd_list;
};

int main() {
ListNode<int>* top = even_odd_list();
    std::cout << *top << std::endl;
    return 0;
}