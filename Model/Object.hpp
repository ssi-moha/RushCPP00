#ifndef OBJECT_H
# define OBJECT_H

class AMovingObject;

class Object {

public:

    
    Object(AMovingObject *elem, Object *next);
    Object(Object const & src);
    ~Object( void );

    Object &  operator=(Object const & rhs);

    Object  *getNext()const;
    void    setNext(Object *next);
    AMovingObject  *getElem();

private:
    Object( void );
    AMovingObject *_elem;
    Object *_next;
    
};

#endif