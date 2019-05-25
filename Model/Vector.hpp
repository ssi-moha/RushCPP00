#ifndef VECTOR_H
# define VECTOR_H
# include <sstream>

class Vector {

public:

    Vector( void );
    Vector(int x, int y);
    Vector(Vector const & src);
    ~Vector( void );

    Vector &    operator=(Vector const & rhs);
    Vector      operator+(Vector const & rhs);
    bool        operator==(Vector const & rhs);

    int         getAbsciss( void )      const;
    int         getOrdinate( void )    const;
    void        setAbsciss( int new_x );
    void        setOrdinate( int new_y );

private:

    int _x;
    int _y;

};

std::ostream & operator<<(std::ostream & o, Vector const & rhs);

#endif