class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        else if(dividend==INT_MIN && divisor==1){
            return INT_MIN;
        }
        bool isNegative = (dividend<0) ^ (divisor<0);

        long long dvd = std::labs((long long)dividend);
        long long dvs = std::labs((long long)divisor);

        long long quotient = 0;

        for(int i = 31 ; i >=0 ; i--){
            if((dvd>>i)>=dvs){
                quotient += (1LL<<i);
                dvd -= (dvs<<i);
            }  
        }

        long long result = isNegative?-quotient:quotient;
        if(result>INT_MAX) return INT_MAX;
        if(result<INT_MIN) return INT_MIN;
        return (int)result;

    }
};