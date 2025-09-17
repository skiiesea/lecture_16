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

int main() {
    ListNode<int>* top = new ListNode(1);
    top->next_ = new ListNode<int>(2);
    top->next_->next_ = new ListNode<int>(3);
    std::cout << *top;
    return 0;

}