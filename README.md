# gmock-more-args
This header-only library add gmock functionality for methods with number of arguments from 11 up to 15.

# USING
Syntaxis is exactly the same as in gmock. For example, to mock method ```methodWith11Args``` with 11  ```int``` arguments and ```int``` result you have to write declaration: 
```
...
MOCK_METHOD11(methodWith11Args, int(int, int, int, int, int, int, int, int, int, int, int));
```

