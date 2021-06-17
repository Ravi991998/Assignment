#include <iostream>
#include <string>
#include<math.h>

using namespace std;

const string units[] = {"" ,"One ","Two ","Three ","Four ","Five ","Six ","Seven ",
                "Eight ","Nine ","Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ",
                "Sixteen ","Seventeen ","Eighteen ","Nineteen "};
 
const string tens[] = {"" ,"" ,"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};

unsigned long long int num1;
 
string indianwords(int n, string words)
{
    if (n == 0)
    {
        return "";
    }
    
    if (n > 19)
    {
        return tens[n/10] + units[n%10] + words;
    }
    else 
    {
        return units[n] + words;
    }
}

string convertindian(unsigned long long int n)
{
    string res;
    int i,j;
    res = indianwords((n % 1000), "");
 
    if (n>100)
    {
        res = "and " + res;
    }
     
    res = indianwords(((n / 100) % 10), "Hundred ") + res;
    res = indianwords(((n / 1000) % 100), "Thousand, ") + res;
    res = indianwords(((n / 100000) % 100), "Lakh, ") + res;
    res = indianwords(((n / 10000000) % 100), "Crore, ") + res;
    res = indianwords(((n / 1000000000) % 100), "Arab, ") + res;
    res = indianwords(((n / 100000000000) % 100), "Kharab, ") + res;
    res = indianwords(((n / 10000000000000) % 100), "Nil, ") + res;
    res = indianwords(((n / 1000000000000000) % 100), "Padma, ") + res;
    res = indianwords(((n / 100000000000000000) % 100), "Shankha, ") + res;

    return res;
}

string americanwords(int n, string words)
{
    string sol="";

    if (n == 0)
    {
        return "";
    }

    if ((n/100) > 0)
    {
        sol += units[n/100] + "Hundred ";
    }
          
    if ((n%100) > 19)
    {
        return sol + tens[(n%100) / 10] + units[(n%100) % 10] + words;
    }
    else 
    {
        return sol+ units[n%100] + words;
    }
}

string convertamerican(unsigned long long int n)
{
    string res;
  
    res = americanwords((n % 1000), "");
    res = americanwords(((n / 1000) % 1000), "Thousand ") + res;
    res = americanwords(((n / 1000000) % 1000), "Million, ") + res;
    res = americanwords(((n / 1000000000) % 1000), "Billion, ") + res;
    res = americanwords(((n / 1000000000000) % 1000), "Trillion, ") + res;
    res = americanwords(((n / 1000000000000000) % 1000), "Quadrillion, ") + res;
    res = americanwords(((n / 1000000000000000000) % 1000), "Quintillion, ") + res;
    res = americanwords(((n / 1000000000000000000000) % 1000), "Sextillion, ") + res;
   
    return res;
}
 
int main()
{
    
    while(1)
    {
        cout<<"\n\nEnter the Figure to Convert(-1 to exit): ";
        cin>>num1;

        if(num1==0)
        {
            cout<<"WORDS:===== Zero";
            continue;
        }
        if(num1==-1)
            break;
        
        if(num1>pow(10,19))
            cout<<"Entered Number is Out of Range!!!!";
        else
        {
            cout<<"\nINDIAN WORDS:===== "+convertindian(num1);
            cout<<"\n\nAMERICAN WORDS:===== "+convertamerican(num1);
        }    
    }
    return 0;
}
