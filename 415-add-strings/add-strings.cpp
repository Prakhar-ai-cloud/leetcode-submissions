class Solution {
public:
    string addStrings(string num1, string num2) {
        string temp;
        if(num1.size()> num2.size()){
            string temp = "";
            for(int i=0;i<num1.size()-num2.size();i++) temp += '0';
            temp += num2;
            num2 = temp;
        }
        else if(num2.size()>num1.size()){
            string temp = "";
            for(int i=0;i<num2.size()-num1.size();i++) temp += '0';
            temp += num1;
            num1 = temp;
        }

        int carry = 0;
        for(int i=num1.size()-1;i>=0;i--){
            int sum = (num1[i]-'0')+(num2[i]-'0') + carry;
            carry = sum/10;
            num1[i] = sum%10 + '0';
        }
         if(carry)
            num1 = '1' + num1;
        return num1;
    }
};