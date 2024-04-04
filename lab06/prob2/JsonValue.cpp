#include "JsonValue.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

void NullValue::print(std::ostream& out) const {
    out << "null";
}

void NumberValue::print(std::ostream& out) const {
    out << value;
}

void BoolValue::print(std::ostream& out) const {
    if (value) {
        out << "true";
    }
    else {
        out << "false";
    }
}

void StringValue::print(std::ostream& out) const {
    out << "\"" << value << "\"";
}

ArrayValue::~ArrayValue() {
    for (auto* value : values) {
        delete value;
    }
}

void ArrayValue::add(JsonValue* value) {
    //std::cout << "Numere add la vector: \n";
    values.push_back(value); 
}

void ArrayValue::print(std::ostream& out) const {
    //[5, 10, 17]
    out << '[';
    for (size_t i = 0; i < values.size(); ++i) {
        values[i]->print(out);
        if (i < values.size() - 1) out << ", ";
    }
    out << ']';
}

ObjectValue::~ObjectValue() {
    for (auto& pair : values) {
        delete pair.second;
    }
}
void ObjectValue::print(std::ostream& out) const {
    //{"da", "nu"}
    out << '{';
    for (size_t i = 0; i < values.size(); ++i) {
        out << "\"" << values[i].first << "\": ";
        values[i].second->print(out);
        if (i < values.size() - 1) out << ", ";
    }
    out << '}';
}


void ObjectValue::add(const std::string& name, JsonValue* value) {
    values.push_back(std::make_pair(name, value));
}
