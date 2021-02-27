//
// Created by polinka on 27.02.2021.
//

#ifndef TEMPLATE_NO_COPY_STACK_HPP
#define TEMPLATE_NO_COPY_STACK_HPP

#include <iostream>

template <typename T>
class No_copy_Stack
{
 public:
  No_copy_Stack() : root(nullptr) {};

  template <typename ... Args>

  void push_emplace(Args&&... value)
  {
    root = new node {{std::forward<Args>(value)...},root};//форвард возвращает ссылку рвалью на аргумент если аргумент не является сслыкой лвалью
  }; //добавляет новый элемент на вершину стека, создается он вместо передачи аргс в качестве аргументов для его констурктора

  void push(T&& value)
  {
    root = new node {std::forward<T>(value),root};
  };

  const T& top() const
  {
    if(!root) throw std::length_error("Stack is empty!");
    return root->data;
  };

  T pop()
  {
    if(!root) throw std::length_error("Stack is empty!");
    Node * delnode = root; //запомнили удаляемый узел
    T value = delnode->data; //запомнили значение, которое хотим вернуть
    root = delnode->next; //вершина сместилась на следующий узел
    delete delnode;
    return value;
  };

  ~No_copy_Stack()
  {
    while(root)
    {
      node *delnode = root;
      root = delnode->next;
      delete delnode;
    }
  };

 private:
  Node *root; //вершина стэка
};


#endif  // TEMPLATE_NO_COPY_STACK_HPP
