class Solution {
public:

    double unsignedPower(double base, int exponent)
    {
        if (0 == exponent)
        {
            return 1;
        }
        if (1 == exponent)
        {
            return base;
        }
        double result = unsignedPower(base, exponent >> 1);
        result = result*result;
        if (exponent & 1==1){
            result = result*base;
        }
        return result;
    }
    double Power(double base, int exponent) {
        if (abs(base - 0.0)<0.0000001&&exponent != 0)
        {
            return 0.0;
        }
        double result = base;
        if (exponent >= 0)
        {
            result = unsignedPower(base, exponent);
        }
        else if (exponent < 0)
        {
            result = unsignedPower(base, -exponent);
            result = 1 / result;
        }
        return result;
    }
};
