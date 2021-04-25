""" Here 0,1,2,3 = M1,M2,M3,M4 man respectively 
    and 0,1,2,3 = W1,W2,W3,W4 woman respectively """


def stableMatching(num, menPref, womenPref):
    unmarriedMen = list(range(num))
    manSpouse = [None] * num                      
    womanSpouse = [None] * num                      
    nextManChoice = [0] * num                       
    
    # This loop will work While there exists at least one unmarried man:
    while unmarriedMen:

        he = unmarriedMen[0]                      
        hisPref = menPref[he]
        
        # Find a woman to propose to
        she = hisPref[nextManChoice[he]] 
        herPref = womenPref[she]
        
        # Find the present husband of the selected woman (it might be None)
        currentHusband = womanSpouse[she]
       
        
        # Now "he" proposes to "she" or Vice versa. 
        # Decide whether "she" accepts, and update the following fields
        if currentHusband == None:
          #"She" accepts any proposal
          womanSpouse[she] = he
          manSpouse[he] = she
          #"His" nextchoice is the next woman in the hisPreferences list
          nextManChoice[he] = nextManChoice[he] + 1
          
          #Delete "him" from the Unmarried list
          unmarriedMen.pop(0)
        else:
          #Husband exists
          #Check the preferences of the current husband and that of the proposed man's
          currentIndex = herPref.index(currentHusband)
          hisIndex = herPref.index(he)
          
          #Accept the proposal if "he" has higher preference in herPreference list
          if currentIndex > hisIndex:
             #New stable match is found for "her"
             womanSpouse[she] = he
             manSpouse[he] = she
             nextManChoice[he] = nextManChoice[he] + 1
             
             #Pop the newly wed husband
             unmarriedMen.pop(0)
             
             #Now the previous husband is unmarried add
             #him to the unmarried list
             unmarriedMen.insert(0,currentHusband)
          else:
             nextManChoice[he] = nextManChoice[he] + 1
             
           
            
    return manSpouse

def displayman(a):
    print("\t----Men as Proposing Group----\n")
    print("Final Pairs\n")
    print("M1 = ",a[0])
    print("M2 = ",a[1])
    print("M3 = ",a[2])
    print("M4 = ",a[3])
    print("Note: Here 0 = W1, 1 = W2, 2 = W3, 3 = W4")
    print("\n")
    
def displaywoman(b):
    print("\t----Woman as Proposing Group----\n")
    print("Final Pairs\n")
    print("W1 = ",b[0])
    print("W2 = ",b[1])
    print("W3 = ",b[2])
    print("W4 = ",b[3])
    print("Note: Here 0 = M1, 1 = M2, 2 = M3, 3 = M4")
    
def stability(q,r):
    if (q==r):
        print("\nHence, Marriage is Stable\n")
    else:
        print("\nHence, Marriage is Unstable\n")
        
      
    
print("\n\t------------EXAMPLE 1 - Preferences------------")
print("\nM1,M2,M3,M4 - represents Man and W1,W2,W3,W4 - represents Woman\n")
print("M1 = W3,W2,W4,W1        W1 = M1,M2,M4,M3")
print("M2 = W2,W1,W3,W4        W2 = M3,M1,M4,M2")
print("M3 = W3,W1,W4,W2        W3 = M3,M2,M4,M1")
print("M4 = W3,W1,W4,W2        W4 = M2,M1,M3,M4")
print("\n")

k= [[2,1,3,0],[1,0,2,3],[2,0,3,1],[2,0,3,1]]
j= [[0,1,3,2],[2,0,3,1],[2,1,3,0],[1,0,2,3]]

"""Boy proposing grp"""
x = stableMatching(4, k, j)
displayman(x)

"""girl proposing group"""    
y = stableMatching(4, j, k) 
displaywoman(y)

"""Stable or Unstable"""
stability(x, y)
    
    

print("\n\n")  

print("\t------------EXAMPLE 2 - Preferences------------")
print("\nM1,M2,M3,M4 - represents Man and W1,W2,W3,W4 - represents Woman\n")
print("M1 = W2,W4,W1,W3        W1 = M2,M1,M4,M3")
print("M2 = W3,W1,W4,W2        W2 = M4,M3,M1,M2")
print("M3 = W2,W3,W1,W4        W3 = M1,M4,M3,M2")
print("M4 = W4,W1,W3,W2        W4 = M2,M1,M4,M3")
print("\n")

l = [[1,3,0,2],[2,0,3,1],[1,2,0,3],[3,0,2,1]]
m = [[1,0,3,2],[3,2,0,1],[0,3,2,1],[1,0,3,2]]

"""Boy proposing group"""
v = stableMatching(4, l, m)
displayman(v)

"""Girl Proposing group""" 
w = stableMatching(4, m, l)
displaywoman(w)

"""Stable or Unstable"""
stability(v, w)
