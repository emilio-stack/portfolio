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
