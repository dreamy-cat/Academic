#include "chapter_16.h"

using namespace std;

template<class T> TStack<T>::Link::Link(T* dat, Link* nxt) : data(dat), next(nxt) {}

template<class T> TStack<T>::TStack() : head(0) {}

template<class T> TStack<T>::~TStack() {
    while (head)
        delete pop();
}

template<class T> void TStack<T>::push(T* dat) {
    head = new Link(dat, head);
}

template<class T> T* TStack<T>::pop() {
    if (head == 0) return 0;
    T* result = head->data;
    Link* oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}

template<class T> T* TStack<T>::peek() const {
    if (head != 0) return head->data; else return 0;
}

template<class T> TStack<T>::iterator::iterator(const TStack<T> &tl) : sp(tl.head) {}

template<class T> TStack<T>::iterator::iterator(const iterator& tl) : sp(tl.sp) {}

template<class T> TStack<T>::iterator::iterator() : sp(0) {}

template<class T> bool TStack<T>::iterator::operator ++() {
    if (sp->next != 0) sp = sp->next; else sp = 0;
    return bool(sp);
}

template<class T> bool TStack<T>::iterator::operator ++(int) {
    return operator ++();
}

template<class T> T* TStack<T>::iterator::current() const {
    if (sp == 0) return 0; else return sp->data;
}

template<class T> T* TStack<T>::iterator::operator->() const {
    if (sp == 0) return 0; else return current();

}

template<class T> T* TStack<T>::iterator::operator *() const {
    return current();
}

