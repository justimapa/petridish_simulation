#Projet programmation orientée objet (SSV)

##REPONSES du groupe ** (*Umut Tan Germeyan* & *Justin Christian Mapanao*) 

*******************************************************
##Q1.1

We have used the methods corresponding to the roles of the operators
(contains(twice), isColliding) for both > and &. And all arguments were
passed by constant reference, which saves memory space as operators are
used very frequently. 
- answer to question 1.1

*******************************************************
##Q1.2

The > and & operators were overloaded internally, as the comparison
operators are very close to the class. The attributes of the current
instance of the class i.e. position and radius.
- answer to question 1.2

*******************************************************
##Q1.3

It is useful to pass arguments by constant reference when they take up
a lot of memory space, in this case classes such as Vec2d and CircularBody.
This avoids creating unnecessary copies of these quite large objects.
This wouldn't be an issue for smaller fundamental types such as int or char.
- answer to question 1.3

*******************************************************

##Q1.4

All methods that do not modify the arguments, such as the getters and
test methods(contains, isColliding). The const is used to indicate
the roles to an eventual user-programmer.
- answer to question 1.4

*******************************************************

##Q2.1

The class Petridish will inherit from the class CircularBody, which will
allow it to use all of the methods in the class CircularBody. This represents
an "IS-A" relationship. The subclass Petridish is a CircularBody.
- answer to question 2.1

*******************************************************

##Q2.2

We will declare as const all the methods that do not modifiy the 
current instance. In this case, the only method we will declare as
const is drawOn(). This allows an eventual user-programmer to read 
the code of our class more easily.
- answer to question 2.2

*******************************************************

##Q2.3

To avoid unnecessary copies of very large and memory class consumming
objects, we must explicily delete operator=.
- answer to question 2.3

*******************************************************

##Q2.4

As we destroy the Petridish, we must deallocate the memory space we had 
previously dynamically allocated for the nutrients and bacteria, as they were
represented by a vector of pointers. This can be done through the 
reset() function of our class.
- answer to question 2.4

*******************************************************

##Q2.5

The methods drawOn and update of the class Lab will simply
call the methods of the same name of its own Petridish.
- answer to question 2.5

*******************************************************

##Q2.7

Just like the class Petridish, the class Nutriment will
also be a subclass of CircularBody and thus inherit all
its attributes amd methods (apart for constructors).
- answer to question 2.7

*******************************************************

##Q2.8

Using the type Quantity instead of a simple double gives more
specificity to the class Nutriment. It also make the code 
more readable and understandable for user-programmers.
- answer to question 2.8

*******************************************************

##Q2.9

We must add an addNutriment method to the class Lab, which
will call the addNutriment method of its Petridish. When we
do this we will also modifiy the drawOn method in the class Petridish,
by making it draw the Nutriments by calling the drawOn method
of its own Nutriment attribute.
- answer to question 2.9

*******************************************************

##Q2.10

Instead of having getter that gives access to the Lab's
Petridish, we will instead utilize a getTemperature method in Lab,
which will in turn call the getTemperature method of its Petridish.
This way we will not break the encapsulation and only allow the update
method in the class Nutriment to access the data which is needed.
- answer to question 2.10

*******************************************************

##Q2.11

We must modify the update methods in both classes. The update method
in the class Lab will call the update method of its dish, which will
itself use a for loop to call the update method of all its Nutriments.
- answer to question 2.11

*******************************************************

##Q2.12

We must add increaseTemperature and decreaseTemperature methods in 
both Lab and Petridish, to allow changes in temperature of the lab's
petri dish.

We must also add a resetTemperature method in the class Petridish,
which will also be called by our initial reset method in Petridish. This
will allow the temperature to go back to its default amount, when we
used the 'R' or 'C' keys.
- answer to question 2.12










