def gcd(a,b):
    rem=1       #Initializing the variable rem to 1
    if(a==0):   #If a is 0 then return b
        return b
    elif(a<b):  
        return 0
    else:
        while(rem>0):
            rem=a%b     #Calculates the remainder of 2 numbers 
            print("\n",a,"=",b,"(",a//b,") + ",rem)
            if(rem!=0):     #If remainder is not zero
                a=b         #new values to a and b are assigned
                b=rem
            else:
                return b


print("---First Number Should be the greater than second number---\n")
num1=int(input("Enter the First Number: "))
num2=int(input("Enter Second Number: "))

d=gcd(num1,num2)

if(d==0):
    print("ERROR! First number should be greater.")
else:
    print("\ngcd(",num1,",",num2,") =",d)
