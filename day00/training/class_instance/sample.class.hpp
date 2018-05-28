#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class sample {
public:

    float           pi;
    int             qd; 

    sample(float const f);
    ~sample(void);

    void    bar(void) const;
};

#endif