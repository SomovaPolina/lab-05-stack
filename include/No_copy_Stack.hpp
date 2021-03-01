//
// Created by polinka on 27.02.2021.
//

#ifndef NO_COPY_STACK_HPP
#define NO_COPY_STACK_HPP

#include <iostream>

template <typename T>
class No_copy_Stack
{
 public:
  No_copy_Stack() : root(nullptr) {};

  template <typename ... Args>

  void push_emplace(Args&&... value)
  {
    root = new Node {{std::forward<Args>(value)...},root};//форвард возвращает ссылку рвалью на аргумент если аргумент не является сслыкой лвалью
  } //добавляет новый элемент на вершину стека, создается он вместо передачи аргс в качестве аргументов для его констурктора

  void push(T&& value)
  {
    root = new Node {std::forward<T>(value),root};
  };

  const T& head() const
  {
    if(!root) throw std::runtime_error("Stack is empty!");
    return root->data;
  };

  T pop()
  {
    if(!root) throw std::runtime_error("Stack is empty!");
    Node * delnode = root; //запомнили удаляемый узел
    T data = std::move(root->data); //запомнили значение, которое хотим вернуть
    root = delnode->next; //вершина сместилась на следующий узел
    delete delnode;
    return data;
  };

  ~No_copy_Stack()
  {
    while(root)
    {
      Node *delnode = root;
      root = delnode->next;
      delete delnode;
    }
  };

  private:
  struct Node
  {
    T data; //поле с данными
    Node * next; //указатель на следующий элемент
  };
  Node* root; //вершина стэка
};


#endif  // NO_COPY_STACK_HPP
