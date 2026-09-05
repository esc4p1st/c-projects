# 🎬 Cinema Booking System

A console-based **Cinema Booking System** written in **C**.

This is my **first portfolio project**, created to practice the fundamentals of C programming and apply them in a practical application.

The program allows users to select a movie, add popcorn and drinks, receive available discounts, and get a final receipt. It also includes a movie recommendation mode based on the user's budget.

---

## 🚀 Features

### 🎟️ Ticket Purchase

Users can:

* Choose a movie from a list of 10 movies
* Select whether they are a student
* Apply a membership discount
* Add popcorn
* Add a drink
* Receive a final receipt with the total price

### 🍿 Food & Drinks

The system provides several popcorn and drink options.

**Popcorn:**

* Salted
* Cheese
* Caramel
* Spicy

**Drinks:**

* Cola
* Sprite
* Water
* Ice Tea
* Orange Juice

### 💰 Discounts

The system supports two types of discounts:

* 🎓 Student discount — **30%**
* 💳 Membership discount — **15%**

### 🎯 Movie Recommendation

Users can enter their budget and receive a list of movies that fit within it.

The recommendation system:

1. Takes the user's budget
2. Checks whether the user is a student or member
3. Calculates the discounted movie prices
4. Finds movies that fit the budget
5. Sorts the recommendations by final price

The recommendations are sorted using **Insertion Sort**.

---

## 🛠️ Technologies

* **C**
* Standard C Library
* `stdio.h`
* `stdlib.h`
* `ctype.h`
* Git
* GitHub

---

## 📚 What I Practiced

This project helped me practice several important C programming concepts:

* Variables and data types
* Arrays
* Strings
* Functions
* Pointers
* Structures (`struct`)
* Enumerations (`enum`)
* `if` statements
* Loops
* `scanf()` and input validation
* Passing arrays to functions
* Working with structures through pointers
* Sorting algorithms
* Basic program architecture

The project uses `Client` and `Recommendation` structures to organize program data.

---

## 🧠 Algorithms

### Insertion Sort

The recommendation system uses **Insertion Sort** to order movies by their final price.

```c
while (j >= 0 && arr[j].finalPrice > key.finalPrice)
{
    arr[j + 1] = arr[j];
    j = j - 1;
}

arr[j + 1] = key;
```

This was one of the algorithms I implemented while learning C.

---

## 📋 Example Workflow

```text
Cinema Booking System

1. Purchase Ticket
2. Movie Recommendation
0. Exit
```

### Purchase Ticket

```text
Choose a movie
→ Select student status
→ Select membership
→ Choose popcorn
→ Choose drink
→ Generate receipt
```

### Recommendation Mode

```text
Enter budget
→ Select student/membership status
→ Calculate discounted prices
→ Find affordable movies
→ Sort recommendations
→ Display results
```

---

## 🎯 Project Goals

The main goal of this project was not to create a perfect cinema management system.

It was to **learn by building**.

Through this project, I wanted to move from individual C exercises to a program where different programming concepts work together.

---

## 🔧 Future Improvements

There are several things I would like to improve in future versions:

* Improve input validation
* Refactor the price calculation logic
* Improve the recommendation system
* Add more cinema features
* Make the code more modular
* Improve error handling
* Add file storage
* Add seat selection
* Improve the user interface
* Add automated tests

---

## 📈 What I Learned

This project taught me that writing a larger program is very different from solving individual programming exercises.

I learned how important it is to:

* Break a problem into smaller functions
* Organize data using structures
* Validate user input
* Think about different user scenarios
* Debug code
* Refactor existing solutions
* Use Git and GitHub while developing a project

---

## 👨‍💻 About the Project

**Language:** C
**Type:** Console Application
**Project:** First Portfolio Project

This project represents one of my first steps toward becoming a software engineer.

> **Learn → Build → Debug → Improve → Repeat. 🚀**
