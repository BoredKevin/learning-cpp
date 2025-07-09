## **"Potion Crafter 3000"** — A Silly Alchemy Game

### 🎮 Concept:

You are a wizard apprentice brewing potions. You combine **ingredients**, and based on the combo, the system tells you what potion you created — useful, dangerous, or just plain weird!

You’ll write functions for brewing, get user input, use function overloading to name results differently, maybe use lambdas for mini logic, and templates for clean input.

---

### 🧾 Example Gameplay:

```
🧙 Welcome to Potion Crafter 3000!
Choose two ingredients to combine:
>> unicorn hair
>> dragon scale

🔮 Brewing...

✨ Result: You created a Strength Potion!
💬 Tip: Use it wisely before a boss fight.

Brew another potion? (y/n)
>> y

>> cheese
>> frog leg

✨ Result: You created a Mystery Goo!
💬 Tip: Maybe… don’t drink this one.

Brew another potion? (y/n)
>> n

Goodbye, young wizard!
```

---

### 🎯 Your Mission:

Static polymorphism, also known as compile-time polymorphism, is a type of polymorphism that resolves the types and method calls at compile time rather than at runtime. This is commonly achieved through the use of function overloading and templates in C++.

#### 1. `getIngredients()` → **User-defined function**

Ask for two ingredients. Combine and return them.

#### 2. `brewPotion(string, string)` → **Main brewing logic**

Use `if` or `map` to return a name of a potion based on combos.

#### 3. `respond()` → **Function overloading**

* One `respond(string)` prints potion name.
* One `respond(int)` could give a "power level" of the potion.
* One `respond(char)` could print a magic emoji.

Function overloading is a way to create multiple functions with the same name but different parameter lists. The compiler determines the correct function to call based on the types and number of arguments used when the function is called.

Example:
```
#include <iostream>

void print(int i) {
    std::cout << "Printing int: " << i << '\n';
}

void print(double d) {
    std::cout << "Printing double: " << d << '\n';
}

void print(const char* s) {
    std::cout << "Printing string: " << s << '\n';
}

int main() {
    print(5);          // Calls print(int i)
    print(3.14);       // Calls print(double d)
    print("Hello");    // Calls print(const char* s)

    return 0;
}
```

#### 4. `getInput<T>()` → **Template**

Reusable clean input.

Templates are a powerful feature in C++ that allows you to create generic functions or classes. The actual code for specific types is generated at compile time, which avoids the overhead of runtime polymorphism. The use of templates is the main technique to achieve static polymorphism in C++.

Example:
```
#include <iostream>

// Template function to print any type
template<typename T>
void print(const T& value) {
    std::cout << "Printing value: " << value << '\n';
}

int main() {
    print(42);           // int
    print(3.14159);      // double
    print("Hello");      // const char*

    return 0;
}
```

In conclusion, static polymorphism achieves polymorphic behavior during compile time using function overloading and templates, instead of relying on runtime information like dynamic polymorphism does. This can result in more efficient code since method calls are resolved at compile time.

#### 5. **Lambda fun**:

* Create a lambda to randomly give a **tip**, e.g., from a `vector<string>` like:

  * "Use with caution!"
  * "Perfect for stealth missions."
  * "Don't mix this with milk."

A lambda function, or simply "lambda", is an anonymous (unnamed) function that is defined in place, within your source code, and with a concise syntax. Lambda functions were introduced in C++11 and have since become a widely used feature, especially in combination with the Standard Library algorithms.

Syntax
Here is a basic syntax of a lambda function in C++:
```
[capture-list](parameters) -> return_type {
    // function body
};
```
- **capture-list**: A list of variables from the surrounding scope that the lambda function can access.
- **parameters**: The list of input parameters, just like in a regular function. Optional.
- **return_type**: The type of the value that the lambda function will return. This part is optional, and the compiler can deduce it in many cases.
- **function body**: The code that defines the operation of the lambda function.
Usage Examples
Here are a few examples to demonstrate the use of lambda functions in C++:

Lambda function with no capture, parameters, or return type.
```
auto printHello = []() {
    std::cout << "Hello, World!\n";
};
printHello(); // Output: Hello, World!
```
Lambda function with parameters.
```
auto add = [](int a, int b) {
    return a + b;
};
int result = add(3, 4); // result = 7
```
Lambda function with capture-by-value.
```
int multiplier = 3;
auto times = [multiplier](int a) {
    return a * multiplier;
};
int result = times(5); // result = 15
```
Lambda function with capture-by-reference.
```
int expiresInDays = 45;
auto updateDays = [&expiresInDays](int newDays) {
    expiresInDays = newDays;
};
updateDays(30); // expiresInDays = 30
```
Note that, when using the capture by reference, any change made to the captured variable inside the lambda function will affect its value in the surrounding scope.

#### 6. Loop until user quits.

---

### 🍄 Optional Ingredient Combos to Support:

| Ingredient 1 | Ingredient 2  | Potion Name         |
| ------------ | ------------- | ------------------- |
| unicorn hair | dragon scale  | Strength Potion     |
| mushroom     | shadow dust   | Invisibility Elixir |
| cheese       | frog leg      | Mystery Goo         |
| fire flower  | snowflake     | Steam Bomb          |
| coffee bean  | lightning bug | Hyper Elixir        |

Unknown combo? Just return **“Oops! You made a Sludge Blob.”**

---

### 💡 Tip:

You don’t need fancy data structures at first. Start with `if-else` combo matching. Then later, you can use `std::map<pair<string, string>, string>` if you’re curious.

---

