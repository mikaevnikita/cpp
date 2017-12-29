#ifndef SUPER_TYPE_H
#define SUPER_TYPE_H

#include <typeinfo>

class SuperType
{
public:
    SuperType();

    template<typename ValueType>
    SuperType(const ValueType& t);

    template<typename CastType>
    CastType cast() const;

    template<typename ValueType>
    SuperType& operator=(const ValueType& t);
private:
    class BaseHolder
    {
    public:
        virtual ~BaseHolder() {}
        virtual const std::type_info& type_info() const = 0;
    };

    template<typename ValueType>
    struct Holder : BaseHolder
    {
        Holder(const ValueType& value)
            :_value(value) {}

        const std::type_info& type_info() const
        {
            return typeid(_value);
        }

        ValueType _value;
    };
private:
    BaseHolder* _held;
};

template <typename ValueType>
SuperType& SuperType::operator=(const ValueType& t){
    delete _held;
    _held = new Holder<ValueType>(t);
    return *this;
}


SuperType::SuperType()
    :_held(nullptr)
{}

template <typename ValueType>
SuperType::SuperType(const ValueType& value)
    :_held(new Holder<ValueType>(value))
{}

template <typename CastType>
CastType SuperType::cast() const
{
    if(typeid(CastType) != _held->type_info())
        throw std::bad_cast();

    return static_cast<Holder<CastType>*>(_held)->_value;
}

#endif
