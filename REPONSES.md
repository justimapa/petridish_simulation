#Projet programmation orientée objet (SSV)

##REPONSES du groupe ** (*Umut Tan Germeyan* & *Justin Christian Mapanao*) 

*************************************************
##Q1.1

We have used the methods corresponding to the roles of the operators
(contains(twice), isColliding) for both > and &. And all arguments were
passed by constant reference, which saves memory space as operators are
used very frequently. 
- réponse à la question 1.1

*************************************************
##Q1.2

The > and & operators were overloaded internally, as the comparison
operators are very close to the class. The attributes of the current
instance of the class i.e. position and radius.
- réponse à la question 1.2

*************************************************
##Q1.3

It is useful to pass arguments by constant reference when they take up
a lot of memory space, in this case classes such as Vec2d and CircularBody.
This avoids creating unnecessary copies of these quite large objects.
This wouldn't be an issue for smaller fundamental types such as int or char.
- réponse à la question 1.3

*************************************************

##Q1.4

All methods that do not modify the arguments, such as the getters and
test methods(contains, isColliding). The const is used to indicate
the roles to an eventual user-programmer.
- réponse à la question 1.4

**************************************************

##Q2.1

The class Petridish will inherit from the class CircularBody, which will
allow it to use all of the methods in the class CircularBody. This represents
an "IS-A" relationship. A petri dish is a circular body.
- reponse a la question 2.1

**************************************************

##Q2.2

We will declare as const all the methods (getTemperature(), drawOn()) 
that do not modifiy the current instance. This allows an eventual user-programmer 
to read the code more easily.
- reponse a la question 2.2

**************************************************

##Q2.3

To avoid unnecessary copies of very large and memory class consumming
objects, we must explicily erase operator=.
-reponse a la question 2.3

***************************************************

##Q2.4

As we destroy the Petridish, we remove the memory space we have allocated 
previously for the nutrients and bacteria within the petri dish. This can
be done through the reset() function.
-reponse a la question 2.4




