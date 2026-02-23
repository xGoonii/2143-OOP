```yaml
id: H01
name: H01
title: 'Forced Study Guide'
description: Deleted some format to see questions and answers better  
category: Homework
date_assigned: 2026-02-09 11:00
date_due: 2026-02-23 11:00
resources: []
```

# 🧠 OOP Worksheet & Study Guide  
### *Making Your Own Types Feel Like the Language Meant Them to Exist*

### Due: 16 Feb 2026 by class time. 

---

# Part 1 — Review, But With Consequences

## 1️⃣ Stacks & Queues (ADT Reality Check)

Answer **clearly and concisely**.

1. Compare **array-based** vs **list-based** implementations of stacks and queues:
   - memory layout <br>
   ***Answer Array:*** <ins>Stored in the same space "block" like layout. <br> </ins>
   ***Answer List:*** <ins>Stored inside nodes which connect to pointers. Data is scattered around <br> <br> </ins>  
   - resizing behavior <br>
   ***Answer Array:*** <ins>Has a capacity. When full you must allocate new array and copy elements, and delete old array.<br></ins>
   ***Answer List:*** <ins>Has no limit capacity. Just create new node. <br><br> </ins>
   - cache friendliness  
   ***Answer Array:*** <ins>Loads faster because memory is grouped together.<br></ins>
   ***Answer List:*** <ins>Loads slower because memory is scattered. <br> </ins>

2. Why is `std::vector` a natural fit for a **stack**, but awkward for a **queue**?<br>
   ***Answer Array:*** <ins>Array is LIFO and vector is able to push back and pop back making it perfect and fast<br></ins>
   ***Answer List:*** <ins>Queue is FIFO means you add to back and remove from front. With a vector youd have to shift everything when removing and element<br> </ins>

3. Define the **invariant** for:
   - a stack ***Answer:*** <ins>First one in first one out.<br></ins>
   - a queue ***Answer:*** <ins>Last one in first one out.<br></ins>

---

# Part 2 — Overloading vs Overriding  
### (Same Word Root, Completely Different Beasts)

## 2️⃣ Conceptual Distinction

Fill out the table:

| Feature               | Overloading | Overriding |
| --------------------- | ----------- | ---------- |
| Resolved at           | compile time| run time   |
| Requires inheritance  | NO          | YES        |
| Same function name    | YES         | YES        |
| Same parameter list   | NO          | YES        |
| Polymorphism involved | NO          | YES        |

Then answer:

1. Why is **overloading** a *compile-time convenience*?<br>
 ***Answer:*** <ins>Overloading is a compile-time convenience because the compiler chooses which function to call based on the argument types before the program runs.<br></ins>

2. Why is **overriding** a *runtime contract*?<br>
 ***Answer:*** <ins>Overriding is a runtime contract because it selectes the correct behavior while the code is running based on the objects type. <br></ins>
 
3. Why do beginners confuse the two?<br>
***Answer:*** <ins>Beginners probably confuse the 2 because they have similiar names, both use same function names, and they might not know the difference in compile vs run time.<br></ins>

4. Why is that confusion dangerous?<br>
***Answer:*** <ins>Because your program can run correctly and behave incorrectly when you overload instead of overriding.<br></ins>

---

# Part 3 — Constructors & Initialization Lists  
### (Where C++ Stops Holding Your Hand)

## 3️⃣ Initialization Lists or Else

Given:

```cpp
class Widget {
private:
    const int id;
    std::string name;

public:
    Widget(int id, std::string name);
};
```

Answer:

1. Why **must** this constructor use an initialization list?<br>
***Answer:*** <ins>Because its a CONST which need to be initialized ASAP.<br></ins>
2. What happens if you try to assign `id` inside the constructor body?<br>
***Answer:*** <ins>The code will not compile because `id` is a constant so you cant chnage the value.<br></ins>
3. Write the correct constructor.<br>
***Answer:*** <ins>Widget(int id, std::string name) : id(idValue), name(nameValue){}<br></ins>
4. Name **one other situation** where initialization lists are required (research-lite).<br>
***Answer:*** <ins>Another situation init list is required is when you're using a reference member <br></ins>

---

## 4️⃣ Copy Constructor vs Assignment Operator

Research + reasoning required.

1. When is the **copy constructor** invoked?<br>
***Answer:*** <ins>When a new object is CREATED using an existing one. passing or returning by value.<br></ins>
2. When is the **assignment operator** invoked?<br>
***Answer:*** <ins>When an exsting object gets assigned/modifies the value of another exsting object.<br></ins>
3. Why do both exist?
***Answer:*** <ins>They do different things, one is used to Create other is used to Modify .<br></ins>
4. What subtle bugs appear if you confuse them?
***Answer:*** <ins>Confusing the two can give you memory leaks, and unknown behavior.<br></ins>

---

# Part 4 — `struct` vs `class`  
### (Same Machine Code, Different Intent)

## 5️⃣ Design Signal, Not Syntax Sugar

Answer:

1. What is the **only** language-level difference between `struct` and `class`?<br>
***Answer:*** <ins>Class is private by default.<br></ins>
2. Why does C++ even allow both?<br>
***Answer:*** <ins>communicates intent, struct is mainly public data, while struct is more protected date.<br></ins>
3. When does choosing `struct` communicate intent *better* than `class`?<br>
***Answer:*** <ins>choosing struct is better when using simple data containers and mostly public memebrs.<br></ins>
4. Why does intent matter more than syntax in large systems?<br>
***Answer:*** <ins>In large codes humans read the program more than the compiler does. Syntax tells the compiler what is allowed,intent tells humans what its for.<br></ins>
---

# Part 5 — Operator Overloading  
### (Where ADTs Start Feeling Real)

## 6️⃣ Rules You Don’t Get to Ignore

Research and explain:

1. Why can’t C++ overload:
   - `.`  
   - `::`  
   - `sizeof`
***Answer:*** <ins>These are fundamental operators to the language, its part of the compilers core system.<br></ins>

2. Why should `operator+` **not** mutate the left-hand operand?<br>
***Answer:*** <ins>It shouldnt mutate the left hadn side because user expects + to create a new result without changing original values .<br></ins>
3. Why is `operator<<` almost never a member function?<br>
***Answer:*** <ins>Member operators are usually on the left hand object .<br></ins>

---

## 7️⃣ The “other / rhs” Trap (Yes, It’s Intentional)

Given:

```cpp
Point operator+(const Point& rhs) const;
```

Answer clearly:

1. Which object owns this function?<br>
***Answer:*** <ins>the function belongs to the class point and is called by the left hand object .<br></ins>
2. What does `rhs` represent?<br>
***Answer:*** <ins>"Right hand-side" which represents the object being added to the LHS .<br></ins>
3. How can this function access `rhs.x` if `x` is private?<br>
***Answer:*** <ins>with "this->x" or "rhs.x" because its inside the point class .<br></ins>
4. What does this tell you about **class-level vs object-level access**?<br>
***Answer:*** <ins>Member functions can access private data of any object of the same class.<br></ins>

---

# Part 6 — `friend`: Controlled Violation of Privacy

## 8️⃣ Friend or Design Smell?

Answer:

1. What does the `friend` keyword actually do?<br>
***Answer:*** <ins>The friend keyword gives a function or another class access to private and protected members of a class.<br></ins>
2. Why is `operator<<` commonly declared as a friend?<br>
***Answer:*** <ins>operator<< is usually declared as a friend because it must be a non-member function to allow std::ostream on the left-hand side .<br></ins>
3. Why is excessive use of `friend` a red flag?<br>
***Answer:*** <ins>making the private memebrs less private.<br></ins>
4. Give **one legitimate use case** and **one illegitimate one**.<br>
***Answer:*** <ins>A legitimate use case is overloading operator<<, where a non-member function needs controlled access to private data.
An illegitimate use case is granting friendship to unrelated classes just to access private members, which breaks encapsulation and signals poor design.<br></ins>

---

# Part 7 — Core Programming Task  
### *Design a Type, Not a School Assignment*

## 9️⃣ Build a Native-Feeling `Point2D`

You are designing a **type**, not checking boxes.

### Required Features

Your `Point2D` class must:

- Use **private data members**
- Include at least **three constructors**:
  - default
  - parameterized
  - copy constructor
- Use **initialization lists**
- Overload:
  - `+`
  - `-`
  - `==`
  - `!=` (without duplicating logic)
  - `<<`
- Demonstrate **const correctness**
- Avoid public getters unless you can justify them

### Required Usage (This Must Compile)

```cpp
Point2D a(3, 4);
Point2D b(1, 2);

Point2D c = a + b;
Point2D d = a - b;

if (c == Point2D(4, 6)) {
    std::cout << "Math still works.\n";
}

std::cout << a << std::endl;
```

---
**Point2D class code**
```cpp
#include <iostream>
using namespace std;

class Point2D{
private:
int x;
int y;

public:
Point2D() : x(0), y(0){}
Point2D(int x, int y) : x(x), y(y){}
Point2D(const Point2D& other) : x(other.x),y(other.y){}
Point2D operator+(const Point2D& rhs) const
   {
   return Point2D(x+rhs.x, y+rhs.y);
   }
Point2D operator-(const Point2D& rhs) const
   {
   return Point2D(x-rhs.x, y-rhs.y);
   }
bool operator==(const Point2D& rhs) const
   {
   return x == rhs.x && y == rhs.y;
   }
friend ostream& operator<<(ostream& os, const Point2D& p)
   {
   os << "(" << p.x << "," << p.y << ")";
   return os;
   }
};
int main(){

}
```
---

## 1️⃣0️⃣ Design Constraints (Read Carefully)

You **may not**:
- expose raw data publicly
- use inheritance
- overload operators with nonsense semantics

You **should**:
- minimize the public interface
- make misuse difficult
- prefer clarity over cleverness

---

# Part 8 — Composition (The Quiet MVP of OOP)

## 1️⃣1️⃣ Composition in Plain English

> **Composition means assembling behavior from parts, not becoming those parts.**

Or more bluntly:

> “Has-a” beats “is-a” most of the time.

---

## 1️⃣2️⃣ Inheritance vs Composition (No Dragons Yet)

### ❌ Inheritance First Instinct

```cpp
class ColoredPoint : public Point2D {
    Color color;
};
```

Problems:
- Locked into `Point2D` forever
- Inherits everything, wanted or not
- Hard to evolve safely

---

### ✅ Composition Approach

```cpp
class ColoredPoint {
private:
    Point2D position;
    Color color;
};
```

Benefits:
- Clear ownership
- Modular behavior
- Fewer unintended side effects

---

## 1️⃣3️⃣ The Big Takeaway

> **Inheritance expresses identity.  
> Composition expresses capability.**

Most real systems care more about **capability**.

---

# Part 9 — Reflection (Yes, This Is Graded)

Answer honestly:

1. Does your `Point2D` *feel* like a built-in type?
2. What design choice most contributed to that feeling?
3. Which OOP concept currently feels overhyped?
4. Which one feels underrated?
5. What part of this worksheet made you uncomfortable — and why? 

If nothing made you uncomfortable, you probably didn’t push hard enough.

---

# ✅ Grading Rubric (100 Points)

## Conceptual Understanding — 25 pts
- Overloading vs Overriding: 10  
- Constructors & Init Lists: 10  
- Struct vs Class (intent-based): 5  

## Operator Overloading Design — 25 pts
- Semantic correctness: 10  
- Const correctness: 5  
- Member vs friend choice: 5  
- Minimal interface: 5  

## Class Design & Encapsulation — 25 pts
- Private data: 10  
- Constructor quality: 5  
- Initialization lists: 5  
- Friend usage justification: 5  

## Code Quality — 15 pts
- Compiles cleanly: 5  
- Readability & naming: 5  
- Comments explain *why*: 5  

## Reflection & Judgment — 10 pts
- Honest reflection: 5  
- Insight into tradeoffs: 5  

---

# Final Instructor Note (Read This Twice)

That feeling of:

> “There’s always something else… another way… something deeper…”

That’s not failure.  
That’s **abstraction having no ceiling**.

The goal is not perfection.  
The goal is **better judgment**.

## Deliverables

- Make sure you have a folder called Assignments in your Github repo.
- Create a folder in Assignments called H01 and place all of your documents in there. 
- Generate a pdf of your solution and have the entire worksheet not just uploaded to Github, but also printed and brought to class Monday the 16th of February.  
- This really is a study guide as we will have an exam the week of the 16th. 
- You have to use markdown to create your document. Why? It does syntax highlighting, and makes writing documents easy. 
  - [Markdown Getting Started](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
  - [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Here-Cheatsheet)
- If you use code spaces or download VsCode, you can install plugins to let you convert markdown to pdf, and to allow you to print directly from VsCode.
