#include <bits/stdc++.h>
using namespace std;
class biginteger
{
private:
    string value;

public:
    biginteger(int n)   ///constructor overloading
    {
        value = to_string(n);
    }
    biginteger(string str)  ///constructor overloading
    {
        value = str;
    }

    int length()
    {
        return value.length();
    }
    string character()   
    {
        return value;
    }

////////////// COMPARE ////////////////
    int compareTo(biginteger x) 
    {
        int neg = 0;

        string s1 = this->character();
        string s2 = x.character();

        if (s1[0] == '-' && s2[0] != '-')
            return -1;
        if (s1[0] != '-' && s2[0] == '-')
            return 1;
        if (s1[0] == '-' && s2[0] == '-')
        {
            s1.erase(0, 1);
            s2.erase(0, 1);
            neg = 1;
        }
        if (s1[0] != '-' && s2[0] != '-')
        {
            // if (s1[0] == '0' || s2[0] == '0')
            //     return "Invalid Input";
            if (s1.length() > s2.length())
            {
                if (neg == 1)
                    return -1;
                else
                    return 1;
            }
            if (s1.length() < s2.length())
            {
                if (neg == 1)
                    return 1;
                else
                    return -1;
            }
            if (s1.length() == s2.length())
            {
                for (int i = 0; i < s1.length(); i++)
                {
                    if (s1[i] > s2[i])
                    {
                        if (neg == 1)
                            return -1;
                        else
                            return 1;
                    }
                    if (s1[i] < s2[i])
                    {
                        if (neg == 1)
                            return 1;
                        else
                            return -1;
                    }
                }
            }
        }
        return 0; //if both of them are equal
    }
////////////// COMPARE ////////////////


//////////////// ADDITTION  ////////////////
    string add(biginteger x)
    {
        string str1, str2;
        str1 = this->character();
        str2 = x.character();
        if ((str1[0] == '-' && str2[0] != '-') || (str1[0] != '-' && str2[0] == '-'))
            return "ERROR 404!\nPlease use the findDiff() method!";
        int neg = 0;
        if (str1[0] == '-' && str2[0] == '-')
            neg = 1;
        if (neg == 1)
        {
            str1.erase(0, 1);
            str2.erase(0, 1);
            
        }

        if (str1.length() > str2.length())
            swap(str1, str2);

        string str = "";

        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;

        int carry = 0;

        for (int i = n1 - 1; i >= 0; i--)
        {

            int sum = ((str1[i] - '0') + (str2[i + diff] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        for (int i = diff - 1; i >= 0; i--)
        {
            int sum = ((str2[i] - '0') + carry);
            str.push_back(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)
            str.push_back(carry + '0');

        reverse(str.begin(), str.end());

        if (neg)
        {
            str = '-' + str;
        }
        while (str[0] == '0')
        {
            str.erase(0, 1);
        }

        return str;
    }
///////////////// ADDITION ////////////////


//////////////  MULTIPLICATION   //////////////////
    string multiply(biginteger x)
    {
        int neg = 0;
        string str1, str2;
        str1 = this->character();
        str2 = x.character();
        if ((str1[0] == '-' && str2[0] != '-') || (str1[0] != '-' && str2[0] == '-'))
        {
            neg = 1;
        }
        if (str1[0] == '-' && str2[0] == '-')
        {
            neg = 2;
        }
        if (neg == 1)
        {
            if (str1[0] == '-')
            {
                str1.erase(0, 1);
            }
            else
            {
                str2.erase(0, 1);
            }
        }
        else if (neg == 2)
        {
            str1.erase(0, 1);
            str2.erase(0, 1);
        }
        if (str1.length() > str2.length())
            swap(str1, str2);

        string s, res = "0";
        int carry, n1, n2, count = 0;
        n1 = str1.length();
        n2 = str2.length();
        for (int i = n1 - 1; i >= 0; i--)
        {
            s = "";
            carry = 0;
            for (int j = n2 - 1; j >= 0; j--)
            {
                int pro = (str1[i] - '0') * (str2[j] - '0') + carry;
                s.push_back(pro % 10 + '0');
                carry = pro / 10;
            }
            if (carry)
                s.push_back(carry + '0');

            reverse(s.begin(), s.end());

            for (int k = 1; k <= count; k++)
                s.push_back('0');

            count++;

            biginteger a(res);
            biginteger b(s);
            res = a.add(b);
        }
        while (res[0] == '0')
        {
            res.erase(0, 1);
        }

        if (neg == 1)
        {
            res = "-" + res;
        }

        return res;
    }
/////////////// MULTIPLICATION /////////////////




/////////////// SUBSTRACTION //////////////////


// Function for finding difference of larger numbers
string findDiff(biginteger x)
{   string str1=this->character();
    string str2= x.character();

    // Before proceeding further, make sure str1 is not smaller

    biginteger a(str1);
    biginteger b(str2);

    if (a.compareTo(b) == -1)
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i = n2 - 1; i >= 0; i--) {
        // Do school mathematics, compute difference of
        // current digits and carry
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0')
                   - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of str1[]
    for (int i = n1 - n2 - 1; i >= 0; i--) {
        if (str1[i] == '0' && carry) {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0) // remove preceding 0's
            str.push_back(sub + '0');
        carry = 0;
    }

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

//// SUBSTRACTION ////////


//////////// FACTORIAL!  ////////////////
    string factorial()
    {   int n=stol(this->character());
        if (n < 0)
        {
            return "Error 404! factorial of negative number not possible";
        }
        // string pro = "1";
        biginteger p("1");

        for (int i = 1; i <= n; i++)
        {
            biginteger itr(to_string(i));
            p.value = p.multiply(itr);
        }
        return p.value;
    }
//////////// FACTORIAL!  ////////////////


    
///////////  POWER    /////////////////
    string power(biginteger x)
    {
        string str = this->character();
        int n=stol(x.character());
        if(n==0) return "1";
        
        int neg = 0;
        if (str[0] == '-')
        {
            neg = 1;
            str.erase(0, 1);
        }
        biginteger p(str);
        for (int i = 1; i < n; i++)
        {
            p.value = p.multiply(str);
        }

        if(neg==1){
            if(n%2==1){
                p.value="-"+p.value;
            }
        }

        return p.value;
    }
////////// POWER  ////////////////////


/////////  ABSOLUTE  /////////////////
    string absolute()
    {
        string s = this->character();
        if (s[0] == '-')
        {
            s.erase(0, 1);
        }

        return s;
    }
///////// ABSOLUTE /////////////////



////////////////////DIVIDE////////////////////////////

pair<string,long long int> divideby(biginteger x)
{
    string num=this->character();
    long long int m=stol(x.character());
	// Store the modulus of big number
	vector<int> vec;
	long long int mod = 0;

	// Do step by step division
	for (int i = 0; i < num.size(); i++) {
		
		int digit = num[i] - '0';

		// Update modulo by concatenating
		// current digit.
		mod = mod * 10 + digit;

		// Update quotient
		long long int quo = mod / m;
		vec.push_back(quo);

		// Update mod for next iteration.
		mod = mod % m;	
	}
    pair<string,long long int>p;
    string ans="";
	// cout << "\nRemainder : " << mod << "\n";

	// cout << "Quotient : ";

	// Flag used to remove starting zeros
	int zeroflag = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 0 && zeroflag == 0)
			continue;
		zeroflag = 1;
		ans+=to_string(vec[i]);
	}
    if(zeroflag==0)ans+="0";

    p={ans,mod};

	return p;
}

////////////////////DIVIDE////////////////////////////


////////////////////DECIMAL TO BINARY////////////////////////////
string tobinary(){
    string s= this->character();

    string binary="";

    pair<string,long long int>p;
    while(s!="0"){
        biginteger a(s);
        biginteger b("2");
        p=a.divideby(b);
        binary+=to_string(p.second);
        s=p.first;
    }
    reverse(binary.begin(),binary.end());

    return binary;
}

////////////////////DECIMAL TO BINARY////////////////////////////

////////////////////LOGICAL NOT////////////////////////////
string NOT(){
    string s=this->character();
    biginteger a(s);
    string bin = a.tobinary();
    for(int i=0;i<bin.size();i++){
        if(bin[i]=='1'){
            bin[i]='0';
        }
        else{
            bin[i]='1';
        }
    }
    
    return bin;
}
////////////////////LOGICAL NOT////////////////////////////

////////////////////LOGICAL AND////////////////////////////
string AND(biginteger x){
    string s1=this->character();
    string s2=x.character();

    biginteger a(s1);
    biginteger b(s2);
    string bin1 = a.tobinary();
    string bin2 = b.tobinary();
    string bin="";
    int n1,n2;
    n1=max(bin1.size(),bin2.size());
    n2=min(bin1.size(),bin2.size());
     
    if(bin1.size()<bin2.size()){
        bin1.swap(bin2);
    }

    for(int i=0;i<n1-n2;i++){
        bin2='0'+bin2;
    }

    for(int i=0;i<n1;i++){
        bin[i]=((bin1[i]-'0')&(bin2[i]-'0'))+'0';
    }

    return bin;
}
////////////////////LOGICAL AND////////////////////////////


////////////////////LOGICAL OR////////////////////////////
string AND(biginteger x){
    string s1=this->character();
    string s2=x.character();

    biginteger a(s1);
    biginteger b(s2);
    string bin1 = a.tobinary();
    string bin2 = b.tobinary();
    string bin="";
    int n1,n2;
    n1=max(bin1.size(),bin2.size());
    n2=min(bin1.size(),bin2.size());
     
    if(bin1.size()<bin2.size()){
        bin1.swap(bin2);
    }

    for(int i=0;i<n1-n2;i++){
        bin2='0'+bin2;
    }

    for(int i=0;i<n1;i++){
        bin[i]=((bin1[i]-'0')|(bin2[i]-'0'))+'0';
    }

    return bin;
}
////////////////////LOGICAL OR////////////////////////////

////////////////////LOGICAL XOR////////////////////////////
string AND(biginteger x){
    string s1=this->character();
    string s2=x.character();

    biginteger a(s1);
    biginteger b(s2);
    string bin1 = a.tobinary();
    string bin2 = b.tobinary();
    string bin="";
    int n1,n2;
    n1=max(bin1.size(),bin2.size());
    n2=min(bin1.size(),bin2.size());
     
    if(bin1.size()<bin2.size()){
        bin1.swap(bin2);
    }

    for(int i=0;i<n1-n2;i++){
        bin2='0'+bin2;
    }

    for(int i=0;i<n1;i++){
        bin[i]=((bin1[i]-'0')^(bin2[i]-'0'))+'0';
    }

    return bin;
}
////////////////////LOGICAL XOR////////////////////////////



};
