## virtual function and poly morphism

- up casting: Casting to Base class
- down casting: Casting to Derived class
- polymorphism: virtual keyword, override keyword, virtual destructor, -> dynamic binding at runtime.
- w/o virtual keyword -> current type's method is called.
- with virtual keword -> provides it with polymorphism.
- override keyword is recommended to be spcified, if the base virtual method will be overrided.
- Each object from class having virtual method have vtable pointer.
- abstrace class: class having virtual function initialized with ``= 0;``(pure virtual function)
