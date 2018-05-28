#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class sample {

public:

    sample(void);
    ~sample(void);

    int     getFoo(void) const;
    void    setFoo(int v);

private:

    int     _foo;

};

#endif