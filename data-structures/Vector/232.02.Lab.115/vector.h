/***********************************************************************
 * Header:
 *    VECTOR
 * Summary:
 *    Our custom implementation of std::vector
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        vector                 : A class that represents a Vector
 *        vector::iterator       : An iterator through Vector
 * Authors
 *    Emilio Regino, Josh Thieme, Jenna Scholl
 ************************************************************************/

#pragma once

#include <cassert>  // because I am paranoid
#include <new>      // std::bad_alloc
#include <memory>   // for std::allocator

class TestVector; // forward declaration for unit tests
class TestStack;
class TestPQueue;
class TestHash;

namespace custom
{

   /*****************************************
    * VECTOR
    * Just like the std :: vector <T> class
    ****************************************/
   template <typename T, typename A = std::allocator<T>>
   class vector
   {
      friend class ::TestVector; // give unit tests access to the privates
      friend class ::TestStack;
      friend class ::TestPQueue;
      friend class ::TestHash;
   public:

      //
      // Construct
      //
      vector(const A& a = A());
      vector(size_t numElements, const A& a = A());
      vector(size_t numElements, const T& t, const A& a = A());
      vector(const std::initializer_list<T>& l, const A& a = A());
      vector(const vector& rhs);
      vector(vector&& rhs);
      ~vector();

      //
      // Assign
      //
      void swap(vector& rhs)
      {
         std::swap(data, rhs.data);
         std::swap(numElements, rhs.numElements);
         std::swap(numCapacity, rhs.numCapacity);
      }
      vector& operator = (const vector& rhs);
      vector& operator = (vector&& rhs);

      //
      // Iterator
      //
      class iterator;
      iterator begin()
      {
         return iterator(data);
      }
      iterator end()
      {
         return iterator(data + numElements);
      }

      //
      // Access
      //
      T& operator [] (size_t index);
      const T& operator [] (size_t index) const;
      T& front();
      const T& front() const;
      T& back();
      const T& back() const;

      //
      // Insert
      //
      void push_back(const T& t);
      void push_back(T&& t);
      void reserve(size_t newCapacity);
      void resize(size_t newElements);
      void resize(size_t newElements, const T& t);

      //
      // Remove
      //
      void clear()
      {
         for (size_t i = 0; i < numElements; i++)
            alloc.destroy(data + i);
         numElements = 0;
      }
      void pop_back()
      {
         if (numElements != 0)
         {
            alloc.destroy(data + (numElements - 1));
            numElements--;
         }
      }
      void shrink_to_fit();

      //
      // Status
      //
      size_t  size()          const { return numElements; }
      size_t  capacity()      const { return numCapacity; }
      bool empty()            const { return size() == 0; }

   private:

      A    alloc;                // use alloacator for memory allocation
      T* data;                 // user data, a dynamically-allocated array
      size_t  numCapacity;       // the capacity of the array
      size_t  numElements;       // the number of items currently used
   };

   /**************************************************
    * VECTOR ITERATOR
    * An iterator through vector.  You only need to
    * support the following:
    *   1. Constructors (default and copy)
    *   2. Not equals operator
    *   3. Increment (prefix and postfix)
    *   4. Dereference
    * This particular iterator is a bi-directional meaning
    * that ++ and -- both work.  Not all iterators are that way.
    *************************************************/
   template <typename T, typename A>
   class vector <T, A> ::iterator
   {
      friend class ::TestVector; // give unit tests access to the privates
      friend class ::TestStack;
      friend class ::TestPQueue;
      friend class ::TestHash;
   public:
      // constructors, destructors, and assignment operator
       iterator() { p = nullptr; }
       iterator(T* p) { this->p = p; }
       iterator(const iterator& rhs) { p = rhs.p; }
       iterator(size_t index, vector<T>& v) { p = &(v.data[index]); }
      iterator& operator = (const iterator& rhs)
      {
         return p = rhs.p;
      }

      // equals, not equals operator
      bool operator != (const iterator& rhs) const { return p != rhs.p; }
      bool operator == (const iterator& rhs) const { return p == rhs.p; }

      // dereference operator
      T& operator * ()
      {
         return *p;
      }

      // prefix increment
      iterator& operator ++ ()
      {
         ++p;
         return *this;
      }

      // postfix increment
      iterator operator ++ (int postfix)
      {
         return p++;
      }

      // prefix decrement
      iterator& operator -- ()
      {
         --p;
         return *this;
      }

      // postfix decrement
      iterator operator -- (int postfix)
      {
         return p++;
      }

   private:
      T* p;
   };


   /*****************************************
    * VECTOR :: NON-DEFAULT constructors
    * non-default constructor: set the number of elements,
    * construct each element, and copy the values over
    ****************************************/
   template <typename T, typename A>
   vector <T, A> ::vector(const A& a)
   {
      data = nullptr;
      numElements = 0;
      numCapacity = 0;
   }


   /*****************************************
    * VECTOR :: NON-DEFAULT constructors
    * non-default constructor: set the number of elements,
    * construct each element, and copy the values over
    ****************************************/
   template <typename T, typename A>
   vector <T, A> ::vector(size_t num, const T& t, const A& a)
   {
      data = alloc.allocate(num);
      numElements = num;
      numCapacity = num;

      for (size_t i = 0; i < numElements; i++)
         alloc.construct(data + i, t);
   }

   /*****************************************
    * VECTOR :: INITIALIZATION LIST constructors
    * Create a vector with an initialization list.
    ****************************************/
   template <typename T, typename A>
   vector <T, A> ::vector(const std::initializer_list<T>& l, const A& a)
   {
      data = alloc.allocate(l.size());
      numElements = l.size();
      numCapacity = l.size();

      for (size_t i = 0; i < l.size(); i++)
         alloc.construct(data + i, *(l.begin() + i));
   }

   /*****************************************
    * VECTOR :: NON-DEFAULT constructors
    * non-default constructor: set the number of elements,
    * construct each element, and copy the values over
    ****************************************/
   template <typename T, typename A>
   vector <T, A> ::vector(size_t num, const A& a)
   {
      // don't need to allocate if num is 0
      if (num != 0)
         data = alloc.allocate(num);
      else
         data = nullptr;
      numElements = num;
      numCapacity = num;

      for (size_t i = 0; i < numElements; i++)
         alloc.construct(data + i);
   }

   /*****************************************
    * VECTOR :: COPY CONSTRUCTOR
    * Allocate the space for numElements and
    * call the copy constructor on each element
    ****************************************/
   template <typename T, typename A>
   vector <T, A> ::vector(const vector& rhs)
   {
      if (!rhs.empty())
      {
         data = alloc.allocate(rhs.numElements);
         numElements = rhs.numElements;
         numCapacity = rhs.numElements;

         for (size_t i = 0; i < numElements; i++)
            alloc.construct(data + i, rhs.data[i]);
      }
      else
      {
         data = nullptr;
         numElements = 0;
         numCapacity = 0;
      }
   }

   /*****************************************
    * VECTOR :: MOVE CONSTRUCTOR
    * Steal the values from the RHS and set it to zero.
    ****************************************/
   template <typename T, typename A>
   vector <T, A> ::vector(vector&& rhs)
   {
      data = rhs.data;
      rhs.data = nullptr;

      numElements = rhs.numElements;
      rhs.numElements = 0;

      numCapacity = rhs.numCapacity;
      rhs.numCapacity = 0;
   }

   /*****************************************
    * VECTOR :: DESTRUCTOR
    * Call the destructor for each element from 0..numElements
    * and then free the memory
    ****************************************/
   template <typename T, typename A>
   vector <T, A> :: ~vector()
   {
      for (size_t i = 0; i < numElements; i++)
         alloc.destroy(data + i);
      alloc.deallocate(data, numCapacity);
   }

   /***************************************
    * VECTOR :: RESIZE
    * This method will adjust the size to newElements.
    * This will either grow or shrink newElements.
    *     INPUT  : newCapacity the size of the new buffer
    *     OUTPUT :
    **************************************/
   template <typename T, typename A>
   void vector <T, A> ::resize(size_t newElements)
   {
       if (newElements < numElements)
           for (size_t i = newElements; i < numElements; i++)
               alloc.destroy(data + i);
       else if (newElements > numElements)
       {
           if (newElements > numCapacity)
               reserve(newElements);
           for (size_t i = numElements; i < newElements; i++)
               alloc.construct(data + i);
       }
       numElements = newElements;
   }

   template <typename T, typename A>
   void vector <T, A> ::resize(size_t newElements, const T& t)
   {
       if (newElements < numElements)
           for (size_t i = newElements; i < numElements; i++)
           {
               alloc.destroy(&data[i]);
           } 
       else if (newElements > numElements)
       {
           if (newElements > numCapacity)
               reserve(newElements);
           for (size_t i = numElements; i < newElements; i++)
               new (&data[i]) T(std::move(t));
       }
       numElements = newElements;
   }

   /***************************************
    * VECTOR :: RESERVE
    * This method will grow the current buffer
    * to newCapacity.  It will also copy all
    * the data from the old buffer into the new
    *     INPUT  : newCapacity the size of the new buffer
    *     OUTPUT :
    **************************************/
   template <typename T, typename A>
   void vector <T, A> ::reserve(size_t newCapacity)
   {
      if (newCapacity <= numCapacity)
         return;

      auto dataNew = alloc.allocate(newCapacity);

      for (size_t i = 0; i < numElements; i++)
         new ((void*)(dataNew + i)) T(std::move(data[i]));

      for (size_t i = 0; i < numElements; i++)
         alloc.destroy(data + i);
      alloc.deallocate(data, numCapacity);

      data = dataNew;
      numCapacity = newCapacity;
   }

   /***************************************
    * VECTOR :: SHRINK TO FIT
    * Get rid of any extra capacity
    *     INPUT  :
    *     OUTPUT :
    **************************************/
   template <typename T, typename A>
   void vector <T, A> ::shrink_to_fit()
   {
      if (numElements == numCapacity)
         return;
      
      if (numElements == 0)
         data = nullptr;
      else
      {
         auto dataNew = alloc.allocate(numElements);
         
         for (size_t i = 0; i < numElements; i++)
            new ((void*)(dataNew + i)) T(data[i]);
         
         for (size_t i = 0; i < numElements; i++)
            alloc.destroy(data + i);
         alloc.deallocate(data, numCapacity);
         
         data = dataNew;
      }
      numCapacity = numElements;
      return;
   }

   /*****************************************
    * VECTOR :: SUBSCRIPT
    * Read-Write access
    ****************************************/
   template <typename T, typename A>
   T& vector <T, A> :: operator [] (size_t index)
   {
      assert(index >= 0 && index < numElements);
      return data[index];
   }

   /******************************************
    * VECTOR :: SUBSCRIPT
    * Read-Write access
    *****************************************/
   template <typename T, typename A>
   const T& vector <T, A> :: operator [] (size_t index) const
   {
      assert(index >= 0 && index < numElements);
      return data[index];
   }

   /*****************************************
    * VECTOR :: FRONT
    * Read-Write access
    ****************************************/
   template <typename T, typename A>
   T& vector <T, A> ::front()
   {
      return data[0];
   }

   /******************************************
    * VECTOR :: FRONT
    * Read-Write access
    *****************************************/
   template <typename T, typename A>
   const T& vector <T, A> ::front() const
   {
      return data[0];
   }

   /*****************************************
    * VECTOR :: FRONT
    * Read-Write access
    ****************************************/
   template <typename T, typename A>
   T& vector <T, A> ::back()
   {
      return data[size() - 1];
   }

   /******************************************
    * VECTOR :: FRONT
    * Read-Write access
    *****************************************/
   template <typename T, typename A>
   const T& vector <T, A> ::back() const
   {
      return data[size() - 1];
   }

   /***************************************
    * VECTOR :: PUSH BACK
    * This method will add the element 't' to the
    * end of the current buffer.  It will also grow
    * the buffer as needed to accomodate the new element
    *     INPUT  : 't' the new element to be added
    *     OUTPUT : *this
    **************************************/
   template <typename T, typename A>
   void vector <T, A> ::push_back(const T& t)
   {
      if (0 == capacity())
         reserve(1);
      if (size() == capacity())
         reserve(capacity() * 2);
      new ((void *)(data + numElements++)) T(t);
   }

   template <typename T, typename A>
   void vector <T, A> ::push_back(T&& t)
   {
      if (0 == capacity())
         reserve(1);
      if (size() == capacity())
         reserve(capacity() * 2);
      new ((void *)(data + numElements++)) T(std::move(t));
   }

   /***************************************
    * VECTOR :: ASSIGNMENT
    * This operator will copy the contents of the
    * rhs onto *this, growing the buffer as needed
    *     INPUT  : rhs the vector to copy from
    *     OUTPUT : *this
    **************************************/
   template <typename T, typename A>
   vector <T, A>& vector <T, A> :: operator = (const vector& rhs)
   {
      // same size
      if (rhs.size() == size())
      {
         for (size_t i = 0; i < size(); i++)
            data[i] = rhs.data[i];
      }
      
      // rhs is bigger
      else if (rhs.size() > size())
      {
         // don't need to allocate
         if (rhs.size() <= capacity())
         {
            for (size_t i = 0; i < size(); i++)
               data[i] = rhs.data[i];
            for (size_t i = size(); i < rhs.size(); i++)
               alloc.construct(data + i, rhs.data[i]);
         }
         
         // need to allocate
         else
         {
            auto dataNew = alloc.allocate(rhs.size());

            for (size_t i = 0; i < rhs.size(); i++)
               alloc.construct(dataNew + i, rhs.data[i]);
            clear();
            alloc.deallocate(data, size());
            data = dataNew;
            numCapacity = rhs.size();
         }
      }
      
      // lhs is bigger
      else
      {
         for (size_t i = 0; i < rhs.size(); i++)
            data[i] = rhs.data[i];
         for (size_t i = rhs.size(); i < size(); i++)
            alloc.destroy(data + i);
      }

      numElements = rhs.size();
      return *this;
   }
   template <typename T, typename A>
   vector <T, A>& vector <T, A> :: operator = (vector&& rhs)
   {
      clear();
      shrink_to_fit();
      swap(rhs);
      return *this;
   }


} // namespace custom

