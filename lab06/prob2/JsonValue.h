#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>  
//#include <utility> // std::pair


class JsonValue {
public:
    virtual ~JsonValue() {}
    virtual void print(std::ostream& out) const = 0;
};

class NullValue : public JsonValue {
public:
    void print(std::ostream& out) const ;
};

class NumberValue : public JsonValue {
    double value;
public:
     NumberValue(double value) : value(value) {}
    void print(std::ostream& out) const ;
};

class BoolValue : public JsonValue {
    bool value;
public:
     BoolValue(bool value) : value(value) {}
    void print(std::ostream& out) const ;
};

class StringValue : public JsonValue {
    std::string value;
public:
     StringValue(const std::string& value) : value(value) {}
    void print(std::ostream& out) const ;
};

//ArrayValue: stores an array of values(max 16); 
//the add function will take a value pointerand add it to the array

class ArrayValue : public JsonValue {
    std::vector<JsonValue*> values; 
public:
    ~ArrayValue(); 
    void add(JsonValue* value);
    void print(std::ostream& out) const ;
};

//ObjectValue: stores an array of pairs of(name, value) (max 16); 
// the add function will take a string for name and a
// pointer for the value and add it. 
// Also add a cast operator to unsigned that returns the number of nodes.

class ObjectValue : public JsonValue {
    std::vector<std::pair<std::string, JsonValue*>> values; // Pointeri simpli
public:
    ~ObjectValue(); // Destructor pentru eliberarea memoriei
    void add(const std::string& name, JsonValue* value);
    void print(std::ostream& out) const ;
    operator unsigned() const { return static_cast<unsigned>(values.size()); }
};

