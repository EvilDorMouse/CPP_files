struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) 
    {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) 
    {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) 
    {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) 
    {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }


    void neg() 
    {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const 
    {
        return numerator_ / (double)denominator_;
    }

    operator double() const
    {
        return (double)this->numerator_/this->denominator_;
    }

    int get_numer() const
    {
        return this->numerator_;
    }

    int get_deno() const
    {
        return this->denominator_;
    }
    
    
    Rational& operator+= (Rational const& a)
    {
        this->add(a);
        return *this;
    }
    
    Rational& operator-= (Rational const& a)
    {
        this->sub(a);
        return *this;
    }

    Rational& operator*= (Rational const& a)
    {
        this->mul(a);
        return *this;
    }

    Rational& operator/= (Rational const& a)
    {
        this->div(a);
        return *this;
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+ (Rational a)
{
    return a;
}

Rational operator- (Rational a)
{
    a.neg();
    return a;
}

Rational operator* (Rational a, Rational const& b)
{
    return a *= b;
}

Rational operator/ (Rational a, Rational const& b)
{
    return a /= b;
}

bool operator== (Rational const & a, Rational const & b)
{
    if ((a.get_deno() == b.get_deno()) && (a.get_numer() == b.get_numer()))
        return true;
    else
        return false;
}

bool operator!= (Rational const & a, Rational const & b)
{
    return !(a == b);
}

bool operator< (Rational const & a, Rational const & b)
{
    double d1 = (double)a.get_numer() / a.get_deno();
    double d2 = (double)b.get_numer() / b.get_deno();
    if (d1 < d2)
        return true;
    else
        return false;
}

bool operator> (Rational const & a, Rational const & b)
{
    return b < a;
}

bool operator<= (Rational const & a, Rational const & b)
{
    return !(b < a);
}
 
bool operator>= (Rational const & a, Rational const & b)
{
    return !(a < b);
}