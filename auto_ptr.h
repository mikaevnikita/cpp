#ifndef AUTO_PTR_H
#define AUTO_PTR_H


template<typename T>
class auto_ptr
{
private:
    T *pObj;
public:
    auto_ptr(T *pObj_):pObj(pObj_){}
    ~auto_ptr();
    auto_ptr(auto_ptr<T> &p);
    auto_ptr<T>& operator=(auto_ptr<T> &p);
    T& operator*();
    T* operator->();
};

template <typename T>
auto_ptr<T>::auto_ptr(auto_ptr<T> &p){
    pObj=p.pObj;
    p.pObj=nullptr;
}

template <typename T>
auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<T> &p){
    if(pObj==p.pObj)
        return *this;//Случай когда p=p;
    delete pObj;//Удаляем текущий объект
    pObj=p.pObj;//Указываем на новый
    p.pObj=nullptr;//Указатель старого сбрасываем
    return *this;
}


template <typename T>
auto_ptr<T>::~auto_ptr(){
    delete pObj;
}

template <typename T>
T& auto_ptr<T>::operator*(){
    return *pObj;
}

template <typename T>
T* auto_ptr<T>::operator->(){
    return pObj;
}


#endif // AUTO_PTR_H
