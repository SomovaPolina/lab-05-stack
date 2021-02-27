// Copyright 2020 Your Name <your_email>

#ifndef STACK_HEADER_HPP_
#define STACK_HEADER_HPP_

#include <iostream>

template <typename T>
class Stack
{
 public:
  Stack() : root(nullptr) {}  //по умолчанию пустой стэк
  void push(T&& value)
  {
          Node* newnode = new Node;
          newnode->data = value;
          newnode->next = root;
          root = newnode;
      };

  void push(const T& value)
  {
          Node* newnode = new Node;
          newnode->data = value;
          newnode->next =root;
          root = newnode;
      };

  void pop()
  {
              if (empty())
              {
                throw std::length_error("Stack is empty!");
              }
              Node * delnode = root; //запомнили удаляемый узел
              T value = delnode->data; //запомнили значение, которое хотим вернуть
              root = delnode->next; //вершина сместилась на следующий узел
              delete delnode;
          };

  const T& top() const
  {
          if (empty())
          {
            throw std::length_error("Stack is empty!");
          }
          return root->data;
      };

  bool empty() const
  {
    return root == nullptr;
  }

  ~Stack()
  {
    while (root)
    {
      Node *delnode = root;
      root = delnode->next;
      delete delnode;
    }
  }

  Stack(const Stack& stack) = delete; //конструктор копирования запрещени
  Stack(Stack&& stack) = default; //констурктор перемещения

  Stack &operator=(const Stack& stack) = delete; //перегрузка оператора = констурктора копирования
  Stack &operator=(Stack&& stack) = default; //перегрузка оператора = констурктора перемщения

 private:
  struct Node
  {
   T data; //поле с данными
   Node * next; //указатель на следующий элемент
  };
  Node* root; //вершина стэка
};
#endif // STACK_HEADER_HPP_
