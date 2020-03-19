#Projet programmation orientée objet (SSV)

##REPONSES du groupe *No groupe* (*Nom étudiant(e)1* & *Nom étudiant(e) 2*) 

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


