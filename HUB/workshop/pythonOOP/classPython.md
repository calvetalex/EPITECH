# PYTHON : les Classes


## Summary

- Introduction
- Comment créer une classe
- Les méthodes
- Les attributs
- Les méthodes magiques
- Héritage

***
## Introduction

Le **Python** est un langage inteprété qui permet la **Programmation Orientée Objet**. En plus des types de base comme *int*, *float*, *str*, etc, python utilise la notion de **classes**. Cette notion va permettre de généraliser le principe de *type* afin de créer des structures de données.

Une classe se définit par des *attributs* et des *méthodes*. Les *attributs* correspondent aux propriétés de la classe (par exemple un attribut "couleur" pour un stylo). Les *méthodes* correspondent aux actions réalisables par la classe (par exemple "écrire" pour un stylo).

Maintenant que nous savons ce qu'est une classe, nous pouvons voir qu'est ce qu'un **objet**. Un objet est **l'instance d'une classe**, c'est à dire l'utilisation de la classe au sein de notre programme. Ainsi, nous pouvons avoir plusieurs objets pour une classe, chacun de ses objets ayant les mêmes attributs et les mêmes méthodes, mais des valeurs qui leur sont propres.

***
## Comment créer une classe ?

Pour créer une classe, nous devons définir cette dernière avec le mot clé `class` et un nom. Nous pouvons ensuite donner une description:

```python
class myClass:
    "short description of my class"
```

Une foit notre classe créée, nous pouvons l'utiliser en créant une instance de cette dernière. Pour cela, nous allons appeler le constructeur de la classe:

```python
myObj = myClass()
```

***
## Les méthodes

La méthode d'une classe est une fonction qui lui est propre (c'est à dire que cette dernière ne peut pas être appelée en dehors de la classe). Pour définir une méthode il nous faut donc déclarer une fonction au sein de notre classe. Il faut également lui donner le paramètre **self** en premier argument ! Prenons par exemple une class `myClass` qui aurait un attribut *value* et définissons une méthode *addOne* qui permet d'ajouter 1 à cette value:

```python
def myClass:
    "short description of my class"
    def addOne(self):
        self.value += 1
```

Maintenant que nous avons défnit notre méthode, comment l'utiliser ? Une fois que nous avons notre objet, nous pouvons passer par ce dernier pour utiliser les différentes méthodes:

```python
myObj = myClass()
myObj.addOne()
```

Vous remarquerez que lors de l'appel de `addOne` nous ne passons aucun paramètre alors que pourtant, nous avons déclarer que la méthode prenait au moins un arguement : *self*. C'est parce que *self* prend pour valeur la référence de notre objet, il n'est donc jamais passé en argument lors de notre appel.

### Le constructeur de la classe

Le constructeur d'une classe est une méthode nommée `__init__`, elle fait partie des méthodes dites *magiques*. Le constructeur est appelé automatiquement lors de la création d'un objet et peut disposer d'un nombre quelconque de paramètres (éventuellement aucun si la classe n'a pas besoin d'attribuer des valeurs à l'initialisation).

```python
class myClass:
    "short description of my class"

    def __init__(self):
        self.value = 0


def anotherClass:
    "class with no default value"

    def __init__(self, value):
        self.value = value

myClassObj = myClass()              # Ici le constructeur n'attend pas de valeur, donc pas besoin de passer un argument en plus
anotherClassObj = anotherClass(42)  # Ici le constructeur attend un argument value, il faut donc passer un élément lors de l'initialisation de l'objet
```

***
## Les attributs

Une classe peut avoir deux types d'attributs : des **attributs de classe**, qui sont commun à toutes les instances de la classe et des **attributs d'instance**, qui sont propres à chaque instance. Les attributs qui seront placés dans le corps de la classe seront des attributs de classe alors que les attributs définit dans le constructeur seront des attributs d'instance.

Pour acceder à ces attributs, nous devons utiliser le mot clé **self**. Ce dernier représente l'instance de la classe et c'est grâce à lui qu'on peut acceder aux différents éléments de notre classe.

```python
class myClass:
    "short description of my class"
    shared = []

    def __init__(self):
        self.notShared = ""

obj1 = myClass()
obj2 = myClass()

obj1.notShared = "I'm in obj1"
obj2.notShared = "I'm in obj2"

obj1.shared.append(1)
obj2.shared.append(2)

print(f"obj1.notShared = {obj1.notShared} and obj1.shared = {obj1.shared}")
print(f"obj2.notShared = {obj2.notShared} and obj2.shared = {obj2.shared}")
```

On remarque que la valeur pour `notShared` est unique alors que la valeur de `shared` est la même pour chaque objet.

En Python, il n'existe pas de variable privée comme en cpp. Toutefois il existe une convention de nommage qui dit qu'une variable ayant un nom préficé avec un _ doit être considéré comme un élément non publique (comme par exemple `_myVar`).

De plus, il existe un mécanisme appelé **name mangling** qui permet de remplacer toutes les variables écrites de la sorte `__myVar` (deux tirets du bas) par `_classname__myVar`. Ce mécanisme permet d'éviter les conflits avec des noms définit dans des sous classes. Ainsi, ce mécanisme permet de mettre en place une pseudo notion de valeur privée : on ne pourra pas accéder à l'élément directement par son nom:

```python
class myClass:
    "short description of my class"

    def __init__(self):
        self.item = 0
        self.__secret = 42
        self.__addOne()

    def addOne(self):
        self.item += 1

    __addOne = addOne #sera remplacé par _myClass__addOne

myObj = myClass()
print(myObj.__secret)
```

Dans l'exemple ci dessus, le print renverra une erreur car `__secret` a été remplacé textuellement par `_myClass__secret`. De plus, même si une autre classe qui hérite de myClass possède sa propre méthode addOne, l'appel du constructeur restera inchangé. Mais nous reviendrons sur l'héritage un peu plus tard.

### les Getters et Setters

Si on utilise des variables qui utilise le *name mangling*, nous pouvons mettre en place des méthodes pour intéragir avec sans les appeler directement. Tout d'abord, des méthodes afin de les récupérer, que nous appelerons **Getters**, puis des méthodes pour leur attribuer des valeurs, que nous appelerons **Setters**.

```python
def myClass:
    "short description of my class"

    def __init__(self):
        self.__privateValue = 42

    def getPrivateValue(self):
        return self.__privateValue

    def setPrivateValue(self, newValue):
        self.__privateValue = newValue
```

***
## Les méthodes magiques

Les méthodes magiques sont des méthodes spéciales qui sont ajoutées à votre classe. Elles se présentent sous la forme `__name__` et ne sont pas destinées à être appelée directement par l'utilisateur, mais dont l'appel sera fait par certaines actions. Par exemple, quand vous ajoutez deux nombres avec l'opérateur **+**, c'est la méthode `__add__`qui est appelée pour effectuer le calcul.

Pour toutes les voir, vous pouvez utiliser la fonction `dir()` en lui passant votre objet en pramètre. Passons en revue certaines d'entre elles:

- `__new__(cls [,...])`: la méthode `__new__` est appelée avant la méthode `__init__`. C'est elle qui va créer une nouvelle instance de la classe, elle retourne un nouvel objet qui est ensuite initialiser par `__init__`. On vous déconseille de modifier le comportement de cette méthode
- `__init__(self [,...])`: cette méthode va initialiser l'instance
- `__del__(self)`: c'est le destructeur, qui va s'effectuer lorsque l'instance sera supprimée
- `__str__(self)`: cette méthode est une des plus utile. Elle va être appelée lors de l'affichage d'un objet (lorsque l'on passe notre objet à *print* ou que l'on cast ce dernier en *str* par exemple). Elle retourne une représentation compréhensible de l'objet :

```python
class myClass:
    "short description of my class"
    def __init__(self):
        self.value = 42

    def __str__(self):
        return f"myClass instance, current value is {self.value}"

myObj = myClass()
print(myObj) # myClass instance, current value is 42
```

- `__repr__(self)`: cette méthode permet de récupérer une représentation compréhensible par la machine afin de recréer une copie de l'instance
- `__round__(self,n)`: cette méthode est appelée lors de l'utilisation de la fonction `round` sur l'objet
- `__floor__(self)`: cette méthode est appelée lors de l'utilisation de `math.floor`
- `__ceil__(self)`: cette méthode est appelée lors de l'utilisation de `math.ceil`
- `__trunc__(self)`: cette méthode est appelée lors de l'utilisation de `math.trunc`
- `__iter__`: permet d'utiliser la fonction **for** sur votre classe. La méthode `__iter__` doit renvoyer un objet disposant d'une méthode `__next__`
- `__next__`: la méthode `__next__` accède aux éléments du conteneur un par un et lève une exception **StopIteration** quand il n'y a plus d'élément.

```python
## Cet exemple provient de la documentation officielle de python
def Reverse:
    "Iterator for looping over a sequence backwards."
    def __init__(self, data):
        self.data = data
        self.index = len(data)

    def __iter__(self):
        return self

    def __next__(self):
        if self.index == 0:
            raise StopIteration
        self.index = self.index - 1
        return self.data[self.index]

rev = Reverse("spam")
for char in rev:
    print(char) # donnera : m,a,p,s
```

#### Méthodes de cast

- `__int__(self)`: cette méthode correspond au cast de notre en `int`
- `__long__(self)`: cette méthode correspond au cast de notre en `long`
- `__float__(self)`: cette méthode correspond au cast de notre en `float`
- `__oct__(self)`: cette méthode correspond au cast de notre en `octal`
- `__hex__(self)`: cette méthode correspond au cast de notre en `hexa`
- `__abs__(self)`: cette méthode correspond à l'opérateur `abs()`
- `__complex__(self)`: cette méthode correspond au cast de notre en `complex`
- `__nonzero__(self)`: cette méthode permet de retourner une valuer booléenne


#### Méthodes d'opérations
- `__add__(self, other)`: cette méthode correspond à l'opérateur `+`
- `__sub__(self, other)`: cette méthode correspond à l'opérateur `-`
- `__mul__(self, other)`: cette méthode correspond à l'opérateur `*`
- `__floordiv__(self, other)`: cette méthode correspond à l'opérateur `//`
- `__truediv__(self, other)`: cette méthode correspond à l'opérateur `/`
- `__mod__(self, other)`: cette méthode correspond à l'opérateur `%`
- `__pow__(self, other)`: cette méthode correspond à l'opérateur `**`
- `__lshift__(self, other)`: cette méthode correspond à l'opérateur `<<`
- `__rshift__(self, other)`: cette méthode correspond à l'opérateur `>>`
- `__and__(self, other)`: cette méthode correspond à l'opérateur `&`
- `__xor__(self, other)`: cette méthode correspond à l'opérateur `^`
- `__or__(self, other)`: cette méthode correspond à l'opérateur `|`
- `__invert__(self)`: cette méthode correspond à l'opérateur `~`
- `__pos__(self)`: cette méthode correspond à l'opérateur unaire `+`
- `__neg__(self)`: cette méthode correspond à l'opérateur unaire `-`


#### Méthodes d'opérations étandues
- `__iadd__(self, other)`: cette méthode correspond à l'opérateur `+=`
- `__isub__(self, other)`: cette méthode correspond à l'opérateur `-=`
- `__imul__(self, other)`: cette méthode correspond à l'opérateur `*=`
- `__ifloordiv__(self, other)`: cette méthode correspond à l'opérateur `//=`
- `__idiv__(self, other)`: cette méthode correspond à l'opérateur `/=`
- `__imod__(self, other)`: cette méthode correspond à l'opérateur `%=`
- `__ipow__(self, other)`: cette méthode correspond à l'opérateur `**=`
- `__ilshift__(self, other)`: cette méthode correspond à l'opérateur `<<=`
- `__irshift__(self, other)`: cette méthode correspond à l'opérateur `>>=`
- `__iand__(self, other)`: cette méthode correspond à l'opérateur `&=`
- `__ixor__(self, other)`: cette méthode correspond à l'opérateur `^=`
- `__ior__(self, other)`: cette méthode correspond à l'opérateur `|=`

#### Méthode de comparaison
- `__lt__(self, other)`: cette méthode correspond à l'opérateur `<`
- `__le__(self, other)`: cette méthode correspond à l'opérateur `<=`
- `__eq__(self, other)`: cette méthode correspond à l'opérateur `==`
- `__ne__(self, other)`: cette méthode correspond à l'opérateur `!=`
- `__ge__(self, other)`: cette méthode correspond à l'opérateur `>=`
- `__gt__(self, other)`: cette méthode correspond à l'opérateur `>`

#### Attribut magique
Il existe un attribut spécial que votre classe peut posséder par défaut et il peut être utile de connaitre son existence (pour du debug par exemple)

-`__doc__`: la documentation de la classe, est par defaut sur `None` et n'est pas héritée par les sous classes. Cette **attribut** correspond à la string que nous notons sous notre déclaration de classe
```python
class myClass:
    "short description of my class"
    pass

test = myClass()
print(test.__doc__) # affichera : short description of my class
```

***
## Héritage

En python, une classe peut hériter d'une autre. Elle prend alors ses attributs et ses méthodes comme base et peut posséder des éléments propres ainsi que modifier les éléments dont elle a hérité.

Quand une classe enfant (classe ayant hérité d'une autre) modifie une méthode de la classe parent (classe dont la classe enfant hérite), cette dernière remplace la méthode de la classe parent, on parle alors de **polymorphisme**. On peut également dire que la méthode de la classe parent a été **surchargée**.

```python
class Mammifere:
    "décrit un mammifere"
    caract1 = "il allaite ses petits"
    def __init__(self, age):
        self.age = age

    def info(self):
        print()
        print(f"caractéristique: {self.caract1}\nagé de : {self.age}")

class Carnivore(Mammifere):
    "catégorie de mammifere se nourissant de viande"
    caract2 = "il mange de la viande"
    def info(self):
        print()
        print(f"Je suis un carnivore !")

animal = Mammifere(3)
loup = Carnivore(5)

print(loup.caract1, loup.caract2) # le loup a accès a caract1 en plus de caract2
animal.info()
loup.info() # le comportement n'est pas le meme que celui de la classe Mammifere, la méthode info a été surchargée
```