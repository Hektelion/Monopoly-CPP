#ifndef DES_HPP
#define DES_HPP
 
class DES
{

private:
    int d1;
    int d2;
    int tot;

public:
    DES();
    ~DES();
    void lancer();
    int get_tot();
    int get_d1();
    int get_d2();
    bool is_double();
    
};

#endif