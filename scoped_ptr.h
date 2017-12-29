#ifndef SCOPED_PTR_H
#define SCOPED_PTR_H


template<typename T>
class scoped_ptr
{
private:
    T *pObj;
    scoped_ptr(const scoped_ptr<T> &scptr);
    scoped_ptr<T>& operator=(const scoped_ptr<T> &scptr);
public:
    scoped_ptr(T *pObj_):pObj(pObj_){}
    ~scoped_ptr();
    T& operator*();
    T* operator->();
};

template <typename T>
scoped_ptr<T>::~scoped_ptr(){
    delete pObj;
}

template <typename T>
T& scoped_ptr<T>::operator*(){
    return *pObj;
}

template <typename T>
T* scoped_ptr<T>::operator->(){
    return pObj;
}


#endif // SCOPED_PTR_H
