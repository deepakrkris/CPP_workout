```cpp
std::vector<int> k {1, 2, 3, 4, 5};
int j = 11;
std::transform(k.begin(),
               k.end(),
               k.begin(),
               [=](int i){ return i+j; })
```
