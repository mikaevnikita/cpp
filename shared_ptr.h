#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <vector>

template<typename T>
class shared_ptr
{
private:
    class storage{
    public:
        T* pObj;
        int count=0;
    };
    int index;
    static std::vector< storage > setOfPointers;
public:
    shared_ptr(T* pObj_=nullptr);
    ~shared_ptr();
    shared_ptr(const shared_ptr<T> &p);
    shared_ptr<T>& operator=(const shared_ptr<T> &p);
    T& operator*();
    T* operator->();
};

template<typename T>
std::vector< typename shared_ptr<T>::storage> shared_ptr<T>::setOfPointers;

template <typename T>
shared_ptr<T>::shared_ptr(T* pObj_){
    bool finded=false;
    for(int i=0;i<setOfPointers.size();i++){
        if(setOfPointers.at(i).pObj==pObj_){
            finded=true;
            index=i;
            setOfPointers.at(index).count++;
            break;
        }
    }
    if(!finded){
        storage tmp;
        tmp.count++;//Эквивалентно tmp.count=1;
        tmp.pObj=pObj_;
        setOfPointers.push_back(tmp);
    }
}

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr<T> &p){
    index=p.index;//Этого достаточно
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T> &p){
    if(index==p.index)
        return *this;//Случай когда p=p;
    if(setOfPointers.at(index).count==1)//То есть текущий указатель единственный, следует удалить
        delete setOfPointers.at(index).pObj;//Удаляем текущий объект
    index=p.index;//Указываем теперь на новый
    return *this;
}


template <typename T>
shared_ptr<T>::~shared_ptr(){
    setOfPointers.at(index).count--;
    if(setOfPointers.at(index).count==0){
        delete setOfPointers.at(index).pObj;
    }
}

template <typename T>
T& shared_ptr<T>::operator*(){
    return *(setOfPointers.at(index).pObj);
}

template <typename T>
T* shared_ptr<T>::operator->(){
    return setOfPointers.at(index).pObj;
}



#endif // SHARED_PTR_H
