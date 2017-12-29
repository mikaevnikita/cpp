
#include <unordered_map>
template<typename T>
class shared_ptr
{
private:
    static std::unordered_map<T*,int> setOfPointers;
    typename std::unordered_map<T*,int>::iterator iter;
public:
    shared_ptr(T* pObj_=nullptr);
    ~shared_ptr();
    shared_ptr(const shared_ptr<T> &p);
    shared_ptr<T>& operator=(const shared_ptr<T> &p);
    T& operator*();
    T* operator->();
};

template<typename T>
std::unordered_map<T*,int> shared_ptr<T>::setOfPointers = std::unordered_map<T*,int>();

template <typename T>
std::unordered_map<T*,int> setOfPointers;

template <typename T>
shared_ptr<T>::shared_ptr(T* pObj_){
    if((iter=setOfPointers.find(pObj_))!=setOfPointers.end())
        iter->second++;
    else{
        std::pair<typename std::unordered_map<T*,int>::iterator,bool> pr=setOfPointers.insert(std::make_pair(pObj_,1));
        iter=pr.first;
    }
}

template <typename T>
shared_ptr<T>::shared_ptr(const shared_ptr<T> &p){
    iter=p.iter;
}

template <typename T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T> &p){
    if(iter->first == p.iter->first)
        return *this;//Случай когда указывает на один и тот же объект;
    if(iter->second==1){//То есть текущий указатель единственный, следует удалить
        delete iter->first;//Удаляем объект
        setOfPointers.erase(iter);//Удаляем пару ключ-значение
    }
    iter=p.iter;//Указываем теперь на новый
    return *this;
}


template <typename T>
shared_ptr<T>::~shared_ptr(){
    iter->second--;
    if(iter->second==0){
        delete iter->first;
        setOfPointers.erase(iter);
    }
}

template <typename T>
T& shared_ptr<T>::operator*(){
    return *(iter->first);
}

template <typename T>
T* shared_ptr<T>::operator->(){
    return iter->first;
}
