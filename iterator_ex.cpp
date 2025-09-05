#include <iostream>
#include <cstring>

class MyString {
private:
    template <typename Iter>
    class MyStringIterator {
        friend class MyString;
    public:
        typedef Iter iterator_type;
        typedef std::forward_iterator_tag iterator_category; // Добавляем синонимы
        typedef ptrdiff_t difference_type; // Корректно вычислять расстояние между 
        typedef iterator_type value_type;
        typedef iterator_type& reference; // ссылка
        typedef iterator_type* pointer; // указатель

        iterator_type* value; // Хранит указатель
    private:
        MyStringIterator(Iter* p) : value(p) {};
    public:
        MyStringIterator(const MyStringIterator& rhs) : value(rhs.value) {};
        bool operator != (const MyStringIterator& rhs) const noexcept {return value != rhs.value; }
        bool operator == (const MyStringIterator& rhs) const noexcept {return value == rhs.value; }
        typedef MyStringIterator::reference operator* () const noexcept {return *value;}
        MyStringIterator& operator++() {++value; return *this;}
        MyStringIterator operator++(int) {
            MyStringIterator tmp = *this;
            ++(*this);
            return tmp; 
        }
    };
private:
    size_t sz_;
    char* str_;
public:
    MyString() : sz_(0), str_(nullptr) {};
    MyString(const char* source) {
        if(source == "") {
            sz_ = 0;
            str_ = nullptr;
        } else {
            sz_ = strlen(source);
            str_ = new char[sz_];
            char* p = str_;
            for (size_t i = 0; i < sz_; ++i) {
                *p = source[i];
                ++p;
            }
        }
    }
    MyString(const MyString& rhs) { // Copy
        if(rhs.sz_ > 0) {
            sz_ = rhs.sz_;
            str_ = new char[sz_];
            char* p = str_;
            char* p_rhs = rhs.str_;
            for (size_t i = 0; i < sz_; ++i) {
                *p = *p_rhs;
                ++p; ++p_rhs;
            }
        } else {
            sz_ = 0;
            str_ = nullptr;
        }
    }
    MyString(MyString&& rhs) : sz_(0), str_(nullptr) {
        std::swap(sz_, rhs.sz_);
        std::swap(str_, rhs.str_);
    }
    ~MyString() {
        if(sz_ > 0) delete[] str_;
    }

    typedef MyStringIterator<char> iterator;
    typedef MyStringIterator<const char> const_siterator;

};
