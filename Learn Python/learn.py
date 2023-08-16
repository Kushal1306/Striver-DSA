# name="kushal"
# #print("Hello world")
# print(name)
# age=12
# print(age)
# is_jain=True
# print(is_jain)
# name=input("what is your name?")
# print("hello"+name)
# number=13
# print(float(number))
# first=input("enter first number")
# second=input("second number")
# sum=int(first)+int(second)
# print("the sum is:"+str(sum))
# name="I'm kushal jain"

# print(name.upper())

# print(name.lower())

# print(name.find("kushal"))
# print(name.replace("kushal jain","shravani"))

# print ("kushal" in name)

# operators
# print(5/2)
# print(5//2)
# print(5%2)
# print(5**2)
# i=5
# i+=2
# i-=2
# i*=2
# i**=2
# print(i)

# age=2

# if age>=18:
#     print("you are an adult")
#     print("you can vote")
# elif age <18 and age>3:
#     print("you are bacha")
# else:
#     print("po ra po")

# range
# numbers=range(5)
# print(numbers)
#while loop
# i=1
# while i<=5:
#     print(i)
#     i=i+1

# for i in range(5):
#     print(i+1)
# marks=[95,98,97]
# print(marks)
# print(marks[0])
# print(marks[-1])
# for i in marks:
#     print(i)

# print(marks[0:2])

# marks.append(99)
# print(marks)
# marks.insert(0,99)

# print(marks)
# print(len(marks))

# marks.clear()
# print(marks)
# marks=[1,2,"kushal"]
# for i in marks:
#     print(i)

# print(marks.index("kushal"))
# marks={"kushal":91,"shravani":94}
# print(marks)
# marks["sreya"]=91
# print(marks)
# for i in marks:
#     i

#################################

# def print_sum(first,second=4):
#     print(first+second)

# print_sum(1,5)

emp = [ "John", 102, "USA"]       
Dep1 = [ "CS",10]    
Dep2 = [ "IT",11]      
HOD_CS = [ 10,"Mr. Holding"]      
HOD_IT = [11, "Mr. Bewon"]      
print("printing employee data ...")      
print(" Name : %s, ID: %d, Country: %s" %(emp[0], emp[1], emp[2]))      
print("printing departments ...")     
print("Department 1:\nName: %s, ID: %d\n Department 2:\n Name: %s, ID: %s"%( Dep1[0], Dep2[1], Dep2[0], Dep2[1]))      
print("HOD Details ....")      
print("CS HOD Name: %s, Id: %d" %(HOD_CS[1], HOD_CS[0]))      
print("IT HOD Name: %s, Id: %d" %(HOD_IT[1], HOD_IT[0]))      
print(type(emp), type(Dep1), type(Dep2), type(HOD_CS), type(HOD_IT))    