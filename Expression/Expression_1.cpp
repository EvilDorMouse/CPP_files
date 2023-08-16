struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}

    double evaluate() const
    {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    // "op" - это один из 4 символов: '+', '-', '*' или '/'
    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    { }

    double evaluate() const
    {
        if (op == '+')
            return left->evaluate() + right->evaluate();

        if (op == '-')
            return left->evaluate() - right->evaluate();

        if (op == '*')
            return left->evaluate() * right->evaluate();

        if (op == '/')
            return left->evaluate() / right->evaluate();
    }
    
    ~BinaryOperation()
    {
        delete left;
        delete right;
    }


private:
    Expression const* left;
    Expression const* right;
    char op;
};