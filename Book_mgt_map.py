def insert(map):
    global id
    name=input("\nEnter the Name of the Book: ")
    for x in map.values():
        if(x==name):
            print("\nThe book already exists in the list!!")
            return
    id+=1
    map[id]=name

def remove(map):
    global id
    if len(map)==0:
        print("\nNo Books remained to delete!!!")
        return
    print(f"\n{map[id]} is removed from the list!!")    
    del map[id]
    id-=1
    
def search(map):
    if len(map)==0:
        print("\nThere are no books in the List!!!")
        return
    name=input("\nEnter the Name of the Book to search: ")
    flag=0
    for x in map.values():
        if x==name:
            print("\nBook exists in the System!!!")
            flag=1
    if flag==0:
        print("\nBook not Found !!!")

def display(map):
    if len(map)==0:
        print("\nThere are no books in the List!!!")
        return
    id=1
    for y in map.values():
        print(f"\n{id}\t{y}")
        id+=1
    
map=dict()
id=0

while(1):
    opt=int(input("\n1.Insert Book\n2.Remove Book\n3.Display Books\n4.Search\n5.Exit\n\nPlease Enter your Choice:  "))

    if(opt==1):
        insert(map)
        
    elif(opt==2):
        remove(map)
        
    elif(opt==3):
        display(map)
        
    elif(opt==4):
        search(map)
        
    elif(opt==5):
        break

    else:
        print("\nPlease Enter a Appropriate Option!!!!")
