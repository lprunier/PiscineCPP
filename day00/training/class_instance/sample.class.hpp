#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class sample {

public:

    int     publicFoo;

    sample(void);
    ~sample(void);

    void    publicBar(void) const;

private:

    int     _privateFoo;

    void    _privateBar(void) const;
};

#endif