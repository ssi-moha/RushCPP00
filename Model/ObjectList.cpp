#include "ObjectList.hpp"

ObjectList::ObjectList() {
    
}
ObjectList::~ObjectList() {
    
}

ObjectList       &ObjectList::operator=(ObjectList const & rhs) {
    if ( this != &rhs )
    {
        this->_first = rhs._name;
    }
    return *this;
}