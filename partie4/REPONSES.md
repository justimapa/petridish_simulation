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
A Nutriment is a CircularBody.
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
dish.

We must also add a resetTemperature method in the class Petridish,
which will also be called by our initial reset method in Petridish.

Thus:
- 'R' key pressed: getEnv().reset() calls reset() method of Lab,
  which in turn calls its dish's reset() method, where after removal
  of the nutriments, the resetTemperature() method is called.
- 'C' key pressed: getEnv().refreshConfig() calls refreshConfig()
  method of Lab::, which resets its dish's temperature.  
- answer to question 2.12

*******************************************************

##Q3.1
All classes that are drawable and updatable will inherit from
these classes. In this case, we have thes classes Lab::,
Petridish::, Nutirment:: and Bacterium::.
This will allow the drawOn() and update() functions
of their subclasses to be used polymorphically without
needing to constantly redfine them in the subclasses.
-answer to question 3.1

*******************************************************

##Q3.2
The methods drawOn() and update() in the class Nutriment:: must be
virtual (which is already the case as they inherit the virtuaity
from the pure virtual functions in Drawable and Updatable).
-answer to question 3.2

*******************************************************

##Q3.3
In the superclass Nutriment::, the getConfig() method must be
pure virtual, which will make Nutriment:: an absract class.
The getConfig() method wil then be used polymorphically
in the classes NutrimentA:: and NutrimentB::.
-answer to question 3.3

*******************************************************

##Q3.4
The polymorphic getConfig() method is used in the drawOn() and update()
methods of Nutriment::. So for example when a NutrimentA:: uses them,
the getConfig() method access the texture and other parameters
corresponding to NutirmentA:: in the app.json file. Same process
if we have a NutrimentB::.
-answer to question 3.4

*******************************************************

##Q3.5
We need to modify the update() method in Lab::, making it call
its generator's update() function as well.
-answer to question 3.5

*******************************************************

##Q3.6
The set() method, which will be called by mutate() will be responsible
to make the checks on the upper and lower bounds of the mutable number.
-answer to question 3.6

*******************************************************

##Q3.7
The probability() and positive() methods will be set as static,
allowing their utilization even without the creation of an
instance of a MutableNumber::.
-answer to question 3.7

*******************************************************

##Q3.8
Inherits from:
- CircularBody::
- Drawable::
- Updatable::

Attributes:
- MutableColor color
- Vec2d direction
- bool abstinence
- Quantity energy
- std::map <std::string, MutableNumber> mutations

Methods:
- void move(sf::Time dt)
- Bacterium* clone()
- bool isDead()
- void drawOn (sf::RenderTarget targetWindow)
- void update(sf::Time dt)

-answer to question 3.8

*******************************************************

##Q3.9
The methods drawOn() and update() are already virtual as they are inherited from
the abstract classes Drawable:: and Updatable::.

The methods move() will be pure virtual as it isn't well defined without
the different types of bacteria subclasses.
-answer to question 3.9

*******************************************************

##Q3.10
The getConfig() method will be pure virtual, just like the one in Nutriment::
as it isn't well defined without its subclasses and will fetch different
config values according to the real nature (bacteria type) of the instance
calling it.
-answer to question 3.10

*******************************************************

##Q3.11
We use the get() method of the class MutableColor (color.get()), which returns
in this case the SFML color of bacterium at hand.
-answer to question 3.11

*******************************************************

##Q3.12
The fact that the move() is not an issue at all. As a pure virtual
method, the compiler knows that it will gain definitions in
evetual subclasses.
-answer to question 3.12

*******************************************************

##Q3.13
The getNutrimentColliding() method in Lab:: will call the method
of the same name of its dish.
-answer to question 3.13

*******************************************************

##Q3.14
The update() method of the class PetriDish:: will be modified to
also have a for loop calling the update() method of every bacteria
contained within it.
-answer to question 3.14

*******************************************************

##Q3.15
In the class PetriDish, the for loops of the update() method will
also contain an if loop using the isDead() methods of Nutriment::
and Bacterium::, erasing them if there is no quantity/energy left.

We will also make sure to erase the bacteria and nutriments within
the reset() method of Petridish::.
-answer to question 3.15

*******************************************************

##Q3.16
The class SimpleBacterium:: will inherit the pure virtual method f() from
the class DiffEqFunction::. This will allow it, and other types of bacterium
to use it polymorphically with the EC or RG4 algorithms.
-answer to question 3.16

*******************************************************

##Q3.17
t will be declared as an attribute of the class SimpleBacterium::
and will be initialized by default using the uniform() method 
within the constructor.
-answer to question 3.17

*******************************************************

##Q3.18
rotation will also be declared as an attribute of the class
SimpleBacterium:: and will be initialized by default to getDirection().angle()
in the constructor.
-answer to question 3.18

*******************************************************

##Q3.19
The class Petridish:: will have a new gradientExponent attribute,
which will be initialized when the constructor of Lab:: calls the
constructor of its Petridish::.
-answer to question 3.19

*******************************************************

##Q3.20
We will add two new attributes to the class SimpleBacterium::,
oldscore and tLastTumble, which will respectively represent
the previous score and the time spent since the last tumble.

They will both be initialized to 0 (sf::Time::Zero for the time
since the last tumble).
-answer to question 3.20

*******************************************************

##Q4.1
The class TwitchingBacterium:: will inherit from the class Bacterium::.
-answer to question 4.1

*******************************************************

##Q4.2
We will redefine the pure virtual method getConfig() in the class 
TwitchingBacterium:: so that it fetches the corresponding config
values polymorphically.
-answer to question 4.2

*******************************************************

##Q4.3
We must redefine all the pure virtual methods in the class Bacterium::
so that we may create instances of TwitchingBacterium::.
-answer to question 4.3

*******************************************************

##Q4.4
We will utilize two getters, getMovementEnergy() and getTentacleEnergy(),
which will get the corresponing config values from the JSON file.
They will both call upon the getEnergyConsumption() method in class
Bacterium::.
-answer to question 4.4

*******************************************************
##Q4.5
We will declare an enum, containing all the different states of
the TwitchingBacterium:: as an attribute of the class. It will be
initialized to IDLE with the class' constructor and will be further
controlled by the update() method, which will affect the different
possible states to the current instance according to the situation it
is in.

This allows the move method to be much more concise through a
switch statement, without using too many if statements.
-answer to question 4.5

*******************************************************

##Q4.6
We add an attribut which is a vector of Swarm pointers to the Petridish::.
Then,we add the method, void  addSwarm(), to the Lab:: and Petridish::.
The Lab addSwarm() will call the addSwarm of the Petridish which will add a Swarm
to the attribut swarms of Petridish.
-answer to question 4.6

*******************************************************
##Q4.7
The SwarmBacterium:: will inherit from DiffEqFunction similar to the SimpleBacterium::.
-answer to question 4.7

*******************************************************
##Q4.8
We need to redefine move, clone and getConfig as the were defined as virtual pures in the Bacterium:: class.
-answer to question 4.8

*******************************************************
##Q4.9
We add the method, Swarm * getSwarmWithId(id), to the Lab:: and Petridish::.
The lab getSwarmWithId will call the Petrdish's getSwarmwithId to get the pointer towards the swarm we want.
-answer to question 4.9

*******************************************************
##Q4.10
The Swarm Destructor must simply destroy the pointers to the now deleted Bacteria.
-answer to question 4.10

*******************************************************
##Q4.11
The Swarm Update(), will control if the SwarmBacterium is dead and will remove it if it is the case.
-answer to question 4.11

*******************************************************
