class Punto
{
private:
 int x, y; // coordenadas x, y
public:
 Punto(int x_, int y_) // constructor
 {
 x = x_;
 y = y_;
 }
 Punto() { x = y = 0;} // constructor sin argumentos
 int leerX() const; // devuelve el valor de x
 int leerY() const; // devuelve el valor de y
 void fijarX(int valorX); // establece el valor de x
 void fijarY(int valorY); // establece el valor de y
};
